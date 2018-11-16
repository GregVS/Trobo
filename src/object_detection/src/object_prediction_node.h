#include "ros/ros.h"
#include <custom_msgs/ImagesAndBoxes.h>
#include <custom_msgs/Action.h>
#include "object_prediction.h"

#include <memory>

class ObjectPredictionNode {

private:
	ros::Publisher outputPub_;
	ObjectPrediction objPrediction_;

	ros::ServiceClient netOutClient_;
	ros::ServiceClient actionClient_;

	std::unique_ptr<ros::NodeHandle> nodeHandle_;

public:
	ObjectPredictionNode(int argc, char**argv);

	void executePredictionForOutput(const custom_msgs::ImagesAndBoxes::ConstPtr& msg);
	void run();

	custom_msgs::ImagesAndBoxes::ConstPtr lastNetworkOutput();
	custom_msgs::Action::ConstPtr lastActionOutput();

};