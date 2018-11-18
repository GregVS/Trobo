#include "ros/ros.h"
#include <std_srvs/Empty.h>
#include <custom_msgs/ImagesAndBoxesSrv.h>

class NavigationNode {

private:
	ros::ServiceClient& netOutClient_;

public:
	NavigationNode(ros::ServiceClient& netOutClient): netOutClient_(netOutClient) {}

	bool navigate(std_srvs::Empty::Request& req, std_srvs::Empty::Response res) {
//		custom_msgs::ImagesAndBoxes imgAndBoxes =
// TODO
		return true;
	}

	custom_msgs::ImagesAndBoxes::ConstPtr fetchNetworkOutput() {
		custom_msgs::ImagesAndBoxesSrv srv;
		if (!netOutClient_.call(srv)) return nullptr;
		return boost::make_shared<custom_msgs::ImagesAndBoxes const>(srv.response.result);
	}

};

int main(int argc, char **argv) {
	ros::init(argc, argv, "navigation_node");
	ros::NodeHandle nh;

	ros::ServiceClient netOutClient = nh.serviceClient<custom_msgs::ImagesAndBoxesSrv>("fetch_prediction_output");

	NavigationNode navigationNode(netOutClient);

	ros::ServiceServer navigationSrv = nh.advertiseService("navigation", &NavigationNode::navigate, &navigationNode);

	return 0;
}