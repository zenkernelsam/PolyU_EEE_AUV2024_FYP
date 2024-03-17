#FYP AUV Master Node Designed by Cisco HE
#20058054d@connect.polyu.hk
#Function: Receiving request from control node to modify the AUV's depth

import rclpy
from rclpy.node import Node
from control_interfaces.srv import BuoyancyControl
#from buoyancy_node.buoyancy_function
import sys


###START OF ROS2 BUOYANCY NODE CLASS###
class BuoyancyNode(Node):
    def __init__(self):
        super().__init__('buoyancy_node')
        self.srv = self.create_service(BuoyancyControl, 'change_depth', self.get_buoyancy_callback) #Create a Server (service) to listen Master Node's request
        #Task node: flare_detect, gate_detect, drum_detect
        '''
        Remember to write your task name below (self.task_name) for better identification
        '''
        self.modify_depth = None
        self.buoyancy_depth = 0
        self.is_succeeded = None

        
    

    def get_buoyancy_callback(self, request_from_control_node, response_from_buoyancy):
        #print("get_task_callback is called")
        #self.get_logger().info(f"Get request.get_command: {request.get_task}") #Debug
        if request_from_control_node.modify_depth == True:
            response_from_buoyancy.is_succeeded = self.is_succeeded == True
            response_from_buoyancy.now_depth = self.buoyancy_depth
            self.get_logger().info(f"[O] Buoyancy Node received modify_depth: {request_from_control_node.new_depth}.")           
            self.get_logger().info(f"[O] Buoyancy Node has responded back to Control Node.")
        return response_from_buoyancy
    
    def write_response(self, is_succeeded, now_depth):
        self.get_logger().info(f"write_reponse() started")
        self.is_succeeded = is_succeeded == "True"
        self.buoyancy_depth = float(now_depth)


        

def main(args=None):
    rclpy.init(args=args)
    buoyancy_node = BuoyancyNode()
    input = sys.argv[1:]

    #Manual Testinf here
    buoyancy_node.write_response(input[0],input[1]) 

    rclpy.spin(buoyancy_node)
    buoyancy_node.destroy_node()
    rclpy.shutdown()