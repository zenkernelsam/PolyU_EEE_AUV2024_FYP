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
        self.current_node_index = 0
        self.task_nodes = ['task1', 'task2', 'task3', 'task4']  # Add all task nodes topic names
        self.client = self.create_client(GetTask, self.task_nodes[self.current_node_index])

        '''
        The client for requesting task_node
        i.e. self.client = self.create_client(GetTask, self.task_nodes[self.current_node_index])
        is put in main()
        '''

        #Initial response messages
        self.task_name_from_task_node = ""
        self.hardware_name = ""
        self.hardware_parameter = ""
        self.time = 0
        self.angle = 0
        self.start = False

        #Task node: flare_detect, gate_detect, drum_detect
        while not self.client.wait_for_service(timeout_sec=1.0): #For Task nodes
            self.get_logger().info('[!] Waiting for Task Node --> [task_node]...')
        self.get_logger().info('[O] Found Task Node --> [task_node]...')
        self.req = GetTask.Request()

    def write_response(self, task_name, buoyancy_direction, hardware_parameter, time, angle, start):
        self.task_name_from_task_node = task_name
        self.hardware_name = hardware_name
        self.hardware_parameter = hardware_parameter
        self.time = time
        self.angle = angle
        self.start = start

    def pop_index(self,num):
        self.task_nodes.pop(num)


    def send_request(self):
        if self.client.service_is_ready():
            self.req.apply_result = True #Let Mater Node know we are gonna request a control command
            self.future = self.client.call_async(self.req) #Asynchronous request
            rclpy.spin_until_future_complete(self, self.future) #Wait until reponse is available
            return True
        else:
            self.get_logger().warn('[!] Task Node Service is not ready. Cannot send command.')
            return False

    def get_command_callback(self, request, response_from_master):
        #self.get_logger().info(f"Get request.get_command: {request.get_command}") # Debug
        #Freewheel the callback until it gets message from task node
        while True:
            if self.start is True:
                if request.get_command is True:
                    response_from_master.task_name_from_task_node = self.task_name_from_task_node
                    response_from_master.hardware_name = self.hardware_name
                    response_from_master.hardware_parameter = self.hardware_parameter
                    response_from_master.time = self.time
                    response_from_master.angle = self.angle
                    self.start = False
                return response_from_master
            else:
                continue
        
    

def main(args=None):
    rclpy.init(args=args)
    master_node = MasterNode()
    try:
        while rclpy.ok():
            # Send the service request
            master_node.client = master_node.create_client(GetTask, master_node.task_nodes[master_node.current_node_index]) #Create Client accoridng to the above list (i.e. task1_node by default) to request Task Nodes' command
            while master_node.send_request() == False:
                #If send_request() failed (returning False), the loop will retry after 1 seconds
                #With this approach, you can activate task nodes later and the system will not stuck in the
                #next command: rclpy.spin_once(master_node), spinning with nothing but waiting for future.done() from task node
                time.sleep(1)
                continue
            
            rclpy.spin_once(master_node)
            if master_node.future.done():
                # Get the service response
                response = master_node.future.result()
                print("Current responding task node name: {}".format(response.task_name))
                if response.is_finished is True:

                    #Write into node
                    master_node.write_response(response.task_name,response.hardware_name,response.hardware_parameter,response.time,response.angle,True)
                    master_node.get_logger().info(f"{response.is_finished},{response.hardware_name},{response.hardware_parameter},{response.time},{response.angle}") # Wait a bit before sending the next request
                    ###POP THE INDEX OUT### (i.e. remove task1_node from self.task_nodes list)
                    print("The Task is already implemented, the program should now request the next task.")
                    master_node.current_node_index += 1
                    print("Switch to next Task: {}".format(master_node.task_nodes[master_node.current_node_index]))

                else:
                    master_node.get_logger().info(f"{response.is_finished},{response.hardware_name},{response.hardware_parameter},{response.time},{response.angle}") # Wait a bit before sending the next request
                    print("The task node is not yet completed.")
                    #Forwarding message to control_node:
                    master_node.write_response(response.task_name, response.hardware_name,response.hardware_parameter,response.time,response.angle,True)
            time.sleep(0.5) #While master node control the frequency of the request flow


        #Exit criteria
    except KeyboardInterrupt:
        pass  # Handle Ctrl+C gracefully
    master_node.destroy_node()
    rclpy.shutdown()