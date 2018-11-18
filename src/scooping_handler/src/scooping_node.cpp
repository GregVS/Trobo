#include "ros/ros.h"
#include <std_srvs/Empty.h>
#include <custom_msgs/NetworkOutputSrv.h>
#include <custom_msgs/Action.h>
#include <boost/shared_ptr.hpp>
#include <vector>

class ScoopingNode {

private:
	ros::ServiceClient& memoryClient_;
	ros::Publisher& actionPub_;

	custom_msgs::ImagesAndBoxes::ConstPtr fetchLastNetworkOutput() {
		custom_msgs::NetworkOutputSrv srv;
		if(!memoryClient_.call(srv)) return nullptr;
		return boost::make_shared<custom_msgs::ImagesAndBoxes const>(srv.response.result);
	}

public:
	ScoopingNode(ros::ServiceClient& memoryClient, ros::Publisher& actionPub): memoryClient_(memoryClient), actionPub_(actionPub) {}

	bool handleScooping(std_srvs::Empty::Request& req, std_srvs::Empty::Response& res) {
		auto lastNetOut = fetchLastNetworkOutput();
		ROS_INFO("FETCHED");
		if (lastNetOut == nullptr || lastNetOut->bot_img_boxes.size() == 0) return false;
		ROS_INFO("BUGGED");
		for (auto const& box : lastNetOut->bot_img_boxes) {
			if (box.left < 0.1 || box.right > 0.9) return false;
		}

		// signal that you want to scoop up the trash
		custom_msgs::Action action;
		action.id = 0;
		actionPub_.publish(action);
		ROS_INFO("SUP");
		return true;
	}

};

int main(int argc, char **argv) {
	ros::init(argc, argv, "scooping_node");
	ros::NodeHandle nh;

	ros::ServiceClient memoryClient = nh.serviceClient<custom_msgs::NetworkOutputSrv>("get_last_network_output");
	ros::Publisher actionPub = nh.advertise<custom_msgs::Action>("action_intents", 5);

	ScoopingNode scoopingNode(memoryClient, actionPub);

	ros::ServiceServer scoopingSrv = nh.advertiseService("handle_scooping", &ScoopingNode::handleScooping, &scoopingNode);

	ros::spin();

	return 0;
}