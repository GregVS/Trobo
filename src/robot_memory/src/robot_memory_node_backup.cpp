#include "ros/ros.h"
#include "memory_bucket.h"
#include <custom_msgs/ImagesAndBoxesSrv.h>
#include <custom_msgs/ActionSrv.h>

#include <memory>

class MemoryNode {

public:
    explicit MemoryNode(RobotMemory& robotMemory) : robotMemory_(robotMemory) {}

	bool fetchNetworkOutputSrv(custom_msgs::ImagesAndBoxesSrv::Request& req, custom_msgs::ImagesAndBoxesSrv::Response& res) {
		auto output = robotMemory_.fetchNetworkOutput(req.skips);
		if (output == nullptr) return false;
		res.result = *output;
		return true;
	}

	bool fetchActionSrv(custom_msgs::ActionSrv::Request& req, custom_msgs::ActionSrv::Response& res) {
		auto action = robotMemory_.fetchAction(req.skips);
		if (action == nullptr) return false;
		res.result = *action;
		return true;
	}

	bool fetchPredictionOutputSrv(custom_msgs::ImagesAndBoxesSrv::Request& req, custom_msgs::ImagesAndBoxesSrv::Response& res) {
		auto output = robotMemory_.fetchPredictionOutput(req.skips);
		if (output == nullptr) return false;
		res.result = *output;
		return true;
	}

private:
	RobotMemory& robotMemory_;

};

int main(int argc, char **argv) {

	RobotMemory robotMemory;
	MemoryNode memoryNode(robotMemory);

	ros::init(argc, argv, "memory_node");
	ros::NodeHandle nh;

		// setup subscribers to store data in memory
	ros::Subscriber netOutputSub = nh.subscribe("network_out_imgs", 5, &RobotMemory::storeNetworkOutput, &robotMemory);
	ros::Subscriber actionSub = nh.subscribe("dispatched_actions", 5, &RobotMemory::storeAction, &robotMemory);
	ros::Subscriber predictionSub = nh.subscribe("prediction_output", 5, &RobotMemory::storePredictionOutput, &robotMemory);

		// setup services
	ros::ServiceServer fetchNetOutput = nh.advertiseService("fetch_network_output", &MemoryNode::fetchNetworkOutputSrv, &memoryNode);
	ros::ServiceServer fetchAction = nh.advertiseService("fetch_action", &MemoryNode::fetchActionSrv, &memoryNode);
	ros::ServiceServer fetchPredictionOut = nh.advertiseService("fetch_prediction_output", &MemoryNode::fetchPredictionOutputSrv, &memoryNode);

	ros::spin();

	return 0;
}