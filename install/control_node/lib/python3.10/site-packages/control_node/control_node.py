#FYP AUV Control Node Designed by Cisco HE
#20058054d@connect.polyu.hk
#Function: Requesting control Node to respond the control command to implement
import rclpy
import time
from rclpy.node import Node
from control_interfaces.srv import GetCommand, BuoyancyControl
from .submodules.auv_control_function import auv_init, thruster_system

class ControlNode(Node):
    def __init__(self):
        super().__init__('control_node')
        self.client_to_master = self.create_client(GetCommand, 'get_command')
        self.client_to_buoyancy = self.create_client(BuoyancyControl, 'change_depth')       
        while not (self.client_to_master.wait_for_service(timeout_sec=1.0) or self.client_to_buoyancy.wait_for_service(timeout_sec=1.0)):
            self.get_logger().info('[!] Waiting for master Node --> [master_node] and buoyancy node --> [buoyancy_node]...')
        self.get_logger().info('[O] Found master Node --> [master_node]...')
        self.req_master = GetCommand.Request()
        self.req_buoyancy = BuoyancyControl.Request()
        #self.timer = self.create_timer(2, self.send_request)  #Let's call it every 0.5 seconds
        self.buoyancy_depth = 0.4 #Default Buoyancy depth is 0.4m

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
            self.req_buoyancy.new_depth = float(self.buoyancy_depth)
            #self.get_logger().info("[O] Requesting Buoyancy Node to set new depth of: {}".format(self.buoyancy_depth))
            self.future_buoyancy = self.client_to_buoyancy.call_async(self.req_buoyancy) #Asynchronous request
            rclpy.spin_until_future_complete(self, self.future_buoyancy) #Wait until reponse is available
            return True
        else:
            self.get_logger().warn('[!] Buoyancy Node Service is not ready. Cannot send command.')
            return False        

def main(args=None):
    #Initialize thrusters and water pumps' GPIO and PWM pins
    auv_init()

    rclpy.init(args=args)
    control_node = ControlNode()
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
            if control_node.future_master.done():
                # Get the service response
                response = control_node.future_master.result()
                # Log the received result
                #print(f"{response.hardware_name},{response.hardware_parameter},{response.time},{response.angle}")
                
                #control_node.get_logger().info(f"[O]Control Node receives responses from master node. Task name: {response.task_name}, Buoyancy: {response.buoyancy_direction}, Thrusters: {response.thruster_direction}, Duration (time): {response.time}, Angle: {response.angle}")
                control_node.get_logger().info(f"Count: {response.count}")
                thruster_system(response.thruster_direction, response.time, response.angle)
                if response.buoyancy_direction != "Neutral":
                    if response.buoyancy_direction == "Up":
                        control_node.buoyancy_depth += 0.1
                        print(f"New Depth: {control_node.buoyancy_depth}")
                    elif response.buoyancy_direction == "Down":
                        control_node.buoyancy_depth -= 0.1
                        print(f"New Depth: {control_node.buoyancy_depth}")

            #Start requesting the buoyancy node to change depth
                    while control_node.request_modify_depth() == False:
                    #If send_request() failed (returning False), the loop will retry after 0.5 seconds
                    #With this approach, you can activate master node later and the system will not stuck in the
                    #next command: rclpy.spin_once(control_node), spinning with nothing but waiting for future.done() from master node
                        #time.sleep(0.1)
                        continue
                    if control_node.future_buoyancy.done():
                        buoyancy_response = control_node.future_buoyancy.result()
                        #control_node.get_logger().info(f"[O]Control Node receives responses from buoyancy node. Status of success: {buoyancy_response.is_succeeded}, Current Depth Set: {round(buoyancy_response.now_depth,2)}")
            #time.sleep(0.1)

                # Wait a bit before sending the next request
                #time.sleep(0.5)  # Adjust the sleep duration as needed
                #Control node should immediately request again after the response is received       

    except KeyboardInterrupt:
        control_node.destroy_node()
        rclpy.shutdown()
        pass  # Handle Ctrl+C gracefully

    

if __name__ == "__main__":
    main()