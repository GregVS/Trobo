#!/usr/bin/env python
import rospy
from custom_msgs.msg import RobotImages
from cv_bridge import CvBridge
import cv2

bridge = CvBridge()

def callback(data):
    # the recieved image must be in rgb format
    cv_bot_img = bridge.imgmsg_to_cv2(data.bot_img, 'rgb8')
    cv_top_img = bridge.imgmsg_to_cv2(data.top_img, 'rgb8')
    # the rgb image has to be converted to bgr for display
    bgr_bot_img = cv_bot_img[:,:,::-1]
    bgr_top_img = cv_top_img[:,:,::-1]

    cv2.imshow('bot_img', bgr_bot_img)
    cv2.imshow('top_img', bgr_top_img)
    cv2.waitKey(1)

# setup ros node
def listener():
    rospy.init_node('images_displayer_node', anonymous=True)
    rospy.Subscriber('images', RobotImages, callback)
    rospy.spin()

if __name__ == '__main__':
    listener()
