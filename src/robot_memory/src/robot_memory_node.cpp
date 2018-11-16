#include "ros/ros.h"
#include "robot_memory.h"
#include <custom_msgs/NetworkOutputSrv.h>
#include <custom_msgs/ActionSrv.h>

#include <memory>

class MemoryNode {

public:
	MemoryNode(RobotMemory& robotMemory) : robotMemory_(robotMemory) {}

	bool lastestNetworkOutputSrv(custom_msgs::NetworkOutputSrv::Request& req, custom_msgs::NetworkOutputSrv::Response& res) {
		auto output = robotMemory_.lastNetworkOutput();
		if (output == nullptr) return false;
		res.result = *output;
		return true;
	}

	bool lastActionSrv(custom_msgs::ActionSrv::Request& req, custom_msgs::ActionSrv::Response& res) {
		auto action = robotMemory_.lastAction();
		if (action == nullptr) return false;
		res.result = *action;
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

		// setup services
	ros::ServiceServer lastOutputSrv = nh.advertiseService("get_last_network_output", &MemoryNode::lastestNetworkOutputSrv, &memoryNode);
	ros::ServiceServer lastActionSrv = nh.advertiseService("get_last_action", &MemoryNode::lastActionSrv, &memoryNode);

	ros::spin();
	
	return 0;
}