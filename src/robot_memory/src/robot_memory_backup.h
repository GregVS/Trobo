#ifndef ROBOT_MEMORY_H
#define ROBOT_MEMORY_H

#include <boost/circular_buffer.hpp>
#include <custom_msgs/ImagesAndBoxes.h>
#include <custom_msgs/Action.h>
#include <iostream>

class RobotMemory {

public:

	// set the size of the buffer to 5
	RobotMemory() : networkOutputBuffer_(5), actionBuffer_(5), predictionOutputBuffer_(5) {}

	// adds the new output to the front of the buffer
	void storeNetworkOutput(const custom_msgs::ImagesAndBoxes::ConstPtr& output) { networkOutputBuffer_.push_back(output); }
	void storeAction(const custom_msgs::Action::ConstPtr& action) { actionBuffer_.push_back(action); }
	void storePredictionOutput(const custom_msgs::ImagesAndBoxes::ConstPtr& output) { predictionOutputBuffer_.push_back(output); }

	// gets the most recently added output
	custom_msgs::ImagesAndBoxes::ConstPtr fetchNetworkOutput(uint8_t skips) { return fetchStoredData(networkOutputBuffer_, skips); }
	custom_msgs::Action::ConstPtr fetchAction(uint8_t skips) { return fetchStoredData(actionBuffer_, skips); }
	custom_msgs::ImagesAndBoxes::ConstPtr fetchPredictionOutput(uint8_t skips) { return fetchStoredData(predictionOutputBuffer_, skips); }

private:
	// Stores the last network ouputs. Replaces old data when max size is reached.
	boost::circular_buffer<custom_msgs::ImagesAndBoxes::ConstPtr> networkOutputBuffer_;
	boost::circular_buffer<custom_msgs::ImagesAndBoxes::ConstPtr> predictionOutputBuffer_;
	boost::circular_buffer<custom_msgs::Action::ConstPtr> actionBuffer_;

	template <class T>
	T fetchStoredData(boost::circular_buffer<T>& buffer, uint8_t skips) {
		int pos = buffer.size() - (skips + 1);
		if (pos < 0) return nullptr;
		return buffer[buffer.size() - (skips + 1)];
	}

};

#endif