#!/usr/bin/env python
import os
import tensorflow as tf
import cv2
import rospy

from sensor_msgs.msg import Image
from custom_msgs.msg import ImagesAndBoxes, Box, RobotImages
from cv_bridge import CvBridge
from object_detection.utils import label_map_util

# Name of the folder that contains the model
MODEL_NAME = 'paper_model'

# Path to the graph which is the actual trained model
PATH_TO_CKPT = '/home/greg/trobo/' + MODEL_NAME + '/frozen_inference_graph.pb'

# List of the labels
PATH_TO_LABELS = os.path.join('/home/greg/trobo/paper_model/data', 'object-detection.pbtxt')

NUM_CLASSES = 1

cvbridge = CvBridge()

# Load the frozen model into memory
detection_graph = tf.Graph()
with detection_graph.as_default():
	od_graph_def = tf.GraphDef()
	with tf.gfile.GFile(PATH_TO_CKPT, 'rb') as fid:
		serialized_graph = fid.read()
		od_graph_def.ParseFromString(serialized_graph)
		tf.import_graph_def(od_graph_def, name='')

# Load the label map
label_map = label_map_util.load_labelmap(PATH_TO_LABELS)
categories = label_map_util.convert_label_map_to_categories(label_map, max_num_classes=NUM_CLASSES, use_display_name=True)
category_index = label_map_util.create_category_index(categories)

def load_image_into_numpy_array(img):
	new_img = cv2.resize(img, (300, 300))
	return new_img.reshape(1, new_img.shape[0], new_img.shape[1], 3)

def run_network_for_img(cv_img, sess):
	# Run the model
    return sess.run([sess.graph.get_tensor_by_name('num_detections:0'),
		sess.graph.get_tensor_by_name('detection_scores:0'),
		sess.graph.get_tensor_by_name('detection_boxes:0'),
		sess.graph.get_tensor_by_name('detection_classes:0')],
		feed_dict={'image_tensor:0': load_image_into_numpy_array(cv_img)})

def get_detection_boxes(out):
	# get the detected bounding boxes and return them
    detection_boxes = []
    num_detections = int(out[0][0])
    for i in range(num_detections):
        classId = int(out[3][0][i]) # TODO possible check to make sure the id is correct
        score = float(out[1][0][i])
        bbox = [float(v) for v in out[2][0][i]]
        if score > 0.3:
			# make origin in center of image
            left = bbox[1] - 0.5
            top = -(bbox[0] - 0.5)
            right = bbox[3] - 0.5
            bottom = -(bbox[2] - 0.5)
            detection_boxes.append((left, top, right, bottom))
    return detection_boxes

def serialize_boxes(box_tuple_list):
	boxes = []
	for box in box_tuple_list:
		sbox = Box()
		sbox.left = box[0]
		sbox.top = box[1]
		sbox.right = box[2]
		sbox.bottom = box[3]
		boxes.append(sbox)
	return boxes

def serialize_result(bot_img_boxes, top_img_boxes, robot_imgs):
	out_img = ImagesAndBoxes()
	out_img.bot_img = robot_imgs.bot_img
	out_img.top_img = robot_imgs.top_img
	
	out_img.bot_img_boxes = serialize_boxes(bot_img_boxes)
	out_img.top_img_boxes = serialize_boxes(top_img_boxes)
	return out_img

def process_and_publish(robot_imgs, sess, pub):
	bot_img_out = run_network_for_img(cvbridge.imgmsg_to_cv2(robot_imgs.bot_img), sess)
	bot_img_boxes = get_detection_boxes(bot_img_out)

	top_img_out = run_network_for_img(cvbridge.imgmsg_to_cv2(robot_imgs.top_img), sess)
	top_img_boxes = get_detection_boxes(top_img_out)

	net_out_imgs = serialize_result(bot_img_boxes, top_img_boxes, robot_imgs)
	pub.publish(net_out_imgs)

def setup_listener():
	with detection_graph.as_default():
		with tf.Session() as sess:
			rospy.init_node('tensorflow_node', anonymous=True)
			pub = rospy.Publisher('network_out_imgs', ImagesAndBoxes, queue_size=1)
			rospy.Subscriber('images', RobotImages, lambda robot_imgs: process_and_publish(robot_imgs, sess, pub))
			rospy.loginfo('Tensorflow node setup...')
			rospy.spin()

if __name__ == '__main__':
	setup_listener()
