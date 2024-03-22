#FYP AUV Control Node Designed by Cisco HE
#20058054d@connect.polyu.hk
#Function: Requesting control Node to respond the control command to implement


import rclpy
import time
from rclpy.node import Node
from control_interfaces.srv import GetCommand, BuoyancyControl
from control_interfaces.msg import AUVStatus
from .submodules.auv_control_function import auv_init, thruster_system

from flask import Flask, render_template
import threading
#app = Flask(__name__,template_folder='submodules')
app = Flask(__name__)
app.config['DEBUG'] = False

# Function to run the Flask app
def run_flask():
    app.run(host='0.0.0.0', port=5000)

#HTML:
html = """

<!DOCTYPE html>

<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Control Node Status</title>
</head>

<body>
    <h1>Control Node Status</h1>
    <p>Task Name: {{ task_name }}</p>
    <p>Thruster Direction: {{ thruster_direction }}</p>
    <p>Buoyancy Direction: {{ buoyancy_direction }}</p>
    <p>Buoyancy Depth: {{ buoyancy_depth }}</p>
    <p>Buoyancy Now Depth: {{ buoyancy_now_depth }}</p>
</body>

</html>

"""


class ControlNode(Node):
    def __init__(self):
        super().__init__('control_node')
        self.client_to_master = self.create_client(GetCommand, 'get_command')
        self.client_to_buoyancy = self.create_client(BuoyancyControl, 'change_depth')

        while not (self.client_to_master.wait_for_service(timeout_sec=1.0) and self.client_to_buoyancy.wait_for_service(timeout_sec=1.0)):
            if self.client_to_master.wait_for_service(timeout_sec=1.0) == False:
                self.get_logger().info('[!] Waiting for master Node --> [master_node]...')
            elif self.client_to_buoyancy.wait_for_service(timeout_sec=1.0) == False:
                self.get_logger().info('[!] Waiting for buoyancy node --> [buoyancy_node]...')
        
        self.get_logger().info('[O] Found master Node --> [master_node] and buoyancy node --> [buoyancy_node]...')
        self.req_master = GetCommand.Request()
        self.req_buoyancy = BuoyancyControl.Request()
        #self.timer = self.create_timer(2, self.send_request)  #Let's call it every 0.5 seconds
        self.buoyancy_depth = 0.4 #Default Buoyancy depth is 0.4m
        self.buoyancy_now_depth = 0
        self.buoyancy_count = 5 #Timer variable for requesting buoyancy_node in a specific period

        #Create a client to publish the control node's status
        self.publisher_ = self.create_publisher(AUVStatus, 'AUV_status', 10)
        self.timer = self.create_timer(1.0, self.timer_callback)  # Timer callback every 1 second
        self.task_name = ""
        self.thruster_direction = ""
        self.buoyancy_direction = ""

        #Create some variables to clean pending requests
        self.future_master_count = 0
        self.future_master_status = True

        #Debug
        #print("Here0")

    def send_request(self):
        if self.client_to_master.service_is_ready():
            self.req_master.get_command = True #Let Mater Node know we are gonna request a control command
            self.future_master = self.client_to_master.call_async(self.req_master) #Asynchronous request
            rclpy.spin_until_future_complete(self, self.future_master) #Wait until reponse is available
            return True
        else:
            self.get_logger().warn('[!] Master Node Service is not ready. Cannot send command.')
            return False
        
    def request_modify_depth(self):
        if self.client_to_buoyancy.service_is_ready():
            self.req_buoyancy.modify_depth = True #Let Mater Node know we are gonna request a control command
            self.req_buoyancy.new_depth = round(float(self.buoyancy_depth),2)
            self.get_logger().info("[O] Requesting Buoyancy Node to set new depth of: {}".format(self.buoyancy_depth))
            self.future_buoyancy = self.client_to_buoyancy.call_async(self.req_buoyancy) #Asynchronous request
            rclpy.spin_until_future_complete(self, self.future_buoyancy) #Wait until reponse is available
            return True
        else:
            self.get_logger().warn('[!] Buoyancy Node Service is not ready. Cannot send command.')
            return False        

    def timer_callback(self):
        #Publish PWM parameters
        msg = AUVStatus()
        msg.task_name = self.task_name
        msg.thruster_direction = self.thruster_direction
        msg.buoyancy_direction = self.buoyancy_direction
        msg.buoyancy_setpoint = self.buoyancy_depth
        msg.buoyancy_now_depth = float(self.buoyancy_now_depth)
        self.publisher_.publish(msg)

def main(args=None):
    #Initialize thrusters and water pumps' GPIO and PWM pins
    auv_init()

    rclpy.init(args=args)
    control_node = ControlNode()

###Start Flask Web###   
    # Create and start the Flask thread
    flask_thread = threading.Thread(target=run_flask)
    flask_thread.start()
###End of Flask
    
###Start Control Node Loop###

    try:
        while rclpy.ok():
            # Send the service request
            while control_node.send_request() == False:
                #If send_request() failed (returning False), the loop will retry after 1 seconds
                #With this approach, you can activate master node later and the system will not stuck in the
                #next command: rclpy.spin_once(control_node), spinning with nothing but waiting for future.done() from master node
                #time.sleep(0.05)
                continue
            #rclpy.spin_once(control_node)  #USELESS?
            print("Here1")
            #Remove pending request if necessary
            while control_node.future_master.done() == False:
                control_node.future_buoyancy_count += 1
                if control_node.future_buoyancy_count > 20:
                    control_node.get_logger().warn('[!] Requesting to Master Node --> [master_node] is timed out. The pending request is removed.')
                    control_node.client_to_master.remove_pending_request(control_node.future_master) #Find how to remove pending request in ROS2 rclpy API documentation.
                    control_node.future_buoyancy_count = 0
                    control_node.future_master_status = False
                    break
                time.sleep(0.2)

            if control_node.future_master_status == False:
                continue #Restart

            if control_node.future_master.done():
                # Get the service response
                response = control_node.future_master.result()
                # Log the received result
                #print(f"{response.hardware_name},{response.hardware_parameter},{response.time},{response.angle}")
                
                #Write task_name, buoyancy_direction, thruster_direction to Node object
                control_node.task_name = response.task_name
                control_node.buoyancy_direction = response.buoyancy_direction
                control_node.thruster_direction = response.thruster_direction

                #control_node.get_logger().info(f"[O]Control Node receives responses from master node. Task name: {response.task_name}, Buoyancy: {response.buoyancy_direction}, Thrusters: {response.thruster_direction}, Duration (time): {response.time}, Angle: {response.angle}")
                control_node.get_logger().info(f"[O]Control Node receives responses from master node. Task name: {response.task_name}, Buoyancy: {response.buoyancy_direction}, Thrusters: {response.thruster_direction}")                
                control_node.get_logger().info(f"Count: {response.count}")
                #if thruster_system(response.thruster_direction, response.time, response.angle) == True:
                if thruster_system(response.thruster_direction) == True:
                    print("thrsuter_system() has been called")
                else: 
                    print("[!]Error in thruster_system()")
                #Debug Use:
                #print("Here1, Buoyancy: {}".format(response.buoyancy_direction))
                control_node.get_logger().info(f"[buoyancy_system] Hardware Control: Buoyancy; Direction: {response.buoyancy_direction}")
                if control_node.buoyancy_count < 5:
                    control_node.get_logger().info(f"Current buoyancy count: {control_node.buoyancy_count}; Buoyancy Request is Skipped")
                else:
                    #Start requesting buoyancy_node
                    if response.buoyancy_direction != "Neutral":
                        #Debug Use:
                        control_node.get_logger().info("*******************")
                        if response.buoyancy_direction == "Up":
                            control_node.buoyancy_depth += 0.1
                            control_node.get_logger().info(f"[O] New Depth: {round(control_node.buoyancy_depth,3)}")
                        elif response.buoyancy_direction == "Down":
                            control_node.buoyancy_depth -= 0.1
                            control_node.get_logger().info(f"[O] New Depth: {round(control_node.buoyancy_depth,3)}")
                        control_node.get_logger().info("*******************")
                        #print("Here3")

                        ###Start requesting the buoyancy node to change depth
                        while control_node.request_modify_depth() == False:
                            time.sleep(0.1)
                            continue
                        print("Here4")
                        
                        if control_node.future_buoyancy.done():
                            buoyancy_response = control_node.future_buoyancy.result()
                            control_node.buoyancy_now_depth = round(buoyancy_response.now_depth,2)
                            control_node.get_logger().info(f"[O]Control Node receives responses from buoyancy node. Status of success: {buoyancy_response.is_succeeded}, Current Depth Read: {round(buoyancy_response.now_depth,2)}")
                            control_node.get_logger().info(f"[O]Control Node receives responses from buoyancy node. Current Depth Read: {round(buoyancy_response.now_depth,2)}")
                    control_node.buoyancy_count = -1 #As -1+1=0
                control_node.buoyancy_count += 1
                @app.route('/auv')
                def auv():
                    return render_template(html, task_name = control_node.task_name, thruster_direction = control_node.thruster_direction, buoyancy_direction = control_node.buoyancy_direction, buoyancy_depth = control_node.buoyancy_depth, buoyancy_now_depth = control_node.buoyancy_now_depth)
        #return "Test"
            time.sleep(0.3) #0.3 seconds per cycle
            del response

                # Wait a bit before sending the next request
                #time.sleep(0.5)  # Adjust the sleep duration as needed
                #Control node should immediately request again after the response is received       

    except KeyboardInterrupt:
        control_node.destroy_node()
        rclpy.shutdown()
        pass  # Handle Ctrl+C gracefully

    

if __name__ == "__main__":
    main()