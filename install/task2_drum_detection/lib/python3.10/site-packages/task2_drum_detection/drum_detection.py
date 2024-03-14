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
from task2_drum_detection.drum_detection_functions import drum_detect

'''Image collection node'''
class DrumDetection(Node):

    '''Initialization function'''
    def __init__(self):
        super().__init__('drum_detection') # initilize the ros2 node called "identify_image"

        '''frame_image topic subscriber code'''
        # Create the object of the topic subscriber (msg_type, topic_name, subscriber_callback_function, array_length)
        self.subscription = self.create_subscription(
            Image,
            'frame_image',
            self.listener_callback,
            10
        )
        self.cv_bridge = CvBridge() # create image transformation object that can transform the image from OpenCV to ros2 type

        self.tracking = False
        
        # '''face_result service server code'''
        # # Create the object of service server (msg type, server name, server callback function)
        # self.srv = self.create_service(FaceResult, 'face_result', self.face_result_callback)

        '''flare_detect service server code'''
        '''Service server'''
        self.srv = self.create_service(DetectionResult, 'drum_detect', self.drum_detect_callback)
        self.result = 'No drum'


    '''Topic subscriber callback function'''
    def listener_callback(self, ros2_image):
        frame = self.cv_bridge.imgmsg_to_cv2(ros2_image, 'bgr8') # transform the img msg from ros2 to OpenCV image

        # Process frame
        frame, combined_mask, self.tracking = drum_detect(frame)

        if self.tracking == True:
            self.result = 'Drum detected'

        # Display the frame with detected gate
        cv2.imshow("Processed Frame", frame)
        cv2.imshow("Combined_mask", combined_mask)
        cv2.waitKey(1)
        

    # '''Service server callback function'''
    # def face_result_callback(self, request, response):
    #     if request.apply_result == True: # determine whether the request is true or false 
    #         response.get_result = self.result
    #         return response
    def drum_detect_callback(self, request, reponse):
        if request.apply_result == True: # reqeust from client
            reponse.get_result = self.result # send the detection result
            print('request is True')
            return reponse 
        elif request.apply_result == False:
            print("request is False")
        else:
            print('request is None')

def main(args=None):
    rclpy.init(args=args) #ros2 python port initialization

    drum_detection = DrumDetection() # create an node object of the CaptureImage class

    rclpy.spin(drum_detection) # loop to wait for quitting ros2 

    cv2.destroyAllWindows()
    drum_detection.destroy_node() # destroy the node object to release the storage place
    rclpy.shutdown() # close the python port


if __name__ == "__main__":
    main()