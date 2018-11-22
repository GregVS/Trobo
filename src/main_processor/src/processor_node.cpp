#include "ros/ros.h"
#include <std_srvs/Empty.h>

int main(int argc, char **argv) {
	ros::init(argc, argv, "processor_node");

	ros::NodeHandle nh;
	ros::Rate updateRate(10); 

	ros::service::waitForService("handle_scooping", -1);
	ros::service::waitForService("navigation", -1);
	ros::service::waitForService("dispatch_action", -1);

	ros::ServiceClient scoopingClient = nh.serviceClient<std_srvs::Empty>("handle_scooping");
	ros::ServiceClient navigationClient = nh.serviceClient<std_srvs::Empty>("navigation");
	ros::ServiceClient actionDispatcherClient = nh.serviceClient<std_srvs::Empty>("dispatch_action");

	ROS_INFO("ROS is running");
	while(ros::ok()) {

		// Check if any scooping should take place
		std_srvs::Empty empty;
		scoopingClient.call(empty);
		navigationClient.call(empty);
        actionDispatcherClient.call(empty);

		ros::spinOnce();
		updateRate.sleep();
	}
	
	return 0;
}