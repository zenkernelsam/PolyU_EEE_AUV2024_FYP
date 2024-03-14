# ROS2 library import
import rclpy
from rclpy.node import Node

import time

# Service message import
from facer_interfaces.srv import DetectionResult

class MasterNode(Node):
    """
    A simple ROS2 service client node for gate detection.
    """
    def __init__(self):
        super().__init__('master_node')
        # The client creation is deferred until the service is needed.
        self.client = None

    def send_request_gate_detect(self):
        """
        Sends a request to the gate detection service.
        """
        if not self.client:
            self.client = self.create_client(DetectionResult, 'gate_detect')
            
            # Wait for the service to be available.
            while not self.client:
                self.get_logger().info('Service not available, waiting again...')
                while not self.client.wait_for_service(timeout_sec=1.0):
                     self.get_logger().info('Service not available, waiting again...')
            
        # Create a request
        request = DetectionResult.Request()
        request.apply_result = True  # Set the request parameter

        # Call the service asynchronously
        self.future = self.client.call_async(request)
        
    def send_request_flare_detect(self):
        """
        Sends a request to the flare detection service.
        """
        if not self.client:
            self.client = self.create_client(DetectionResult, 'flare_detect')
            
            # Wait for the service to be available.
            while not self.client:
                self.get_logger().info('Service not available, waiting again...')
                while not self.client.wait_for_service(timeout_sec=1.0):
                     self.get_logger().info('Service not available, waiting again...')
            
        # Create a request
        request = DetectionResult.Request()
        request.apply_result = True  # Set the request parameter

        # Call the service asynchronously
        self.future = self.client.call_async(request)

    def send_request_drum_detect(self):
        """
        Sends a request to the drum detection service.
        """
        if not self.client:
            self.client = self.create_client(DetectionResult, 'drum_detect')
            
            # Wait for the service to be available.
            while not self.client:
                self.get_logger().info('Service not available, waiting again...')
                while not self.client.wait_for_service(timeout_sec=1.0):
                     self.get_logger().info('Service not available, waiting again...')
            
        # Create a request
        request = DetectionResult.Request()
        request.apply_result = True  # Set the request parameter

        # Call the service asynchronously
        self.future = self.client.call_async(request)

    def send_request_q_gate_detect(self):
        """
        Sends a request to the qualification gate detection service.
        """
        if not self.client:
            self.client = self.create_client(DetectionResult, 'Qgate_detect')
            
            # Wait for the service to be available.
            while not self.client:
                self.get_logger().info('Service not available, waiting again...')
                while not self.client.wait_for_service(timeout_sec=1.0):
                     self.get_logger().info('Service not available, waiting again...')
            
        # Create a request
        request = DetectionResult.Request()
        request.apply_result = True  # Set the request parameter

        # Call the service asynchronously
        self.future = self.client.call_async(request)

def main(args=None):
    rclpy.init(args=args)  # Initialize ROS2 Python client library

    master_node = MasterNode()

    # Spin until the service response is interrupted by keyboard
    try:
        while rclpy.ok():
            # Send the service request
            master_node.send_request_flare_detect()

            while True:
                rclpy.spin_once(master_node)
                if master_node.future.done():
                    
                    # Get the service response
                    response = master_node.future.result()
                    # Log the received result
                    master_node.get_logger().info(
                        '\nFlare Detection Result: %s \nBuoyancy Direction: %s \nThruster Direction: %s' %
                        (response.get_result, response.buoyancy_direction, response.thruster_direction))
                    break
           
            # Wait a bit before sending the next request
            time.sleep(1)  # Adjust the sleep duration as needed       
    except KeyboardInterrupt:
        pass  # Handle Ctrl+C gracefully

    master_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()