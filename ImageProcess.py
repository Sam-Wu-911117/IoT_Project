import cv2
import numpy as np

def main():
    # open camera
    cap = cv2.VideoCapture(0)

    # checked is opensd
    if not cap.isOpened():
        print("camera open failed")
        return

    while True:
        # read frame
        ret, frame = cap.read()

        # checked read frame
        if not ret:
            print("not get frame")
            break

        # change color space to HSV
        hsv_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

        #Define Green HSV
        lower_green = np.array([36, 25, 25])
        upper_green = np.array([75, 255, 255])

        # create green mask
        mask_green = cv2.inRange(hsv_frame, lower_green, upper_green)

        # Define Red HSV
        lower_red1 = np.array([0, 70, 50])
        upper_red1 = np.array([10, 255, 255])
        lower_red2 = np.array([170, 70, 50])
        upper_red2 = np.array([180, 255, 255])

        # create red mask
        mask_red1 = cv2.inRange(hsv_frame, lower_red1, upper_red1)
        mask_red2 = cv2.inRange(hsv_frame, lower_red2, upper_red2)
        mask_red = cv2.bitwise_or(mask_red1, mask_red2)

        #  compute ratio of green
        green_pixels = cv2.countNonZero(mask_green)
        total_pixels = frame.size // 3  
        green_ratio = green_pixels / total_pixels * 100

        # compute ratio of red
        red_pixels = cv2.countNonZero(mask_red)
        red_ratio = red_pixels / total_pixels * 100

        # show ratio of green on frame
        cv2.putText(frame, f'Green ratio: {green_ratio:.2f}%', (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

        #  show ratio of red on frame
        cv2.putText(frame, f'Red ratio: {red_ratio:.2f}%', (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)

        # show frame
        cv2.imshow('Frame', frame)

        # press 'q' to quit 
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # close all windows
    cap.release()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()