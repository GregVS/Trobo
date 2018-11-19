#include "ros/ros.h"
#include <std_srvs/Empty.h>
#include <custom_msgs/ImagesAndBoxesSrv.h>
#include "navigator.h"
#include <memory>

class NavigationNode {

private:
	ros::ServiceClient& netOutClient_;
	Navigator navigator_;

public:
    explicit NavigationNode(ros::ServiceClient& netOutClient): netOutClient_(netOutClient) {}

	bool navigate(std_srvs::Empty::Request& req, std_srvs::Empty::Response& res) {
		auto imgAndBoxes = fetchPredictionOutput();
		if(!imgAndBoxes) return false;
		navigator_.navigate(*imgAndBoxes);
		return true;
	}

	std::unique_ptr<custom_msgs::ImagesAndBoxes const> fetchPredictionOutput() {
		custom_msgs::ImagesAndBoxesSrv srv;
		if (!netOutClient_.call(srv)) return nullptr;
		return std::make_unique<custom_msgs::ImagesAndBoxes const>(srv.response.result);
	}

};

int main(int argc, char **argv) {
	ros::init(argc, argv, "navigation_node");
	ros::NodeHandle nh;

	ros::service::waitForService("fetch_prediction_output", -1);
	ros::ServiceClient netOutClient = nh.serviceClient<custom_msgs::ImagesAndBoxesSrv>("fetch_prediction_output");

	NavigationNode navigationNode(netOutClient);

	ros::ServiceServer navigationSrv = nh.advertiseService("navigation", &NavigationNode::navigate, &navigationNode);

	return 0;
}