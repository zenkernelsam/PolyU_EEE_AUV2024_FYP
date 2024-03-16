#FYP AUV Master Node Designed by Cisco HE
#20058054d@connect.polyu.hk
#Function: Receiving request from control node to modify the AUV's depth
from .submodules.buoyancy_function import thruster_move, water_pump_period
import rclpy
from rclpy.node import Node
from control_interfaces.srv import BuoyancyControl
import smbus
import time
#from buoyancy_node.buoyancy_function
#import sys
import re

#Wai's library used
import serial
import wiringpi
from wiringpi import GPIO

#Water_pump default frequency 100Hz:
water_pump_hz = 100
water_pump_period = (1/100)*1E9

#import datetime
# Motor A ....connection
previous_depth = 0
count = 0
sum_depth = 0.0
speed_limit = 0.017
speed = 0 
#deceleration_range = 0.08
speed_cons = 0.01
pwm1 = 100
pwm2 = 50
enA = 10
MOTORL_PIN1 = 17 #OP5P Configuration
MOTORL_PIN2 = 19
# Motor B connections
enB = 17
MOTORR_PIN1 = 23
MOTORR_PIN2 = 25
accelaration = 0
accelaration_1cons = 0.01667
accelaration_2cons = 0.03
time_2cons = 0
speep_cons = 0.03
depth_value = 0
get_depth = 0
# Constants for PID control
#setpoint = 0.4  # Desired depth value
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

#MPU6050 Class
class MPU6050:

    # Global Variables
    GRAVITIY_MS2 = 9.80665
    address = None
    bus = smbus.SMBus(2)

    # Scale Modifiers
    ACCEL_SCALE_MODIFIER_2G = 16384.0
    ACCEL_SCALE_MODIFIER_4G = 8192.0
    ACCEL_SCALE_MODIFIER_8G = 4096.0
    ACCEL_SCALE_MODIFIER_16G = 2048.0

    GYRO_SCALE_MODIFIER_250DEG = 131.0
    GYRO_SCALE_MODIFIER_500DEG = 65.5
    GYRO_SCALE_MODIFIER_1000DEG = 32.8
    GYRO_SCALE_MODIFIER_2000DEG = 16.4

    # Pre-defined ranges
    ACCEL_RANGE_2G = 0x00
    ACCEL_RANGE_4G = 0x08
    ACCEL_RANGE_8G = 0x10
    ACCEL_RANGE_16G = 0x18

    GYRO_RANGE_250DEG = 0x00
    GYRO_RANGE_500DEG = 0x08
    GYRO_RANGE_1000DEG = 0x10
    GYRO_RANGE_2000DEG = 0x18

    # MPU-6050 Registers
    PWR_MGMT_1 = 0x6B
    PWR_MGMT_2 = 0x6C

    SELF_TEST_X = 0x0D
    SELF_TEST_Y = 0x0E
    SELF_TEST_Z = 0x0F
    SELF_TEST_A = 0x10

    ACCEL_XOUT0 = 0x3B
    ACCEL_XOUT1 = 0x3C
    ACCEL_YOUT0 = 0x3D
    ACCEL_YOUT1 = 0x3E
    ACCEL_ZOUT0 = 0x3F
    ACCEL_ZOUT1 = 0x40

    TEMP_OUT0 = 0x41
    TEMP_OUT1 = 0x42

    GYRO_XOUT0 = 0x43
    GYRO_XOUT1 = 0x44
    GYRO_YOUT0 = 0x45
    GYRO_YOUT1 = 0x46
    GYRO_ZOUT0 = 0x47
    GYRO_ZOUT1 = 0x48

    ACCEL_CONFIG = 0x1C
    GYRO_CONFIG = 0x1B

    def __init__(self, address):
        self.address = address

        # Wake up the MPU-6050 since it starts in sleep mode
        self.bus.write_byte_data(self.address, self.PWR_MGMT_1, 0x00)

    # I2C communication methods

    def read_i2c_word(self, register):
        """Read two i2c registers and combine them.

        register -- the first register to read from.
        Returns the combined read results.
        """
        # Read the data from the registers
        high = self.bus.read_byte_data(self.address, register)
        low = self.bus.read_byte_data(self.address, register + 1)

        value = (high << 8) + low

        if (value >= 0x8000):
            return -((65535 - value) + 1)
        else:
            return value

    # MPU-6050 Methods

    def get_temp(self):
        """Reads the temperature from the onboard temperature sensor of the MPU-6050.

        Returns the temperature in degrees Celcius.
        """
        # Get the raw data
        raw_temp = self.read_i2c_word(self.TEMP_OUT0)

        # Get the actual temperature using the formule given in the
        # MPU-6050 Register Map and Descriptions revision 4.2, page 30
        actual_temp = (raw_temp / 340) + 36.53

        # Return the temperature
        return actual_temp

    def set_accel_range(self, accel_range):
        """Sets the range of the accelerometer to range.

        accel_range -- the range to set the accelerometer to. Using a
        pre-defined range is advised.
        """
        # First change it to 0x00 to make sure we write the correct value later
        self.bus.write_byte_data(self.address, self.ACCEL_CONFIG, 0x00)

        # Write the new range to the ACCEL_CONFIG register
        self.bus.write_byte_data(self.address, self.ACCEL_CONFIG, accel_range)

    def read_accel_range(self, raw = False):
        """Reads the range the accelerometer is set to.

        If raw is True, it will return the raw value from the ACCEL_CONFIG
        register
        If raw is False, it will return an integer: -1, 2, 4, 8 or 16. When it
        returns -1 something went wrong.
        """
        # Get the raw value
        raw_data = self.bus.read_byte_data(self.address, self.ACCEL_CONFIG)

        if raw is True:
            return raw_data
        elif raw is False:
            if raw_data == self.ACCEL_RANGE_2G:
                return 2
            elif raw_data == self.ACCEL_RANGE_4G:
                return 4
            elif raw_data == self.ACCEL_RANGE_8G:
                return 8
            elif raw_data == self.ACCEL_RANGE_16G:
                return 16
            else:
                return -1

    def get_accel_data(self, g = False):
        """Gets and returns the X, Y and Z values from the accelerometer.

        If g is True, it will return the data in g
        If g is False, it will return the data in m/s^2
        Returns a dictionary with the measurement results.
        """
        # Read the data from the MPU-6050
        x = self.read_i2c_word(self.ACCEL_XOUT0)
        y = self.read_i2c_word(self.ACCEL_YOUT0)
        z = self.read_i2c_word(self.ACCEL_ZOUT0)

        accel_scale_modifier = None
        accel_range = self.read_accel_range(True)

        if accel_range == self.ACCEL_RANGE_2G:
            accel_scale_modifier = self.ACCEL_SCALE_MODIFIER_2G
        elif accel_range == self.ACCEL_RANGE_4G:
            accel_scale_modifier = self.ACCEL_SCALE_MODIFIER_4G
        elif accel_range == self.ACCEL_RANGE_8G:
            accel_scale_modifier = self.ACCEL_SCALE_MODIFIER_8G
        elif accel_range == self.ACCEL_RANGE_16G:
            accel_scale_modifier = self.ACCEL_SCALE_MODIFIER_16G
        else:
            print("Unkown range - accel_scale_modifier set to self.ACCEL_SCALE_MODIFIER_2G")
            accel_scale_modifier = self.ACCEL_SCALE_MODIFIER_2G

        x = x / accel_scale_modifier
        y = y / accel_scale_modifier
        z = z / accel_scale_modifier

        if g is True:
            return {'x': x, 'y': y, 'z': z}
        elif g is False:
            x = x * self.GRAVITIY_MS2
            y = y * self.GRAVITIY_MS2
            z = z * self.GRAVITIY_MS2
            return {'x': x, 'y': y, 'z': z}

    def set_gyro_range(self, gyro_range):
        """Sets the range of the gyroscope to range.

        gyro_range -- the range to set the gyroscope to. Using a pre-defined
        range is advised.
        """
        # First change it to 0x00 to make sure we write the correct value later
        self.bus.write_byte_data(self.address, self.GYRO_CONFIG, 0x00)

        # Write the new range to the ACCEL_CONFIG register
        self.bus.write_byte_data(self.address, self.GYRO_CONFIG, gyro_range)

    def read_gyro_range(self, raw = False):
        """Reads the range the gyroscope is set to.

        If raw is True, it will return the raw value from the GYRO_CONFIG
        register.
        If raw is False, it will return 250, 500, 1000, 2000 or -1. If the
        returned value is equal to -1 something went wrong.
        """
        # Get the raw value
        raw_data = self.bus.read_byte_data(self.address, self.GYRO_CONFIG)

        if raw is True:
            return raw_data
        elif raw is False:
            if raw_data == self.GYRO_RANGE_250DEG:
                return 250
            elif raw_data == self.GYRO_RANGE_500DEG:
                return 500
            elif raw_data == self.GYRO_RANGE_1000DEG:
                return 1000
            elif raw_data == self.GYRO_RANGE_2000DEG:
                return 2000
            else:
                return -1

    def get_gyro_data(self):
        """Gets and returns the X, Y and Z values from the gyroscope.

        Returns the read values in a dictionary.
        """
        # Read the raw data from the MPU-6050
        x = self.read_i2c_word(self.GYRO_XOUT0)
        y = self.read_i2c_word(self.GYRO_YOUT0)
        z = self.read_i2c_word(self.GYRO_ZOUT0)

        gyro_scale_modifier = None
        gyro_range = self.read_gyro_range(True)

        if gyro_range == self.GYRO_RANGE_250DEG:
            gyro_scale_modifier = self.GYRO_SCALE_MODIFIER_250DEG
        elif gyro_range == self.GYRO_RANGE_500DEG:
            gyro_scale_modifier = self.GYRO_SCALE_MODIFIER_500DEG
        elif gyro_range == self.GYRO_RANGE_1000DEG:
            gyro_scale_modifier = self.GYRO_SCALE_MODIFIER_1000DEG
        elif gyro_range == self.GYRO_RANGE_2000DEG:
            gyro_scale_modifier = self.GYRO_SCALE_MODIFIER_2000DEG
        else:
            print("Unkown range - gyro_scale_modifier set to self.GYRO_SCALE_MODIFIER_250DEG")
            gyro_scale_modifier = self.GYRO_SCALE_MODIFIER_250DEG

        x = x / gyro_scale_modifier
        y = y / gyro_scale_modifier
        z = z / gyro_scale_modifier

        return {'x': x, 'y': y, 'z': z}

    def get_all_data(self):
        """Reads and returns all the available data."""
        temp = self.get_temp()
        accel = self.get_accel_data()
        gyro = self.get_gyro_data()

        return [accel, gyro, temp]
    
    #I put Wai's read_sensor_data() inside MPU6050 class directly
    def read_sensor_data(self):
        # Read the accelerometer values
        accelerometer_data = self.get_accel_data()

        # Read the gyroscope values
        gyroscope_data = self.get_gyro_data()

        # Read temp
        temperature = self.get_temp()
        return accelerometer_data, gyroscope_data, temperature
    
def start():
    """
    Initialize the MPU6050, calculate the offset and print the adjusted data.
    """
    mpu = MPU6050(0x68)
    
    # Number of samples to take for calibration
    num_samples = 100
    
    # Initialize sums for calculating average offset
    sum_ax = sum_ay = sum_az = 0
    
    # Take multiple samples to calculate the average offset
    for _ in range(num_samples):
        accel_data = mpu.get_accel_data()
        sum_ax += accel_data['x']
        sum_ay += accel_data['y']
        sum_az += accel_data['z']
    
    # Calculate the average offset
    offset_x = sum_ax / num_samples
    offset_y = sum_ay / num_samples
    offset_z = sum_az / num_samples

    return offset_x, offset_y, offset_z

###END OF MPU6050 CLASS###

###START OF ROS2 BUOYANCY NODE CLASS###
class BuoyancyNode(Node):
    def __init__(self):
        super().__init__('buoyancy_node')
        self.read_sensor = serial.Serial("/dev/ttyUSB0", 115200)
        self.srv = self.create_service(BuoyancyControl, 'change_depth', self.get_buoyancy_callback) #Create a Server (service) to listen Master Node's request
        #Task node: flare_detect, gate_detect, drum_detect
        '''
        Remember to write your task name below (self.task_name) for better identification
        '''

        self.setpoint = 0.4
        self.deceleration_range = 0.08
        self.pre_p_depth_value = self.setpoint + self.deceleration_range
        self.pre_n_depth_value = self.setpoint - self.deceleration_range 

        self.modify_depth = None
        self.is_succeeded = None

        
    

    def get_buoyancy_callback(self, request_from_control_node, response_from_buoyancy):
        #print("get_task_callback is called")
        #self.get_logger().info(f"Get request.get_command: {request.get_task}") #Debug
        if request_from_control_node.modify_depth == True:
            self.setpoint = request_from_control_node.new_depth
            response_from_buoyancy.is_succeeded = self.is_succeeded == True
            response_from_buoyancy.now_depth = self.setpont
            self.get_logger().info(f"[O] New Setpoint: {self.setpoint}")
            self.get_logger().info(f"[O] Buoyancy Node has responded back to Control Node.")
        return response_from_buoyancy
    
    def write_response(self, is_succeeded, now_depth):
        print(f"write_reponse() started")
        self.is_succeeded = is_succeeded == "True"
        self.buoyancy_depth = int(now_depth)



        

def main(args=None):
    rclpy.init(args=args)
    buoyancy_node = BuoyancyNode()
    #input = sys.argv[1:]
    rclpy.spin(buoyancy_node)
    #Start read MPU6050
    mpu6050 = mpu6050.mpu6050(0x68)

    try:
        while rclpy.ok():
            #Start read sensor output
            sensor_output = buoyancy_node.read_sensor.readline().decode('utf-8')
            depth_match = re.search(r'Depth:(-?\d+\.\d+)', sensor_output)
            if depth_match:
                depth_from_TTL = float(depth_match.group(1))
                print(f"Find Depth: {depth_from_TTL}m.")
            else:
                print("Failed to extract depth and temperature data.")
            # Read the sensor data
            accelerometer_data, gyroscope_data, temperature = mpu6050.read_sensor_data()
            # Extract x and y values from accelerometer data
            x = accelerometer_data['x'] + xpitch_offset
            y = accelerometer_data['y'] + ypitch_offset

            #get_depth = (pix.getData() * -1) + depth_offset
            get_depth = depth_from_TTL + depth_offset
            if get_depth is not None:
                count += 1
                sum_depth += get_depth
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
            if abs(buoyancy_node.setpoint - depth_value) < buoyancy_node.deceleration_range:  # Reverse motors
                #if PIDcontrol_output < 0:  # floating
                if (speed) < 0 :#uping
                    if (abs(speed) > accelaration_2cons) : #up
                        wiringpi.digitalWrite(MOTORL_PIN1, GPIO.HIGH)   # water in
                        wiringpi.digitalWrite(MOTORL_PIN2, GPIO.LOW)   # water in
                        wiringpi.digitalWrite(MOTORR_PIN1, GPIO.HIGH)  # water in
                        wiringpi.digitalWrite(MOTORR_PIN2, GPIO.LOW)  # water out
                        #pwmA.ChangeDutyCycle(100)
                        #pwmB.ChangeDutyCycle(70)
                        thruster_move("water_pump1",water_pump_period,100,0)
                        thruster_move("water_pump2",water_pump_period,70,0)
                        print("deceleration_up_down1.1_up") 
                    elif (accelaration_1cons < abs(speed) < accelaration_2cons):
                        wiringpi.digitalWrite(MOTORL_PIN1, GPIO.LOW)   # water out
                        wiringpi.digitalWrite(MOTORL_PIN2, GPIO.HIGH)   # water out
                        wiringpi.digitalWrite(MOTORR_PIN1, GPIO.LOW)  # water out
                        wiringpi.digitalWrite(MOTORR_PIN2, GPIO.HIGH)   # water out
                        #pwmA.ChangeDutyCycle(100)
                        #pwmB.ChangeDutyCycle(70)
                        thruster_move("water_pump1",water_pump_period,100,0)
                        thruster_move("water_pump2",water_pump_period,70,0)                        
                        print("deceleration_up_down1.2_stop") 
                    elif (accelaration_1cons > abs(speed) ):    
                        wiringpi.digitalWrite(MOTORL_PIN1, GPIO.HIGH)   # water in
                        wiringpi.digitalWrite(MOTORL_PIN2, GPIO.LOW)   # water in
                        wiringpi.digitalWrite(MOTORR_PIN1, GPIO.HIGH)  # water in
                        wiringpi.digitalWrite(MOTORR_PIN2, GPIO.LOW)  # water out
                        #pwmA.ChangeDutyCycle(80)
                        #pwmB.ChangeDutyCycle(50)
                        thruster_move("water_pump1",water_pump_period,80,0)
                        thruster_move("water_pump2",water_pump_period,50,0)
                        print("deceleration_up_down1.3_stop")     
                elif (speed) > 0:
                    if (abs(accelaration) > accelaration_2cons) : #up
                        wiringpi.digitalWrite(MOTORL_PIN1, GPIO.LOW)   # water out
                        wiringpi.digitalWrite(MOTORL_PIN2, GPIO.HIGH)   # water out
                        wiringpi.digitalWrite(MOTORR_PIN1, GPIO.LOW)  # water out
                        wiringpi.digitalWrite(MOTORR_PIN2, GPIO.HIGH)   # water out
                        #pwmA.ChangeDutyCycle(100)
                        #pwmB.ChangeDutyCycle(70)
                        thruster_move("water_pump1",water_pump_period,100,0)
                        thruster_move("water_pump2",water_pump_period,70,0)
                        print("deceleration_up_down2.1_up") 
                    elif (accelaration_1cons < abs(accelaration) < accelaration_2cons):
                        wiringpi.digitalWrite(MOTORL_PIN1, GPIO.HIGH)   # water in
                        wiringpi.digitalWrite(MOTORL_PIN2, GPIO.LOW)   # water in
                        wiringpi.digitalWrite(MOTORR_PIN1, GPIO.HIGH)  # water in
                        wiringpi.digitalWrite(MOTORR_PIN2, GPIO.LOW)
                        print("deceleration_up_down2.2_stop") 
                        #pwmA.ChangeDutyCycle(100)
                        #pwmB.ChangeDutyCycle(70)
                        thruster_move("water_pump1",water_pump_period,100,0)
                        thruster_move("water_pump2",water_pump_period,70,0)
                    elif (accelaration_1cons > abs(accelaration) ):    
                        wiringpi.digitalWrite(MOTORL_PIN1, GPIO.LOW)   # water out
                        wiringpi.digitalWrite(MOTORL_PIN2, GPIO.HIGH)   # water out
                        wiringpi.digitalWrite(MOTORR_PIN1, GPIO.LOW)  # water out
                        wiringpi.digitalWrite(MOTORR_PIN2, GPIO.HIGH)  
                        #pwmA.ChangeDutyCycle(80)
                        #pwmB.ChangeDutyCycle(50)
                        thruster_move("water_pump1",water_pump_period,80,0)
                        thruster_move("water_pump2",water_pump_period,50,0)
                        print("deceleration_up_down2.3_stop")   
                else: # acc =0 
                    wiringpi.digitalWrite(MOTORL_PIN1, GPIO.LOW)
                    wiringpi.digitalWrite(MOTORL_PIN2, GPIO.LOW)
                    wiringpi.digitalWrite(MOTORR_PIN1, GPIO.LOW)
                    wiringpi.digitalWrite(MOTORR_PIN2, GPIO.LOW)
                    #pwmA.ChangeDutyCycle(100)
                    #pwmB.ChangeDutyCycle(65)
                    thruster_move("water_pump1",water_pump_period,100,0)
                    thruster_move("water_pump2",water_pump_period,65,0)
                    #print("stop4")
            elif speed > speed_limit:  # If speed exceeds limit, float
                wiringpi.digitalWrite(MOTORL_PIN1, GPIO.LOW) # water out
                wiringpi.digitalWrite(MOTORL_PIN2, GPIO.HIGH)
                wiringpi.digitalWrite(MOTORR_PIN1, GPIO.LOW) # water out
                wiringpi.digitalWrite(MOTORR_PIN2, GPIO.HIGH)
                #pwmA.ChangeDutyCycle(100)
                #pwmB.ChangeDutyCycle(70)
                thruster_move("water_pump1",water_pump_period,100,0)
                thruster_move("water_pump2",water_pump_period,70,0)
                print("over speed stop1")
            elif speed < -speed_limit:
                wiringpi.digitalWrite(MOTORL_PIN1, GPIO.HIGH) # water in
                wiringpi.digitalWrite(MOTORL_PIN2, GPIO.LOW)
                wiringpi.digitalWrite(MOTORR_PIN1, GPIO.HIGH) # water in
                wiringpi.digitalWrite(MOTORR_PIN2, GPIO.LOW)
                #pwmA.ChangeDutyCycle(100)
                #pwmB.ChangeDutyCycle(70)
                thruster_move("water_pump1",water_pump_period,100,0)
                thruster_move("water_pump2",water_pump_period,70,0)
                print("over speed stop2")
            else:
                if y > 0.3:  # left
                    if PIDcontrol_output > 0:  # need sink
                        wiringpi.digitalWrite(MOTORL_PIN1, GPIO.LOW)   # water out
                        wiringpi.digitalWrite(MOTORL_PIN2, GPIO.HIGH)   # water out
                        wiringpi.digitalWrite(MOTORR_PIN1, GPIO.HIGH)  # water in
                        wiringpi.digitalWrite(MOTORR_PIN2, GPIO.LOW)   # water in
                        #pwmA.ChangeDutyCycle(100)
                        #pwmB.ChangeDutyCycle(65)
                        thruster_move("water_pump1",water_pump_period,100,0)
                        thruster_move("water_pump2",water_pump_period,65,0)
                        print("stop5_balance")
                        stage = 0
                    elif PIDcontrol_output < 0:  # need float
                        wiringpi.digitalWrite(MOTORL_PIN1, GPIO.LOW)   # water out
                        wiringpi.digitalWrite(MOTORL_PIN2, GPIO.HIGH)  # water out
                        wiringpi.digitalWrite(MOTORR_PIN1, GPIO.HIGH)   # water in
                        wiringpi.digitalWrite(MOTORR_PIN2, GPIO.LOW)   # water in
                        #pwmA.ChangeDutyCycle(100)
                        #pwmB.ChangeDutyCycle(65)
                        thruster_move("water_pump1",water_pump_period,100,0)
                        thruster_move("water_pump2",water_pump_period,65,0)
                        print("L out, R stop6_balance")
                        stage = 1
                    else:
                        wiringpi.digitalWrite(MOTORL_PIN1, GPIO.LOW)
                        wiringpi.digitalWrite(MOTORL_PIN2, GPIO.LOW)
                        wiringpi.digitalWrite(MOTORR_PIN1, GPIO.LOW)
                        wiringpi.digitalWrite(MOTORR_PIN2, GPIO.LOW)
                        #pwmA.ChangeDutyCycle(100)
                        #pwmB.ChangeDutyCycle(65)
                        thruster_move("water_pump1",water_pump_period,100,0)
                        thruster_move("water_pump2",water_pump_period,65,0)
                        print("stop7")
                elif y < -0.3:  # right
                    if PIDcontrol_output > 0:  # need sink
                        wiringpi.digitalWrite(MOTORL_PIN1, GPIO.HIGH)  # water in
                        wiringpi.digitalWrite(MOTORL_PIN2, GPIO.LOW)   # water in
                        wiringpi.digitalWrite(MOTORR_PIN1, GPIO.HIGH)   # water in
                        wiringpi.digitalWrite(MOTORR_PIN2, GPIO.LOW)   # water in
                        #pwmA.ChangeDutyCycle(100)
                        #pwmB.ChangeDutyCycle(50)
                        thruster_move("water_pump1",water_pump_period,100,0)
                        thruster_move("water_pump2",water_pump_period,65,0)
                        print("L in, R stop8")
                        stage = 0
                    elif PIDcontrol_output < 0:  # need float
                        wiringpi.digitalWrite(MOTORL_PIN1, GPIO.HIGH)   # water in
                        wiringpi.digitalWrite(MOTORL_PIN2, GPIO.LOW)   # water in
                        wiringpi.digitalWrite(MOTORR_PIN1, GPIO.LOW)   # water out
                        wiringpi.digitalWrite(MOTORR_PIN2, GPIO.HIGH)  # water out
                        #pwmA.ChangeDutyCycle(100)
                        #pwmB.ChangeDutyCycle(65)
                        thruster_move("water_pump1",water_pump_period,100,0)
                        thruster_move("water_pump2",water_pump_period,65,0)
                        print("L stop, R out9")
                        stage = 1
                else:
                    wiringpi.digitalWrite(MOTORL_PIN1, GPIO.LOW)
                    wiringpi.digitalWrite(MOTORL_PIN2, GPIO.LOW)
                    wiringpi.digitalWrite(MOTORR_PIN1, GPIO.LOW)
                    wiringpi.digitalWrite(MOTORR_PIN2, GPIO.LOW)
                    #pwmA.ChangeDutyCycle(100)
                    #pwmB.ChangeDutyCycle(65)
                    thruster_move("water_pump1",water_pump_period,100,0)
                    thruster_move("water_pump2",water_pump_period,65,0)
                    print("stop10")
                if ((PIDcontrol_output > 0) and (speed==0) and (abs(accelaration)<accelaration_2cons)):  # need sink
                    wiringpi.digitalWrite(MOTORL_PIN1, GPIO.HIGH)  # water in
                    wiringpi.digitalWrite(MOTORL_PIN2, GPIO.LOW)   # water in
                    wiringpi.digitalWrite(MOTORR_PIN1, GPIO.HIGH)  # water in
                    wiringpi.digitalWrite(MOTORR_PIN2, GPIO.LOW)   # water in
                    #pwmA.ChangeDutyCycle(100)
                    #pwmB.ChangeDutyCycle(80)
                    thruster_move("water_pump1",water_pump_period,100,0)
                    thruster_move("water_pump2",water_pump_period,80,0)
                    print("L in, R in11")
                    stage = 0
                elif (PIDcontrol_output < 0 and speed == 0 and abs(accelaration)<accelaration_2cons):  # need float
                    wiringpi.digitalWrite(MOTORL_PIN1, GPIO.LOW) # water out
                    wiringpi.digitalWrite(MOTORL_PIN2, GPIO.HIGH)
                    wiringpi.digitalWrite(MOTORR_PIN1, GPIO.LOW)# water out
                    wiringpi.digitalWrite(MOTORR_PIN2, GPIO.HIGH)
                    #pwmA.ChangeDutyCycle(100)
                    #pwmB.ChangeDutyCycle(65)
                    thruster_move("water_pump1",water_pump_period,100,0)
                    thruster_move("water_pump2",water_pump_period,65,0)
                    print("L out, R out12")
                    stage = 1 
                else:
                    wiringpi.digitalWrite(MOTORL_PIN1, GPIO.LOW)
                    wiringpi.digitalWrite(MOTORL_PIN2, GPIO.LOW)
                    wiringpi.digitalWrite(MOTORR_PIN1, GPIO.LOW)
                    wiringpi.digitalWrite(MOTORR_PIN2, GPIO.LOW)
                    #pwmA.ChangeDutyCycle(80)
                    #pwmB.ChangeDutyCycle(50)
                    thruster_move("water_pump1",water_pump_period,80,0)
                    thruster_move("water_pump2",water_pump_period,50,0)
                    print("stop13")
    except KeyboardInterrupt:
    # Close the serial connection
        pass
    
    #Manual Testing here
    buoyancy_node.write_response(input[0],input[1]) 

    buoyancy_node.destroy_node()
    rclpy.shutdown()