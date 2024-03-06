import cv2
import numpy as np

def main():
    # 通过摄像头索引号来指定要使用的摄像头，通常第一个摄像头索引号是0
    cap = cv2.VideoCapture(0)

    # 检查摄像头是否成功打开
    if not cap.isOpened():
        print("无法打开摄像头")
        return

    while True:
        # 读取一帧的数据
        ret, frame = cap.read()

        # 检查是否成功读取了帧
        if not ret:
            print("无法接收帧")
            break

        # 获取视频帧的高度和宽度
        height, width = frame.shape[:2]

        # 定义中心矩形的宽度和高度
        rect_width = 400
        rect_height = 300

        # 计算中心矩形的左上角和右下角坐标
        x1 = int((width - rect_width) / 2)
        y1 = int((height - rect_height) / 2)
        x2 = x1 + rect_width
        y2 = y1 + rect_height

        # 在帧上绘制矩形
        cv2.rectangle(frame, (x1, y1), (x2, y2), (255, 255, 255), 2)

        # 获取中心矩形内的区域
        roi = frame[y1:y2, x1:x2]

        # 转换图像颜色空间为HSV
        hsv_roi = cv2.cvtColor(roi, cv2.COLOR_BGR2HSV)
    

        # 定义绿色的HSV范围
        lower_green = np.array([36, 25, 25])
        upper_green = np.array([75, 255, 255])
        
        # 定义红色的HSV范围
        lower_red1 = np.array([0, 70, 50])    # 红色的H值范围在0到30之间
        upper_red1 = np.array([30, 255, 255])

        lower_red2 = np.array([150, 70, 50])  # 红色的H值范围在150到180之间
        upper_red2 = np.array([180, 255, 255])

        # 组合两个范围，考虑红色跨越了0度边界
        lower_red = np.array([lower_red1, lower_red2])
        upper_red = np.array([upper_red1, upper_red2])

        # 创建绿色的掩码
        mask = cv2.inRange(hsv_roi, lower_green, upper_green)
        
        # 创建绿色的掩码
        mask2 = cv2.inRange(hsv_roi, lower_red[0], upper_red[0]) + cv2.inRange(hsv_roi, lower_red[1], upper_red[1])

        # 计算绿色像素的比例
        green_pixels = cv2.countNonZero(mask)
        total_pixels = rect_width * rect_height
        green_ratio = green_pixels / total_pixels * 100
        
        # 计算紅色像素的比例
        red_pixels = cv2.countNonZero(mask2)
        total_pixels = rect_width * rect_height
        red_ratio = red_pixels / total_pixels * 100

        # 在帧上显示绿色比例
        cv2.putText(frame, f'Green ratio: {green_ratio:.2f}%', (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
        
        # 在帧上显示紅色比例
        cv2.putText(frame, f'Red ratio: {red_ratio:.2f}%', (10, 70), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)

        # 显示帧
        cv2.imshow('Frame', frame)

        # 按下 'q' 键退出循环
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # 释放摄像头资源并关闭所有窗口
    cap.release()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()

