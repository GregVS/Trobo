#include "object_prediction.h"
#include <custom_msgs/ImagesAndBoxes.h>
#include <ros/ros.h>
#include "perspective/perspective.h"

using namespace custom_msgs;

const custom_msgs::ImagesAndBoxes ObjectPrediction::performPrediction(const ImagesAndBoxes& currImgBoxes, const ImagesAndBoxes& lastImgBoxes, const Action& lastAction) const {
	ROS_INFO("Performing Prediction");
	std::vector<Box> predictedBoxes;
	for (auto& box : lastImgBoxes.top_img_boxes) {
	    Box prediction;

	}
	return currImgBoxes;
}

std::pair<double, double> ObjectPrediction::predictPosition(const custom_msgs::Box &box) const {
	double x = (box.left + box.right) / 2.0;
	double y = (box.top + box.bottom) / 2.0;
	auto worldCoords = perspective::screenToWorld(x, y);
    // TODO
}



// after 1 sec full speed, 7.75 in
