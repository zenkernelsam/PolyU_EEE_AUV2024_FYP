import cv2
import numpy as np

def color_mask(frame):
    # Convert the BGR image to L*a*b* color space
    lab_image = cv2.cvtColor(frame, cv2.COLOR_BGR2LAB)
    #lab_image = cv2.GaussianBlur(lab_image, (5, 5), 0)

    '''Color thresholding'''
    # Define the range for green colors in the L*a*b* color space
    # Note: these ranges are approximate and may require tuning
    lower_orange = np.array([0, 120, 120])  # Lower bound of green in L*a*b* space
    upper_orange = np.array([255, 255, 255])  # Upper bound of green in L*a*b* space
    orange_mask = cv2.inRange(lab_image, lower_orange, upper_orange)

    # Perform morphological operations to clean up the mask
    kernel = np.ones((5, 5), np.uint8)
    kernel_open = np.ones((2, 2), np.uint8)
    # combined_mask = cv2.morphologyEx(combined_mask_green, cv2.MORPH_OPEN, kernel)
    # combined_mask = cv2.morphologyEx(combined_mask_green, cv2.MORPH_CLOSE, kernel)
    # combined_mask = cv2.dilate(combined_mask, kernel, iterations=1)
    orange_mask = cv2.morphologyEx(orange_mask, cv2.MORPH_OPEN, kernel_open, iterations=1)
    # combined_mask = cv2.dilate(combined_mask, kernel, iterations=1)
    
    return orange_mask

def determine_thruster_direction(normalized_x):
    """Determines the direction for the thruster based on normalized x position."""
    if 0.5 < normalized_x < 0.85:
        return 'Left'
    elif 0.15 < normalized_x <= 0.5:
        return 'Right'
    else:
        return 'Forward'
    
def determine_direction(center_x, frame_width):
    normalized_x = center_x / frame_width

    thruster_direction = determine_thruster_direction(normalized_x)

    return thruster_direction

def flare_detect(frame, tracking):
    thruster_direction = 'None'
    # Apply your color mask
    combined_mask = color_mask(frame)

    # Find contours in the thresholded image
    contours, _ = cv2.findContours(combined_mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    if contours:
        for contour in contours:
            area = cv2.contourArea(contour)
            # Fit a minimum area rectangle
            rect = cv2.minAreaRect(contour)
            box = cv2.boxPoints(rect)
            box = np.int0(box)
            
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
            
            if area > 100:
                if aspect_ratio > 10 and 87 < angle < 93:
                    print('Flare detected!')
                    # Draw the rectangle
                    cv2.drawContours(frame, [box], 0, (0, 255, 0), 2)
                    cv2.putText(frame, 'Flare', (int(x), int(y-10)), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2, cv2.LINE_AA)
                    cv2.circle(frame, (int(x), int(y)), 5, (0, 0, 255), -1)
                    tracking = True
                    thruster_direction = determine_direction(x, frame.shape[1])

    return frame, combined_mask, tracking, thruster_direction