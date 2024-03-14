import cv2
import numpy as np

def color_mask(frame):
    # Convert the BGR image to L*a*b* color space
    lab_image = cv2.cvtColor(frame, cv2.COLOR_BGR2LAB)
    #lab_image = cv2.GaussianBlur(lab_image, (5, 5), 0)

    '''Color thresholding'''
    # Define the range for green colors in the L*a*b* color space
    # Note: these ranges are approximate and may require tuning
    lower_red = np.array([0, 120, 0])  # Lower bound of red in L*a*b* space
    upper_red = np.array([180, 255, 255])  # Upper bound of red in L*a*b* space
    red_mask = cv2.inRange(lab_image, lower_red, upper_red)

    lower_blue_red = np.array([0, 0, 0])  # Lower bound of blue in L*a*b* space
    upper_blue_red = np.array([255, 255, 115])  # Upper bound of blue in L*a*b* space
    blue_mask_red = cv2.inRange(lab_image, lower_blue_red, upper_blue_red)

    combined_mask_red = cv2.bitwise_and(red_mask, cv2.bitwise_not(blue_mask_red))
    # Perform morphological operations to clean up the mask
    kernel = np.ones((5, 5), np.uint8)
    kernel_open = np.ones((2, 2), np.uint8)
    # combined_mask = cv2.morphologyEx(combined_mask_green, cv2.MORPH_OPEN, kernel)
    # combined_mask = cv2.morphologyEx(combined_mask_green, cv2.MORPH_CLOSE, kernel)
    # combined_mask = cv2.dilate(combined_mask, kernel, iterations=1)
    combined_mask_red = cv2.morphologyEx(combined_mask_red, cv2.MORPH_OPEN, kernel_open, iterations=1)
    # combined_mask = cv2.dilate(combined_mask, kernel, iterations=1)
    
    return combined_mask_red

def drum_detect(frame):
    combined_mask = color_mask(frame)

    # Find contours in the thresholded image
    contours, _ = cv2.findContours(combined_mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
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
            try:
                aspect_ratio = max(w, h) / min(w, h)
            except ZeroDivisionError:
                continue

            if 100 < area < 7000:
                #cv2.putText(frame, str(round(aspect_ratio, 2)), (int(x), int(y)), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2, cv2.LINE_AA)
                if 1 < aspect_ratio < 2:
                    print('Drum detected!')
                    # Draw the rectangle
                    tracking = True
                    cv2.drawContours(frame, [box], 0, (0, 255, 0), 2)
                    cv2.putText(frame, 'Drum', (int(x), int(y-10)), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2, cv2.LINE_AA)

    return frame, combined_mask, tracking