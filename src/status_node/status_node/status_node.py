"""
Author: Cisco HE
Node: status_node
Node Task: To display current AUV status

"""

import rclpy
from rclpy.node import Node
from control_interfaces.msg import AUVStatus

class StatusNode(Node):
    
    def __init__(self):
        super().__init__("status_ndoe")
        self.subscription = self.create_subscription(
        AUVStatus,
        'AUV_status',
        self.listener_callback,
        10    
        )
        self.subscription

    def listener_callback(self, msg):
        print("**********************************")
        self.get_logger().info(f'[O] Obtained AUV Status:')
        print(f"Current Task Name: {msg.task_name}")
        print(f"Thruster Direction: {msg.thruster_direction}")
        print(f"Buoyancy Direction: {msg.buoyancy_direction}")
        print(f"Buoyancy Setpoint: {msg.buoyancy_setpoint}")
        print(f"Current AUV Depth: {msg.buoyancy_now_depth}")
        print("**********************************")


def main(args=None):
    rclpy.init(args=args)

    status_node = StatusNode()

    rclpy.spin(status_node)

    status_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()