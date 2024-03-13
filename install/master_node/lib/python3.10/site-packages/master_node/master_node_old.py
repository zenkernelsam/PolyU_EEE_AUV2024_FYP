#FYP AUV Master Node Designed by Cisco HE
#20058054d@connect.polyu.hk
#Function: A proxy which proxies Control Node's request to dedicated task node
#Request: Control Node --> Master Node --> Task Node 1 --> Task Node 2 ... --> Task Node N which is current task
#Response: Task Node N --> Master Node --> Control Node
import rclpy
import time
from rclpy.node import Node
from control_interfaces.srv import GetCommand, GetTask

class MasterNode(Node):
    def __init__(self):
        super().__init__('master_node')
        self.srv = self.create_service(GetCommand, 'get_command', self.get_command_callback) #Create a Server (service) to listen Control Node's request
        self.client = self.create_client(GetTask, 'task1') #Create Client to request Task Nodes' command
        #Task node: flare_detect, gate_detect, drum_detect
        while not self.client.wait_for_service(timeout_sec=1.0): #For Task nodes
            self.get_logger().info('[!] Waiting for Task Node --> [task_node]...')
        self.req = GetTask.Request()

    def send_request(self):
        if self.client.service_is_ready():
            self.req.get_task = True #Let Mater Node know we are gonna request a control command
            self.future = self.client.call_async(self.req) #Asynchronous request
            rclpy.spin_until_future_complete(self, self.future) #Wait until reponse is available
        else:
            self.get_logger().warn('[!] Task Node Service is not ready. Cannot send command.')

    def get_command_callback(self, request, response_from_master):
        self.get_logger().info(f"Get request.get_command: {request.get_command}") #Debug
        if request.get_command is True:
            self.send_request()
            if self.future.done():
                    print("Get response from Task Node")
                    # Get the service response
                    response_from_task = self.future.result()
                    # Log the received result
                    response_from_master.hardware_name = response_from_task.hardware_name
                    response_from_master.hardware_parameter = response_from_task.hardware_parameter
                    #response_from_master.time = response_from_task.time
                    response_from_master.time = 15
                    response_from_master.angle = response_from_task.angle
            #response.hardware_name = "water_pump"
            #response.hardware_parameter = "out"
            #response.time = 10
            #response.angle = 30
            self.get_logger().info(f"Response should be finished..")
        return response_from_master
    

def main(args=None):
    rclpy.init(args=args)
    master_node = MasterNode()
            # Spin until the service response is interrupted by keyboard
    try:
        while rclpy.ok():
            # Send the service request
            master_node.send_request()

            while True:
                rclpy.spin_once(master_node)
                if master_node.future.done():

                    # Get the service response
                    response = master_node.future.result()
                    # Log the received result
                    master_node.get_logger().info(f'Hardware Name: {response.hardware_name}')
                    master_node.get_logger().info(f'Hardware Parameter: {response.hardware_parameter}')
                    master_node.get_logger().info(f'Time used: {response.time}')
                    master_node.get_logger().info(f'Angle: {response.angle}')
                    time.sleep(0.2)
                    break 
    except KeyboardInterrupt:
        pass  # Handle Ctrl+C gracefully
    #rclpy.spin(master_node)
    master_node.destroy_node()
    rclpy.shutdown()