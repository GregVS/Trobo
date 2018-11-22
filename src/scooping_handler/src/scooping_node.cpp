#include "ros/ros.h"
#include <std_srvs/Empty.h>
#include <custom_msgs/ImagesAndBoxesSrv.h>
#include <custom_msgs/Action.h>
#include <boost/shared_ptr.hpp>
#include <vector>
#include <optional>

class ScoopingNode {

private:
	ros::ServiceClient& predictionClient_;
	ros::Publisher& actionPub_;

	std::optional<custom_msgs::ImagesAndBoxes const> fetchLastNetworkOutput() const {
		custom_msgs::ImagesAndBoxesSrv srv;
		if(!predictionClient_.call(srv)) return std::nullopt;
		return { srv.response.result };
	}

public:
	ScoopingNode(ros::ServiceClient& predictionClient, ros::Publisher& actionPub): predictionClient_(predictionClient), actionPub_(actionPub) {}

	bool handleScooping(std_srvs::Empty::Request& req, std_srvs::Empty::Response& res) {
		auto lastNetOut = fetchLastNetworkOutput();
		if (!lastNetOut || lastNetOut->bot_img_boxes.empty()) return false;
		for (auto const& box : lastNetOut->bot_img_boxes) {
			if (box.left < 0.1 || box.right > 0.9) return false;
		}

		// signal that you want to scoop up the trash

		custom_msgs::Action action;
		action.id = 0;
		actionPub_.publish(action);
		return true;
	}

};

int main(int argc, char **argv) {
	ros::init(argc, argv, "scooping_node");
	ros::NodeHandle nh;

	ros::service::waitForService("fetch_prediction_output", -1);

	ros::ServiceClient predictionClient = nh.serviceClient<custom_msgs::ImagesAndBoxesSrv>("fetch_prediction_output");


	ros::Publisher actionPub = nh.advertise<custom_msgs::Action>("action_intents", 5);

	ScoopingNode scoopingNode(predictionClient, actionPub);

	ros::ServiceServer scoopingSrv = nh.advertiseService("handle_scooping", &ScoopingNode::handleScooping, &scoopingNode);

	ros::spin();

	return 0;
}