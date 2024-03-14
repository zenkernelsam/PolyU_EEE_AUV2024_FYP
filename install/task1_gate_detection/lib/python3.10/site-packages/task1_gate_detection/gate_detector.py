import cv2
import numpy as np

def color_mask(frame):
    # Convert the BGR image to L*a*b* color space
    lab_image = cv2.cvtColor(frame, cv2.COLOR_BGR2LAB)
    lab_image = cv2.GaussianBlur(lab_image, (3, 3), 0)
    gray_image = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    #gray_image = cv2.GaussianBlur(gray_image, (5, 5), 0)

    '''Color thresholding'''
    # Define the range for green colors in the L*a*b* color space
    # Note: these ranges are approximate and may require tuning
    lower_green = np.array([0, 0, 0])  # Lower bound of green in L*a*b* space
    upper_green = np.array([255, 116, 255])  # Upper bound of green in L*a*b* space

    lower_red = np.array([0, 120, 0])  # Lower bound of red in L*a*b* space
    upper_red = np.array([180, 255, 255])  # Upper bound of red in L*a*b* space

    # Threshold the L*a*b* image to get the green mask
    green_mask = cv2.inRange(lab_image, lower_green, upper_green)
    red_mask = cv2.inRange(lab_image, lower_red, upper_red)
    _, black_mask = cv2.threshold(gray_image, 94, 255, cv2.THRESH_BINARY_INV)
    #Exclude specular highlights
    # black_mask = cv2.bitwise_and(black_mask, cv2.bitwise_not(high_lightness))

    lower_blue_green = np.array([0, 0, 0])  # Lower bound of blue in L*a*b* space
    upper_blue_green = np.array([255, 255, 130])  # Upper bound of blue in L*a*b* space
    blue_mask_green = cv2.inRange(lab_image, lower_blue_green, upper_blue_green)

    lower_blue_red = np.array([0, 0, 0])  # Lower bound of blue in L*a*b* space
    upper_blue_red = np.array([255, 255, 115])  # Upper bound of blue in L*a*b* space
    blue_mask_red = cv2.inRange(lab_image, lower_blue_red, upper_blue_red)

    # Combine the green and red masks
    # combined_mask = cv2.bitwise_or(green_mask, red_mask)
    # combined_mask = cv2.bitwise_or(combined_mask, black_mask)
    # combined_mask = cv2.bitwise_and(combined_mask, cv2.bitwise_not(blue_mask))
    combined_mask_green = cv2.bitwise_and(green_mask, cv2.bitwise_not(blue_mask_green))
    combined_mask_red = cv2.bitwise_and(red_mask, cv2.bitwise_not(blue_mask_red))
    # combined_mask_black = cv2.bitwise_and(black_mask, cv2.bitwise_not(blue_mask_black))
    
    combined_mask = cv2.bitwise_or(combined_mask_green, combined_mask_red)
    combined_mask = cv2.bitwise_or(combined_mask, black_mask)

    # Perform morphological operations to clean up the mask
    kernel = np.ones((5, 5), np.uint8)
    kernel_open = np.ones((2, 2), np.uint8)
    # combined_mask = cv2.morphologyEx(combined_mask_green, cv2.MORPH_OPEN, kernel)
    # combined_mask = cv2.morphologyEx(combined_mask_green, cv2.MORPH_CLOSE, kernel)
    # combined_mask = cv2.dilate(combined_mask, kernel, iterations=1)
    combined_mask = cv2.morphologyEx(combined_mask, cv2.MORPH_OPEN, kernel_open, iterations=1)
    combined_mask = cv2.dilate(combined_mask, kernel, iterations=1)
    
    return combined_mask

def is_u_shaped_convexity(contour, frame):
    margin = 50

    # Check if contour is large enough for convexity defect calculation
    if len(contour) < 4:
        return False

    # Calculate the convex hull of the contour
    hull = cv2.convexHull(contour, returnPoints=False)

    # Find the convexity defects, which are the 'gaps' in the convex hull
    try:
        defects = cv2.convexityDefects(contour, hull)
    except cv2.error as e:
        print("Error calculating convexity defects:", e)
        return False
    
    if defects is not None and defects.shape[0] > 0:
        # Count the number of defects (gaps in the convex hull)
        valid_defects = 0

        for i in range(defects.shape[0]):
            s, e, f, d = defects[i, 0]
            start = tuple(contour[s][0])
            end = tuple(contour[e][0])
            far = tuple(contour[f][0])

            # Ensure the defect points are not too close to the edge
            if (start[0] <= margin or start[1] <= margin or
                end[0] <= margin or end[1] <= margin or
                far[0] <= margin or far[1] <= margin or
                start[0] >= frame.shape[1] - margin or start[1] >= frame.shape[0] - margin or
                end[0] >= frame.shape[1] - margin or end[1] >= frame.shape[0] - margin or
                far[0] >= frame.shape[1] - margin or far[1] >= frame.shape[0] - margin):
                continue
            
            # Normalize the defect depth by the bounding box area
            # normalized_d = float(d) / bounding_box_area

            # We can use the depth of the defect (d) to filter out small defects
            # if normalized_d > 0.92:  # This threshold may need to be adjusted
            if d > 20000:
                valid_defects += 1
                
                # Optional: draw the defect on the frame for visualization
                cv2.line(frame, start, end, [255, 0, 0], 2)
                # cv2.circle(frame, far, 5, [0, 0, 255], -1)
        
        # If there're more than one valid defects, it might be a U-shape
        if valid_defects >= 1:
            return True

    return False

def determine_thruster_direction(normalized_x):
    """Determines the direction for the thruster based on normalized x position."""
    if normalized_x < 0.35:
        return 'Left'
    elif normalized_x > 0.65:
        return 'Right'
    else:
        return 'Forward'

def determine_buoyancy(normalized_y):
    """Determines the buoyancy direction based on normalized y position."""
    if normalized_y < 0.38:
        return 'Up'
    elif normalized_y > 0.62:
        return 'Down'
    else:
        return 'Neutral'

def determine_direction(center_x, center_y, frame_width, frame_height):
    normalized_x = center_x / frame_width
    normalized_y = center_y / frame_height

    buoyancy_direction = determine_buoyancy(normalized_y)
    thruster_direction = determine_thruster_direction(normalized_x)

    return buoyancy_direction, thruster_direction


#Process the frame and update tracker
def process_and_update(frame, lost_tracking_threshold, lost_tracking_counter, tracking, tracker, false_counter):
    buoyancy_direction = 'None'
    thruster_direction = 'None'
    #frame = cv2.resize(frame, (640, 480))
    combined_mask = color_mask(frame)

    # Find contours in the mask image
    # cv2.CHAIN_APPROX_NONE stores all the boundary points and is more accurate in contour approximation but need more computation power
    # cv2.CHAIN_APPROX_SIMPLE stores only the end points of the boundary points and is less accurate but faster
    contours, _ = cv2.findContours(combined_mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    #print(tracking)
    # Your logic to select an object to track, e.g., based on size or shape
    for contour in contours:
        
        area = cv2.contourArea(contour)
        # Get the bounding box of the contour
        if 100 < area < 47000:
            x, y, w, h = cv2.boundingRect(contour)
            aspect_ratio = float(w/h)
            if 0.2 < aspect_ratio < 1:   
                gate_shape_detected = is_u_shaped_convexity(contour, frame)  
                print("status: ",gate_shape_detected)             
                if gate_shape_detected:  # Example condition
                    false_counter = 0
                    # Initialize tracker with the selected object
                    tracker = cv2.TrackerKCF_create()
                    tracker.init(frame, (x, y, w, h))
                    tracking = True
                    #gate_position = []
                    break
                else:
                    false_counter += 1
                    if false_counter >= 10:
                        tracking = False
                        #print("False counter reached 10!!!")
                        break
    if tracker is not None:
        # Update tracker and get new position of the object
        success, box = tracker.update(frame)

        if success and tracking:
            lost_tracking_counter = 0
            x, y, w, h = [int(v) for v in box]
            center_x = x + w / 2
            center_y = y + h / 2
            buoyancy_direction, thruster_direction = determine_direction(center_x, center_y, 640, 480)
            cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)
            cv2.putText(frame, "Gate", (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
            #cv2.circle(frame, (int(x + w / 2), int(y + h / 2)), 5, (0, 0, 255), -1)
            
        else:
            if lost_tracking_counter <= lost_tracking_threshold:
                # Draw rectangle for a few frames after tracking is lost
                x, y, w, h = [int(v) for v in box]  # Use last known position
                cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)
                print('drawing blue box!!!')
            lost_tracking_counter += 1  # Increment counter on tracking failure

    return frame, combined_mask, tracking, tracker, lost_tracking_counter, false_counter, buoyancy_direction, thruster_direction
