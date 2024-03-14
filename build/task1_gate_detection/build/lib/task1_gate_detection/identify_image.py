#ros2 library 
import rclpy # ros2 python library
from rclpy.node import Node # ros2 node library
from cv_bridge import CvBridge # ros2 & OpenCV image transformation library

#other libraries
import cv2 # OpenCV image processing library

#message import library
from sensor_msgs.msg import Image # image messsage library
#service import library
from facer_interfaces.srv import DetectionResult

#self-defined function
from task1_gate_detection.gate_detector import process_and_update

'''Image collection node'''
class IdentifyImage(Node):

    '''Initialization function'''
    def __init__(self):
        super().__init__('identify_image') # initilize the ros2 node called "identify_image"

        '''Topic subscriber'''
        '''frame_image topic subscriber code'''
        # Create the object of the topic subscriber (msg_type, topic_name, subscriber_callback_function, array_length)
        self.subscription = self.create_subscription(
            Image,
            'frame_image',
            self.listener_callback,
            10
        )
        self.cv_bridge = CvBridge() # create image transformation object that can transform the image from OpenCV to ros2 type
        
        '''variables dont't need to be changed'''
        self.tracking = False
        self.tracker = None
        self.lost_tracking_counter = 0  # Counter to keep track of lost tracking
        self.false_counter = 0
        self.buoyancy_direction = 'None'
        self.thruster_direction = 'None'
        
        '''variables could be changed'''
        self.lost_tracking_threshold = 15  # Threshold for lost tracking
        # '''face_result service server code'''
        # # Create the object of service server (msg type, server name, server callback function)
        # self.srv = self.create_service(FaceResult, 'face_result', self.face_result_callback)

        '''Service server code'''
        self.srv = self.create_service(DetectionResult, 'gate_detect', self.gate_detect_callback)
        self.result = 'No Gate'
        


    '''Topic subscriber callback function'''
    def listener_callback(self, ros2_image):
        frame = self.cv_bridge.imgmsg_to_cv2(ros2_image, 'bgr8') # transform the img msg from ros2 to OpenCV image

        # Process frame
        frame, combined_mask, self.tracking, self.tracker, self.lost_tracking_counter, self.false_counter, self.buoyancy_direction, self.thruster_direction = process_and_update(
            frame, 
            self.lost_tracking_threshold, 
            self.lost_tracking_counter,
            self.tracking,
            self.tracker,
            self.false_counter
            )

        if self.tracking:
            self.result = 'Gate detected'
        # self.frame_counter += 1
        # self.lost_tracking_counter += 1

        # Display the frame with detected gate
        cv2.imshow("Processed Frame", frame)
        cv2.imshow("Combined_mask", combined_mask)
        cv2.waitKey(1)

    # '''Service server callback function'''
    # def face_result_callback(self, request, response):
    #     if request.apply_result == True: # determine whether the request is true or false 
    #         response.get_result = self.result
    #         return response
    
    def gate_detect_callback(self, request, response):
        if request.apply_result == True: # reqeust from client
            response.get_result = self.result # send the detection result
            response.buoyancy_direction = self.buoyancy_direction
            response.thruster_direction = self.thruster_direction
            print('request is True')
            return response 
        elif request.apply_result == False:
            print("request is False")
        else:
            print('request is None')
            


def main(args=None):
    rclpy.init(args=args) #ros2 python port initialization

    identify_image = IdentifyImage() # create an node object of the CaptureImage class

    rclpy.spin(identify_image) # loop to wait for quitting ros2 

    cv2.destroyAllWindows()
    identify_image.destroy_node() # destroy the node object to release the storage place
    rclpy.shutdown() # close the python port


if __name__ == "__main__":
    main()