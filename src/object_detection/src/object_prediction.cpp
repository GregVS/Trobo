#include "object_prediction.h"
#include <custom_msgs/ImagesAndBoxes.h>
#include <ros/ros.h>

using namespace custom_msgs;

const custom_msgs::ImagesAndBoxes ObjectPrediction::performPrediction(const ImagesAndBoxes& currImgBoxes, const ImagesAndBoxes& lastImgBoxes, const Action& lastAction) const {
	ROS_INFO("Performing Prediction");
	std::vector<Box> predictedBoxes;
	for (auto& box : lastImgBoxes.top_img_boxes) {
	    Box prediction;

	}
	return currImgBoxes;
}



// 1, 2, 3, 4, 9, 10 for still markers
// after 1 sec full speed, 7.75 in

// 2 feet - 0px - B
// 3 feet - 85px - C
// INF - 277px - A