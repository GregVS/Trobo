#include "object_prediction.h"
#include <custom_msgs/ImagesAndBoxes.h>
#include <ros/ros.h>

custom_msgs::ImagesAndBoxes ObjectPrediction::performPrediction(ImagesAndBoxesPtr& currImgBoxes, ImagesAndBoxesPtr& lastImgBoxes, ActionPtr& lastAction) {
	ROS_INFO("Performing Prediction");
}
