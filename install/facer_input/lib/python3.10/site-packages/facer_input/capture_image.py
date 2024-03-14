#ros2 library 
import rclpy # ros2 python library
from rclpy.node import Node # ros2 node library
from cv_bridge import CvBridge # ros2 & OpenCV image transformation library

#other libraries
import cv2 # OpenCV image processing library
import time # time library

#message import library
from sensor_msgs.msg import Image # image messsage library

'''Image collection node'''
class CaptureImage(Node):

    '''Initialization function'''
    def __init__(self):
        super().__init__('capture_image') # initilize the ros2 node called "capture_image"

        '''frame_image topic publisher code'''
        self.cap = cv2.VideoCapture() # create an object that can collect video
        self.cap.open(0, apiPreference=cv2.CAP_V4L2)
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
        self.cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc('M', 'J', 'P', 'G'))
        # self.cap.set(cv2.CAP_PROP_EXPOSURE, 0.25)
        self.cv_bridge = CvBridge() # create image transformation object that can transform the image from OpenCV to ros2 type
        # create an topic publisher object (message type, topic name, array length)
        self.publisher_ = self.create_publisher(
            Image,
            'frame_image',
            10
        )


        #timer_period = 0.1 # confirm the publishing period, unit is second
        from rcl_interfaces.msg import ParameterDescriptor # import the parameter description
        self.parameter_descriptor = ParameterDescriptor(description = 'this is topic publish period!') # adding the parameter description 
        self.declare_parameter('timer_period', 0.1, self.parameter_descriptor) # revise the publishing period to be the parameter
        timer_period_param = self.get_parameter('timer_period').get_parameter_value().double_value #set the parameter tothe double floating number

        self.timer = self.create_timer(timer_period_param , self.timer_callback) # create a timer


        # '''camera_state action server code'''
        # # create the object of action server 
        # self._action_server = ActionServer(
        #     self,
        #     CameraState,
        #     'camera_state',
        #     self.execute_callback
        # )

    '''topic publisher timer callback function'''
    def timer_callback(self):
        ret, frame = self.cap.read()
        if not ret:
            self.get_logger().info('Camera frame not available')
            return
        frame = cv2.resize(frame, (640, 480))
        msg = self.cv_bridge.cv2_to_imgmsg(frame, encoding='bgr8') #transform image frame from the OpenCV format to ros2 img msg format
        self.publisher_.publish(msg) #publish the image
        self.get_logger().info('Publishing camera frame')

def main(args=None):
    rclpy.init(args=args) #ros2 python port initialization

    capture_image = CaptureImage() # create an node object of the CaptureImage class

    rclpy.spin(capture_image) # loop to wait for quitting ros2 
    
    capture_image.cap.release()
    capture_image.destroy_node() # destroy the node object to release the storage place
    rclpy.shutdown() # close the python port


if __name__ == "__main__":
    main()