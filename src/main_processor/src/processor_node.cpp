#include "ros/ros.h"
#include <std_srvs/Empty.h>

int main(int argc, char **argv) {
	ros::init(argc, argv, "processor_node");

	ros::NodeHandle nh;
	ros::Rate updateRate(10); 

	ros::ServiceClient scoopingClient = nh.serviceClient<std_srvs::Empty>("handle_scooping");

	while(ros::ok()) {
		ROS_INFO("ROS is running");

		// Check if any scooping should take place
		std_srvs::Empty empty;
		scoopingClient.call(empty);

		ros::spinOnce();
		updateRate.sleep();
	}
	
	return 0;
}