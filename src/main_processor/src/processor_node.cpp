#include "ros/ros.h"

int main(int argc, char **argv) {
	ros::init(argc, argv, "processor_node");

	ros::NodeHandle nh;
	ros::Rate updateRate(10); 

	while(ros::ok()) {
		ROS_INFO("ROS is running");
		ros::spinOnce();
		updateRate.sleep();
	}
	
	return 0;
}