import cv2
import numpy as np

def color_mask(frame):
    # Convert the BGR image to L*a*b* color space
    lab_image = cv2.cvtColor(frame, cv2.COLOR_BGR2LAB)
    lab_image = cv2.GaussianBlur(lab_image, (3, 3), 0)
    #gray_image = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    #gray_image = cv2.GaussianBlur(gray_image, (5, 5), 0)

    '''Color thresholding'''
    # Define the range for green colors in the L*a*b* color space
    # Note: these ranges are approximate and may require tuning
    lower_orange = np.array([0, 115, 115])  # Lower bound of green in L*a*b* space
    upper_orange = np.array([190, 255, 255])  # Upper bound of green in L*a*b* space
    orange_mask = cv2.inRange(lab_image, lower_orange, upper_orange)

    # white_lower = np.array([0, 0, 150])
    # white_upper = np.array([255, 95, 255])
    # white_mask = cv2.inRange(hsv_image, white_lower, white_upper)

    # lower_blue_white = np.array([0, 0, 0])  # Lower bound of blue in L*a*b* space
    # upper_blue_white = np.array([240, 255, 125])  # Upper bound of blue in L*a*b* space
    # blue_mask_white = cv2.inRange(lab_image, lower_blue_white, upper_blue_white)

    # Threshold the L*a*b* image to get the green mask
    #_, white_mask = cv2.threshold(gray_image, 150, 255, cv2.THRESH_BINARY)
    #Exclude specular highlights
    # black_mask = cv2.bitwise_and(black_mask, cv2.bitwise_not(high_lightness))
    
    #combined_mask = cv2.bitwise_and(white_mask, cv2.bitwise_not(blue_mask_white))

    # Perform morphological operations to clean up the mask
    kernel = np.ones((5, 5), np.uint8)
    kernel_open = np.ones((2, 2), np.uint8)
    # combined_mask = cv2.morphologyEx(combined_mask_green, cv2.MORPH_OPEN, kernel)
    # combined_mask = cv2.morphologyEx(combined_mask_green, cv2.MORPH_CLOSE, kernel)
    # combined_mask = cv2.dilate(combined_mask, kernel, iterations=1)
    orange_mask = cv2.morphologyEx(orange_mask, cv2.MORPH_OPEN, kernel_open, iterations=1)
    orange_mask= cv2.dilate(orange_mask, kernel, iterations=1)
    
    return orange_mask

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

def determine_distance(contour_data1, contour_data2, frame):
    x_distance = (contour_data1[1] - contour_data2[1])**2
    y_distance = (contour_data1[2] - contour_data2[2])**2
    distance = (x_distance + y_distance)**0.5

    # cv2.line(frame, (int(contour_data1[1]), int(contour_data1[2])), (int(contour_data2[1]), int(contour_data2[2])), (255, 0, 0), 2)
    # cv2.putText(frame, str(round(distance,2)), (int(contour_data1[1]), int(contour_data1[2])-20), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2, cv2.LINE_AA)

    return distance

def q_gate_detect(frame, tracking):
    contour_data = []
    buoyancy_direction = 'None'
    thruster_direction = 'None'

    combined_mask = color_mask(frame)
    
    # Find contours
    contours, _ = cv2.findContours(combined_mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    # Your logic to select an object to track, e.g., based on size or shape
    if contours:
        for contour in contours:
            area = cv2.contourArea(contour)
            # Fit a minimum area rectangle
            rect = cv2.minAreaRect(contour)
            box = cv2.boxPoints(rect)
            box = np.intp(box)
            
            # Analyze the rectangle to determine if it's a long rectangle
            x, y = rect[0]
            w, h = rect[1]
            angle = rect[2]
            if w < h:
                angle += 90

            try:
                aspect_ratio = max(w, h) / min(w, h)
            except ZeroDivisionError:
                continue

            if 100 < area < 2000:
                # cv2.putText(frame, str(round(aspect_ratio,2)), (int(x), int(y)), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2, cv2.LINE_AA)
                if aspect_ratio > 10:
                    contour_data.append((angle, x, y))
                    if len(contour_data) > 2:
                        contour_data.pop(0)  # Remove the oldest entry if there are more than two
                    if len(contour_data) >= 2 and abs(contour_data[0][0] - contour_data[1][0]) < 8 and 100 < determine_distance(contour_data[0], contour_data[1], frame) < 250:
                        #print('Qualification gate detected!') 
                        center_x = (contour_data[0][1] + contour_data[1][1]) / 2
                        center_y = (contour_data[0][2] + contour_data[1][2]) / 2
                        cv2.circle(frame, (int(center_x), int(center_y)), 5, (0, 0, 255), -1)
                        tracking = True
                        buoyancy_direction, thruster_direction = determine_direction(center_x, center_y, 640, 480)
                    # Draw the rectangle
                    cv2.drawContours(frame, [box], 0, (0, 255, 0), 2)
                    #cv2.putText(frame, 'Flare', (int(x), int(y-10)), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2, cv2.LINE_AA)

    return frame, combined_mask, tracking, buoyancy_direction, thruster_direction 
