#include "ros/ros.h"
#include "object_prediction_node.h"

//include services
#include <custom_msgs/NetworkOutputSrv.h>
#include <custom_msgs/ActionSrv.h>

#include <boost/shared_ptr.hpp>

ObjectPredictionNode::ObjectPredictionNode(int argc, char**argv) {
	ros::init(argc, argv, "object_prediction_node");
	nodeHandle_ = std::make_unique<ros::NodeHandle>();

	netOutClient_ = nodeHandle_->serviceClient<custom_msgs::NetworkOutputSrv>("get_last_network_output");
	actionClient_ = nodeHandle_->serviceClient<custom_msgs::ActionSrv>("get_last_action");

	nodeHandle_->subscribe("network_out_imgs", 2, &ObjectPredictionNode::executePredictionForOutput, this);
	outputPub_ =  nodeHandle_->advertise<custom_msgs::ImagesAndBoxes>("prediction_output", 10);
}

void ObjectPredictionNode::executePredictionForOutput(const custom_msgs::ImagesAndBoxes::ConstPtr& currNetOut) {
	ROS_INFO("SUMMERTIME");
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

void ObjectPredictionNode::run() {
	ROS_INFO("UP");
	ros::spin();
}

int main(int argc, char **argv) {

	ObjectPredictionNode node(argc, argv);
	node.run();
	
	return 0;
}