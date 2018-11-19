#ifndef ROBOT_MEMORY_H
#define ROBOT_MEMORY_H

#include <boost/circular_buffer.hpp>
#include <custom_msgs/ImagesAndBoxes.h>
#include <custom_msgs/Action.h>
#include <iostream>

template <class DataType>
class MemoryBucket {

public:

	// set the size of the buffer to 5
	MemoryBucket() : buffer_(5) {}

	// adds the new output to the front of the buffer
	void storeDataInBuffer(const typename DataType::ConstPtr& output) { buffer_.push_back(output); }

	// gets the most recently added output
	typename DataType::ConstPtr fetchDataFromBuffer(uint8_t skips) {
		int pos = buffer_.size() - (skips + 1);
		if (pos < 0) return nullptr;
		return buffer_[buffer_.size() - (skips + 1)];
	}

private:
	// Stores the last network ouputs. Replaces old data when max size is reached.
	boost::circular_buffer<typename DataType::ConstPtr> buffer_;

};

#endif