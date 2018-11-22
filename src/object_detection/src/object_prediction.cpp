#include "object_prediction.h"
#include <custom_msgs/ImagesAndBoxes.h>
#include <ros/ros.h>

using namespace custom_msgs;

const custom_msgs::ImagesAndBoxes ObjectPrediction::performPrediction(const ImagesAndBoxes& currImgBoxes, const ImagesAndBoxes& lastImgBoxes, const Action& lastAction) const {
	ROS_INFO("Performing Prediction");
	return currImgBoxes;
}
