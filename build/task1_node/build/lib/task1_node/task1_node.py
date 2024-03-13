#FYP AUV Master Node Designed by Cisco HE
#20058054d@connect.polyu.hk
#Function: A proxy which proxies Control Node's request to dedicated task node
#Request: Control Node --> Master Node --> Task Node 1 --> Task Node 2 ... --> Task Node N which is current task
#Response: Task Node N --> Master Node --> Control Node
import rclpy
from rclpy.node import Node
from control_interfaces.srv import GetCommand, GetTask
import sys

class Task1Node(Node):
    def __init__(self):
        super().__init__('task1_node')
        self.srv = self.create_service(GetTask, 'task1', self.get_task_callback) #Create a Server (service) to listen Master Node's request
        #Task node: flare_detect, gate_detect, drum_detect
        '''
        Remember to write your task name below (self.task_name) for better identification
        '''
        self.task_name = "task1" 
        self.is_finished = None
        self.buoyancy_direction = ""
        self.thruster_direction = ""
        self.time = 0
        self.angle = 0
    

    def get_task_callback(self, request, response_from_task):
        #print("get_task_callback is called")
        #self.get_logger().info(f"Get request.get_command: {request.get_task}") #Debug
        if request.apply_result == True:
            response_from_task.task_name = self.task_name
            response_from_task.is_finished = self.is_finished == True
            response_from_task.buoyancy_direction = self.buoyancy_direction
            response_from_task.thruster_direction = self.thruster_direction
            response_from_task.time = self.time
            response_from_task.angle = self.angle
            #self.get_logger().info(f"Response should be finished..")
        return response_from_task
    
    def write_response(self, is_finished, buoyancy_direction, thruster_direction):
        print(f"write_response() started: {is_finished}, {buoyancy_direction}, {thruster_direction}")
        self.is_finished = is_finished == "True"
        self.buoyancy_direction = buoyancy_direction
        self.thruster_direction = thruster_direction
        #self.time = int(time)
        #self.angle = int(angle)
        self.time = 0
        self.angle = 0

def main(args=None):
    rclpy.init(args=args)
    task1_node = Task1Node()
    input = sys.argv[1:]
    task1_node.write_response(input[0],input[1],input[2]) 
    """
    You can the run "ros2 run task1_node task1_node False abc abc" which will response:
    is_finish: True/False [bool]
    Hardware name: abc [string]
    Hardware parameter: abc [string]
    Time: 123 [uint32]
    Angle: 123 [uint32]
    """
    rclpy.spin(task1_node)
    task1_node.destroy_node()
    rclpy.shutdown()