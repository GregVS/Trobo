#include <boost/circular_buffer.hpp>
#include <custom_msgs/ImagesAndBoxes.h>
#include <custom_msgs/Action.h>

#include "ros/ros.h"

class RobotMemory {

public:

	// set the size of the buffer to 5
	RobotMemory() : networkOutputBuffer_(5), actionBuffer_(5) {}

	// adds the new output to the front of the buffer
	void storeNetworkOutput(const custom_msgs::ImagesAndBoxes::ConstPtr& output) { 
		networkOutputBuffer_.push_back(output);
		ROS_INFO("Storing network output");
	}
	
	void storeAction(const custom_msgs::Action::ConstPtr& action) { actionBuffer_.push_back(action); }

	// gets the most recently added output
	custom_msgs::ImagesAndBoxes::ConstPtr lastNetworkOutput() {
		if (networkOutputBuffer_.empty()) return nullptr;
		return networkOutputBuffer_.front();
	}

	custom_msgs::Action::ConstPtr lastAction() {
		if (actionBuffer_.empty()) return nullptr;
		return actionBuffer_.front();
	}

private:
	// Stores the last network ouputs. Replaces old data when max size is reached.
	boost::circular_buffer<custom_msgs::ImagesAndBoxes::ConstPtr> networkOutputBuffer_;
	boost::circular_buffer<custom_msgs::Action::ConstPtr> actionBuffer_;

};