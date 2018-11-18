#!/usr/bin/env python
import rospy
from custom_msgs.msg import ImagesAndBoxes
from cv_bridge import CvBridge
import cv2

bridge = CvBridge()

def show_img(img, boxes, window):
    # the recieved image must be in rgb format
    cv_image = bridge.imgmsg_to_cv2(img, 'rgb8')
    # the rgb image has to be converted to bgr for display
    # bgr_image = cv_image[:,:,::-1]
    bgr_image = cv2.cvtColor(cv_image, cv2.COLOR_RGB2BGR)
    height, width = bgr_image.shape[:2]
    for i in boxes:
        cv2.rectangle(bgr_image, (int(i.left * width), int(i.top*height)), (int(i.right*width), int(i.bottom*height)), (0, 255, 0), 2)
    cv2.imshow(window, bgr_image)
    cv2.waitKey(1)

def callback(data):
    show_img(data.bot_img, data.bot_img_boxes, "bot img")
    show_img(data.top_img, data.top_img_boxes, "top img")

# setup ros node
def listener():
    rospy.init_node('network_output_displayer', anonymous=True)
    rospy.Subscriber('network_out_imgs', ImagesAndBoxes, callback)
    rospy.loginfo('Network output image displayer running...')
    rospy.spin()

if __name__ == '__main__':
    listener()
