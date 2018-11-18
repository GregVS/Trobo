#include "ros/ros.h"
#include "object_prediction_node.h"

//include services
#include <custom_msgs/ImagesAndBoxesSrv.h>
#include <custom_msgs/ActionSrv.h>

#include <boost/shared_ptr.hpp>

void ObjectPredictionNode::executePredictionForOutput(const custom_msgs::ImagesAndBoxes::ConstPtr& currNetOut) {
	// call the services and get the latest data
	custom_msgs::ImagesAndBoxes::ConstPtr lastNetOut = prevNetworkOutput();
	custom_msgs::Action::ConstPtr lastAction = prevActionOutput();

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
custom_msgs::ImagesAndBoxes::ConstPtr ObjectPredictionNode::prevNetworkOutput() {
	custom_msgs::ImagesAndBoxesSrv srv;
	srv.request.skips = 1;
	if (!netOutClient_.call(srv)) return nullptr;
	return boost::make_shared<custom_msgs::ImagesAndBoxes const>(srv.response.result);
}

// Calls the memory service to get the last action sent to the robot
custom_msgs::Action::ConstPtr ObjectPredictionNode::prevActionOutput() {
	custom_msgs::ActionSrv srv;
	srv.request.skips = 1;
	if (!actionClient_.call(srv)) return nullptr;
	return boost::make_shared<custom_msgs::Action const>(srv.response.result);
}

int main(int argc, char **argv) {

	ros::init(argc, argv, "object_prediction_node");
	ros::NodeHandle nh;

	ros::service::waitForService("fetch_network_output", -1);
	ros::ServiceClient netOutClient = nh.serviceClient<custom_msgs::ImagesAndBoxesSrv>("fetch_network_output");

	ros::service::waitForService("fetch_action", -1);
	ros::ServiceClient actionClient = nh.serviceClient<custom_msgs::ActionSrv>("fetch_action");

	// publish the final boxes
	ros::Publisher outputPub =  nh.advertise<custom_msgs::ImagesAndBoxes>("prediction_output", 10);

	ObjectPredictionNode objPredictionNode(netOutClient, actionClient, outputPub);

	ros::Subscriber netOutSub = nh.subscribe("network_out_imgs", 2, &ObjectPredictionNode::executePredictionForOutput, &objPredictionNode);

	ROS_INFO("Obj Prediction Node Running...");

	ros::spin();
	
	return 0;
}