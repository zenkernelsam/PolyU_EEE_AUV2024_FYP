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
        self.hardware_name = 0
        self.hardware_parameter = 0
        self.time = 0
        self.angle = 0
        self.start = False
        #Task node: flare_detect, gate_detect, drum_detect
        while not self.client.wait_for_service(timeout_sec=1.0): #For Task nodes
            self.get_logger().info('[!] Waiting for Task Node --> [task_node]...')
        self.req = GetTask.Request()

    def write_response(self, hardware_name,hardware_parameter,time,angle, start):
        self.hardware_name = hardware_name
        self.hardware_parameter = hardware_parameter
        self.time = time
        self.angle = angle
        self.start = start

    def send_request(self):
        if self.client.service_is_ready():
            self.req.get_task = True #Let Mater Node know we are gonna request a control command
            self.future = self.client.call_async(self.req) #Asynchronous request
            rclpy.spin_until_future_complete(self, self.future) #Wait until reponse is available
        else:
            self.get_logger().warn('[!] Task Node Service is not ready. Cannot send command.')

    def get_command_callback(self, request, response):
        #self.get_logger().info(f"Get request.get_command: {request.get_command}") # Debug

        if self.start is not False:
            if request.get_command is True:
                response.hardware_name = self.hardware_name
                response.hardware_parameter = self.hardware_parameter
                response.time = self.time
                response.angle = self.angle
                self.start = False
            return response
        
    

def main(args=None):
    rclpy.init(args=args)
    master_node = MasterNode()
    try:
        while rclpy.ok():
            # Send the service request
            master_node.send_request()
            rclpy.spin_once(master_node)
            if master_node.future.done():
                # Get the service response
                response = master_node.future.result()
                if response.is_finished is True:
                    #Write into node
                    master_node.write_response(response.hardware_name,response.hardware_parameter,response.time,response.angle,True)
                    master_node.get_logger().info(f"{response.hardware_name},{response.hardware_parameter},{response.time},{response.angle}") # Wait a bit before sending the next request
                else:
                    print("The Task is already implemented, the program should now request the next task.")
            time.sleep(0.5) #While master node control the frequency of the request flow  
    except KeyboardInterrupt:
        pass  # Handle Ctrl+C gracefully
    master_node.destroy_node()
    rclpy.shutdown()