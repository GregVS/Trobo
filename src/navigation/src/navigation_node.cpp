#include "ros/ros.h"
#include <std_srvs/Empty.h>
#include <custom_msgs/ImagesAndBoxesSrv.h>
#include "navigator.h"
#include <optional>

class NavigationNode {

private:
	ros::ServiceClient& netOutClient_;
	ros::Publisher& actionPub_;
	Navigator navigator_;

public:
    explicit NavigationNode(ros::ServiceClient& netOutClient, ros::Publisher& actionPub) :
    	netOutClient_(netOutClient),
    	actionPub_(actionPub) {}

	bool navigate(std_srvs::Empty::Request& req, std_srvs::Empty::Response& res) {
		auto imgAndBoxes = fetchPredictionOutput();
		if(!imgAndBoxes) return false;
		actionPub_.publish(navigator_.chooseNavigationAction(*imgAndBoxes));
		return true;
	}

	std::optional<custom_msgs::ImagesAndBoxes const> fetchPredictionOutput() {
		custom_msgs::ImagesAndBoxesSrv srv;
		if (!netOutClient_.call(srv)) return std::nullopt;
		return { srv.response.result };
	}

};

int main(int argc, char **argv) {
	ros::init(argc, argv, "navigation_node");
	ros::NodeHandle nh;

	ros::service::waitForService("fetch_prediction_output", -1);
	ros::ServiceClient netOutClient = nh.serviceClient<custom_msgs::ImagesAndBoxesSrv>("fetch_prediction_output");
	ros::Publisher actionPub = nh.advertise<custom_msgs::Action>("action_intents", 5);

	NavigationNode navigationNode(netOutClient, actionPub);

	ros::ServiceServer navigationSrv = nh.advertiseService("navigation", &NavigationNode::navigate, &navigationNode);

	ros::spin();
	return 0;
}