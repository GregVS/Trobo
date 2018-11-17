#include "ros/ros.h"
#include "object_prediction_node.h"

//include services
#include <custom_msgs/NetworkOutputSrv.h>
#include <custom_msgs/ActionSrv.h>

#include <boost/shared_ptr.hpp>

void ObjectPredictionNode::executePredictionForOutput(const custom_msgs::ImagesAndBoxes::ConstPtr& currNetOut) {
	// call the services and get the latest data
	custom_msgs::ImagesAndBoxes::ConstPtr lastNetOut = lastNetworkOutput();
	custom_msgs::Action::ConstPtr lastAction = lastActionOutput();

	// if either were unattainable then do not perform any prediction
	if (lastAction == nullptr || lastNetOut == nullptr) {
		outputPub_.publish(*currNetOut);
		return;
	}

	// run the prediction
	custom_msgs::ImagesAndBoxes imgBoxes = objPrediction_.performPrediction(currNetOut, lastNetOut, lastAction);
	ROS_INFO("HI");
	outputPub_.publish(imgBoxes);
}


// Calls the memory service to get the last network output
custom_msgs::ImagesAndBoxes::ConstPtr ObjectPredictionNode::lastNetworkOutput() {
	custom_msgs::NetworkOutputSrv srv;
	if (!netOutClient_.call(srv)) return nullptr;
	return boost::make_shared<custom_msgs::ImagesAndBoxes const>(srv.response.result);
}

// Calls the memory service to get the last action sent to the robot
custom_msgs::Action::ConstPtr ObjectPredictionNode::lastActionOutput() {
	custom_msgs::ActionSrv srv;
	if (!actionClient_.call(srv)) return nullptr;
	return boost::make_shared<custom_msgs::Action const>(srv.response.result);
}

int main(int argc, char **argv) {

	ros::init(argc, argv, "object_prediction_node");
	ros::NodeHandle nh;

	ros::ServiceClient netOutClient = nh.serviceClient<custom_msgs::NetworkOutputSrv>("get_last_network_output");
	ros::ServiceClient actionClient = nh.serviceClient<custom_msgs::ActionSrv>("get_last_action");
	ros::Publisher outputPub =  nh.advertise<custom_msgs::ImagesAndBoxes>("prediction_output", 10);

	ObjectPredictionNode objPredictionNode(netOutClient, actionClient, outputPub);

	ros::Subscriber netOutSub = nh.subscribe("network_out_imgs", 2, &ObjectPredictionNode::executePredictionForOutput, &objPredictionNode);

	ros::spin();
	
	return 0;
}