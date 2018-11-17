#include "ros/ros.h"
#include <custom_msgs/ImagesAndBoxes.h>
#include <custom_msgs/Action.h>
#include "object_prediction.h"

#include <memory>

class ObjectPredictionNode {

private:
	ros::Publisher& outputPub_;
	ObjectPrediction objPrediction_;

	ros::ServiceClient& netOutClient_;
	ros::ServiceClient& actionClient_;

public:
	ObjectPredictionNode(ros::ServiceClient& netOutClient, ros::ServiceClient& actionClient, ros::Publisher& outputPub):
		netOutClient_(netOutClient), actionClient_(actionClient), outputPub_(outputPub) {}

	void executePredictionForOutput(const custom_msgs::ImagesAndBoxes::ConstPtr& msg);
	void run();

	custom_msgs::ImagesAndBoxes::ConstPtr lastNetworkOutput();
	custom_msgs::Action::ConstPtr lastActionOutput();

};