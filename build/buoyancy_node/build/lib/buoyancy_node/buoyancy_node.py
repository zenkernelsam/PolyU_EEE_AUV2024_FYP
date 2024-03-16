import rclpy
from rclpy.node import Node
from control_interfaces.srv import BuoyancyControl
from control_interfaces.msg import AUVBuoyancy
import serial
import mpu6050
import time
import RPi.GPIO as GPIO
from .submodules.bar30Pix import pixhawk

#Wai's library used
import serial

mpu6050 = mpu6050.mpu6050(0x68)

def read_sensor_data():
    # Read the accelerometer values
    accelerometer_data = mpu6050.get_accel_data()

    # Read the gyroscope values
    gyroscope_data = mpu6050.get_gyro_data()

    # Read temp
    temperature = mpu6050.get_temp()
    return accelerometer_data, gyroscope_data, temperature
#def print_with_time(message):

###START OF ROS2 BUOYANCY NODE CLASS###
class BuoyancyNode(Node):
    def __init__(self):
        super().__init__('buoyancy_node')
        self.publisher_ = self.create_publisher(AUVBuoyancy, 'current_depth', 10)
        self.timer = self.create_timer(0.2, self.timer_callback)  # Timer callback every 0.2 second
        self.srv = self.create_service(BuoyancyControl, 'change_depth', self.get_buoyancy_callback) #Create a Server (service) to listen Master Node's request
        #Task node: flare_detect, gate_detect, drum_detect
        '''
        Remember to write your task name below (self.task_name) for better identification
        '''

        self.setpoint = 0.4
        self.get_depth = 0

        self.modify_depth = None
        self.is_succeeded = None

    def timer_callback(self):
        
        msg = AUVBuoyancy()
        msg.now_depth = float(self.get_depth)
        self.publisher_.publish(msg)
        self.get_logger().info(f'Buoyancy depth: {msg.now_depth}')   
    

    def get_buoyancy_callback(self, request_from_control_node, response_from_buoyancy):
        #print("get_task_callback is called")
        #self.get_logger().info(f"Get request.get_command: {request.get_task}") #Debug
        if request_from_control_node.modify_depth == True:
            print("[O] Received Request from Control Node [control_node]")
            self.setpoint = round(request_from_control_node.new_depth, 3)
            self.is_succeeded = True
            response_from_buoyancy.is_succeeded = self.is_succeeded
            response_from_buoyancy.now_depth = round(float(self.get_depth),3)
            self.get_logger().info(f"[O] New Setpoint: {self.setpoint}")
            self.get_logger().info(f"[O] Buoyancy Node has responded back to Control Node.")
        return response_from_buoyancy
    


def main(args=None):
    previous_depth = 0
    count = 0
    sum_depth = 0.0
    speed_limit = 0.017
    speed = 0 
    deceleration_range = 0.08
    speed_cons = 0.01
    pwm1 = 100
    pwm2 = 50
    enA = 10
    MOTORL_PIN1 = 9
    MOTORL_PIN2 = 11
    enB = 17
    MOTORR_PIN1 = 22
    MOTORR_PIN2 = 27
    accelaration = 0
    accelaration_1cons = 0.01667
    accelaration_2cons = 0.03
    time_2cons = 0
    speep_cons = 0.03
    depth_value = 0
    # Constants for PID control
    Kp = 50      # Proportional gain
    Ki = 0.001       # Integral gain
    Kd = 0.001      # Derivative gain
    depth_offset = -0.1
    # Variables for PID control
    integral = 0.0
    pervious_speed = 0
    previous_error = 0.0
    xpitch_offset = -0.55
    ypitch_offset = +0.1
    #pre_p_depth_value = setpoint + deceleration_range
    #pre_n_depth_value = setpoint - deceleration_range 
    serial_port = None
    for port in serial.tools.list_ports.comports():
        if "usb" in port.name or "ACM" in port.name:
            serial_port = port.device
            print("using port : ",serial_port)
    print(serial_port)
    # serial_port = '/dev/ttyUSB0' 
    baud_rate = 115200
    # Create a serial object
    # ser = serial.Serial(serial_port, baud_rate)
    pix = pixhawk(serial_port)
    GPIO.setmode(GPIO.BCM)
    GPIO.setwarnings(False)
    GPIO.setup(enA, GPIO.OUT)
    GPIO.setup(MOTORL_PIN1, GPIO.OUT)
    GPIO.setup(MOTORL_PIN2, GPIO.OUT)
    GPIO.setup(enB, GPIO.OUT)
    GPIO.setup(MOTORR_PIN1, GPIO.OUT)
    GPIO.setup(MOTORR_PIN2, GPIO.OUT)
    pwmA = GPIO.PWM(enA, 99)  # Frequency = 100Hz
    pwmB = GPIO.PWM(enB, 99)  # Frequency = 100Hz
    # Start PWM
    pwmA.start(0)  # Start with 0% duty cycle (stopped)
    pwmB.start(0)  # Start with 0% duty cycle (stopped)
    rclpy.init(args=args)
    buoyancy_node = BuoyancyNode()
    #input = sys.argv[1:]
    #rclpy.spin(buoyancy_node)
    #Start read MPU6050
    #mpu6050 = mpu6050.mpu6050(0x68)

    try:
        while rclpy.ok():
            rclpy.spin_once(buoyancy_node)
            #buoyancy_node.is_succeeded = False

            accelerometer_data, gyroscope_data, temperature = read_sensor_data()

            # Extract x and y values from accelerometer data
            x = accelerometer_data['x'] + xpitch_offset
            y = accelerometer_data['y'] + ypitch_offset

            # Print the x and y values
            # print("x:", x)
            #s = time.perf_counter()
            #data = ser.readline().decode().strip()
            
            buoyancy_node.get_depth = (pix.getData() * -1) + depth_offset
            if buoyancy_node.get_depth is not None:

                count += 1
                sum_depth += buoyancy_node.get_depth
                if count == 3:
                    depth_value = sum_depth / 4
                    count = 0
                    sum_depth = 0.0
                    speed = (depth_value - previous_depth)/0.15
                    accelaration = (speed-pervious_speed)/0.15
                    pervious_speed = speed
                    previous_depth = depth_value
                #deceleration_range = deceleration_range/1.01
                # Error calculation
                error = buoyancy_node.setpoint - (depth_value)
                # Proportional term
                proportional = Kp * error
                # Integral term
                integral += Ki * error
                # Derivative term
                derivative = Kd * (error - previous_error)
                previous_error = error
                # PID control output
                PIDcontrol_output = proportional + integral + derivative

                #print("previous_depth", previous_depth)
                print(f"Depth: {depth_value}, Pitch: {y}")
                print("Control output:",PIDcontrol_output)
                print("speed", speed,"accelaration:",accelaration)
                stage = 1
                #print("decelerate range:", deceleration_range)
                #print("x",abs(setpoint - depth_value))
            #if pre_n_depth_value < setpoint < depth_value or pre_p_depth_value > setpoint > depth_value:
                #if deceleration_range > 0.02:
                #deceleration_range /= 2  # Halve the deceleration range
            if abs(buoyancy_node.setpoint - depth_value) < deceleration_range:  # Reverse motors
                #if PIDcontrol_output < 0:  # floating
                if (speed) < 0 :#uping
                    if (abs(speed) > accelaration_2cons) : #up
                        GPIO.output(MOTORL_PIN1, GPIO.HIGH)   # water in
                        GPIO.output(MOTORL_PIN2, GPIO.LOW)   # water in
                        GPIO.output(MOTORR_PIN1, GPIO.HIGH)  # water in
                        GPIO.output(MOTORR_PIN2, GPIO.LOW)  # water out
                        pwmA.ChangeDutyCycle(100)
                        pwmB.ChangeDutyCycle(70)
                        print("deceleration_up_down1.1_up") 
                    elif (accelaration_1cons < abs(speed) < accelaration_2cons):
                        GPIO.output(MOTORL_PIN1, GPIO.LOW)   # water out
                        GPIO.output(MOTORL_PIN2, GPIO.HIGH)   # water out
                        GPIO.output(MOTORR_PIN1, GPIO.LOW)  # water out
                        GPIO.output(MOTORR_PIN2, GPIO.HIGH)   # water out
                        pwmA.ChangeDutyCycle(100)
                        pwmB.ChangeDutyCycle(70)
                        print("deceleration_up_down1.2_stop") 
                    elif (accelaration_1cons > abs(speed) ):    
                        GPIO.output(MOTORL_PIN1, GPIO.HIGH)   # water in
                        GPIO.output(MOTORL_PIN2, GPIO.LOW)   # water in
                        GPIO.output(MOTORR_PIN1, GPIO.HIGH)  # water in
                        GPIO.output(MOTORR_PIN2, GPIO.LOW)  # water out
                        pwmA.ChangeDutyCycle(80)
                        pwmB.ChangeDutyCycle(50)
                        print("deceleration_up_down1.3_stop")     
                elif (speed) > 0:
                    if (abs(accelaration) > accelaration_2cons) : #up
                        GPIO.output(MOTORL_PIN1, GPIO.LOW)   # water out
                        GPIO.output(MOTORL_PIN2, GPIO.HIGH)   # water out
                        GPIO.output(MOTORR_PIN1, GPIO.LOW)  # water out
                        GPIO.output(MOTORR_PIN2, GPIO.HIGH)   # water out
                        pwmA.ChangeDutyCycle(100)
                        pwmB.ChangeDutyCycle(70)
                        print("deceleration_up_down2.1_up") 
                    elif (accelaration_1cons < abs(accelaration) < accelaration_2cons):
                        GPIO.output(MOTORL_PIN1, GPIO.HIGH)   # water in
                        GPIO.output(MOTORL_PIN2, GPIO.LOW)   # water in
                        GPIO.output(MOTORR_PIN1, GPIO.HIGH)  # water in
                        GPIO.output(MOTORR_PIN2, GPIO.LOW)
                        print("deceleration_up_down2.2_stop") 
                        pwmA.ChangeDutyCycle(100)
                        pwmB.ChangeDutyCycle(70)
                    elif (accelaration_1cons > abs(accelaration) ):    
                        GPIO.output(MOTORL_PIN1, GPIO.LOW)   # water out
                        GPIO.output(MOTORL_PIN2, GPIO.HIGH)   # water out
                        GPIO.output(MOTORR_PIN1, GPIO.LOW)  # water out
                        GPIO.output(MOTORR_PIN2, GPIO.HIGH)  
                        pwmA.ChangeDutyCycle(80)
                        pwmB.ChangeDutyCycle(50)
                        print("deceleration_up_down2.3_stop")   
                else: # acc =0 
                    GPIO.output(MOTORL_PIN1, GPIO.LOW)
                    GPIO.output(MOTORL_PIN2, GPIO.LOW)
                    GPIO.output(MOTORR_PIN1, GPIO.LOW)
                    GPIO.output(MOTORR_PIN2, GPIO.LOW)
                    pwmA.ChangeDutyCycle(100)
                    pwmB.ChangeDutyCycle(65)
                    #print("stop4")
            elif speed > speed_limit:  # If speed exceeds limit, float
                GPIO.output(MOTORL_PIN1, GPIO.LOW) # water out
                GPIO.output(MOTORL_PIN2, GPIO.HIGH)
                GPIO.output(MOTORR_PIN1, GPIO.LOW) # water out
                GPIO.output(MOTORR_PIN2, GPIO.HIGH)
                pwmA.ChangeDutyCycle(100)
                pwmB.ChangeDutyCycle(70)
                print("over speed stop1")
            elif speed < -speed_limit:
                GPIO.output(MOTORL_PIN1, GPIO.HIGH) # water in
                GPIO.output(MOTORL_PIN2, GPIO.LOW)
                GPIO.output(MOTORR_PIN1, GPIO.HIGH) # water in
                GPIO.output(MOTORR_PIN2, GPIO.LOW)
                pwmA.ChangeDutyCycle(100)
                pwmB.ChangeDutyCycle(70)
                print("over speed stop2")
            else:
                if y > 0.3:  # left
                    if PIDcontrol_output > 0:  # need sink
                        GPIO.output(MOTORL_PIN1, GPIO.LOW)   # water out
                        GPIO.output(MOTORL_PIN2, GPIO.HIGH)   # water out
                        GPIO.output(MOTORR_PIN1, GPIO.HIGH)  # water in
                        GPIO.output(MOTORR_PIN2, GPIO.LOW)   # water in
                        pwmA.ChangeDutyCycle(100)
                        pwmB.ChangeDutyCycle(65)
                        print("stop5_balance")
                        stage = 0
                    elif PIDcontrol_output < 0:  # need float
                        GPIO.output(MOTORL_PIN1, GPIO.LOW)   # water out
                        GPIO.output(MOTORL_PIN2, GPIO.HIGH)  # water out
                        GPIO.output(MOTORR_PIN1, GPIO.HIGH)   # water in
                        GPIO.output(MOTORR_PIN2, GPIO.LOW)   # water in
                        pwmA.ChangeDutyCycle(100)
                        pwmB.ChangeDutyCycle(65)
                        print("L out, R stop6_balance")
                        stage = 1
                    else:
                        GPIO.output(MOTORL_PIN1, GPIO.LOW)
                        GPIO.output(MOTORL_PIN2, GPIO.LOW)
                        GPIO.output(MOTORR_PIN1, GPIO.LOW)
                        GPIO.output(MOTORR_PIN2, GPIO.LOW)
                        pwmA.ChangeDutyCycle(100)
                        pwmB.ChangeDutyCycle(65)
                        print("stop7")
                elif y < -0.3:  # right
                    if PIDcontrol_output > 0:  # need sink
                        GPIO.output(MOTORL_PIN1, GPIO.HIGH)  # water in
                        GPIO.output(MOTORL_PIN2, GPIO.LOW)   # water in
                        GPIO.output(MOTORR_PIN1, GPIO.HIGH)   # water in
                        GPIO.output(MOTORR_PIN2, GPIO.LOW)   # water in
                        pwmA.ChangeDutyCycle(100)
                        pwmB.ChangeDutyCycle(50)
                        print("L in, R stop8")
                        stage = 0
                    elif PIDcontrol_output < 0:  # need float
                        GPIO.output(MOTORL_PIN1, GPIO.HIGH)   # water in
                        GPIO.output(MOTORL_PIN2, GPIO.LOW)   # water in
                        GPIO.output(MOTORR_PIN1, GPIO.LOW)   # water out
                        GPIO.output(MOTORR_PIN2, GPIO.HIGH)  # water out
                        pwmA.ChangeDutyCycle(100)
                        pwmB.ChangeDutyCycle(65)
                        print("L stop, R out9")
                        stage = 1
                else:
                    GPIO.output(MOTORL_PIN1, GPIO.LOW)
                    GPIO.output(MOTORL_PIN2, GPIO.LOW)
                    GPIO.output(MOTORR_PIN1, GPIO.LOW)
                    GPIO.output(MOTORR_PIN2, GPIO.LOW)
                    pwmA.ChangeDutyCycle(100)
                    pwmB.ChangeDutyCycle(65)
                    print("stop10")
                if ((PIDcontrol_output > 0) and (speed==0) and (abs(accelaration)<accelaration_2cons)):  # need sink
                    GPIO.output(MOTORL_PIN1, GPIO.HIGH)  # water in
                    GPIO.output(MOTORL_PIN2, GPIO.LOW)   # water in
                    GPIO.output(MOTORR_PIN1, GPIO.HIGH)  # water in
                    GPIO.output(MOTORR_PIN2, GPIO.LOW)   # water in
                    pwmA.ChangeDutyCycle(100)
                    pwmB.ChangeDutyCycle(80)
                    print("L in, R in11")
                    stage = 0
                elif (PIDcontrol_output < 0 and speed == 0 and abs(accelaration)<accelaration_2cons):  # need float
                    GPIO.output(MOTORL_PIN1, GPIO.LOW) # water out
                    GPIO.output(MOTORL_PIN2, GPIO.HIGH)
                    GPIO.output(MOTORR_PIN1, GPIO.LOW)# water out
                    GPIO.output(MOTORR_PIN2, GPIO.HIGH)
                    pwmA.ChangeDutyCycle(100)
                    pwmB.ChangeDutyCycle(65)
                    print("L out, R out12")
                    stage = 1 
                else:
                    GPIO.output(MOTORL_PIN1, GPIO.LOW)
                    GPIO.output(MOTORL_PIN2, GPIO.LOW)
                    GPIO.output(MOTORR_PIN1, GPIO.LOW)
                    GPIO.output(MOTORR_PIN2, GPIO.LOW)
                    pwmA.ChangeDutyCycle(80)
                    pwmB.ChangeDutyCycle(50)
                    print("stop13")
            print(f"Current Setpoint: {buoyancy_node.setpoint}, Current now_depth: {round(buoyancy_node.get_depth,3)}")
    except KeyboardInterrupt:
    # Close the serial connection
        pass


    buoyancy_node.destroy_node()
    rclpy.shutdown()