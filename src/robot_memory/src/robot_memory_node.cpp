#include "ros/ros.h"
#include "memory_bucket.h"
#include <custom_msgs/ImagesAndBoxesSrv.h>
#include <custom_msgs/ActionSrv.h>

#include <memory>

struct MemoryBucketSet {
    MemoryBucket<custom_msgs::ImagesAndBoxes> networkOutputBucket;
    MemoryBucket<custom_msgs::ImagesAndBoxes> predictionOutputBucket;
    MemoryBucket<custom_msgs::Action> actionBucket;
};

class MemoryNode {

public:
    explicit MemoryNode(MemoryBucketSet& bucketSet): bucketSet_(bucketSet) {}

    // Service functions/definitions go here
	bool fetchNetworkOutputSrv(custom_msgs::ImagesAndBoxesSrv::Request& req, custom_msgs::ImagesAndBoxesSrv::Response& res) {
		return fetchDataFromBucket<custom_msgs::ImagesAndBoxesSrv, custom_msgs::ImagesAndBoxes>(req, res, bucketSet_.networkOutputBucket);
	}
	bool fetchActionSrv(custom_msgs::ActionSrv::Request& req, custom_msgs::ActionSrv::Response& res) {
        return fetchDataFromBucket<custom_msgs::ActionSrv, custom_msgs::Action>(req, res, bucketSet_.actionBucket);
	}
	bool fetchPredictionOutputSrv(custom_msgs::ImagesAndBoxesSrv::Request& req, custom_msgs::ImagesAndBoxesSrv::Response& res) {
		return fetchDataFromBucket<custom_msgs::ImagesAndBoxesSrv, custom_msgs::ImagesAndBoxes>(req, res, bucketSet_.predictionOutputBucket);
	}

	// Gets the data from the given memory bucket
	template <typename SrvType, typename DataType>
	bool fetchDataFromBucket(typename SrvType::Request& req, typename SrvType::Response& res, MemoryBucket<DataType>& bucket) {
        auto output = bucket.fetchDataFromBuffer(req.skips);
        if (output == nullptr) return false;
        res.result = *output;
        return true;
    }

private:
    MemoryBucketSet& bucketSet_;

};

int main(int argc, char **argv) {

	MemoryBucketSet bucketSet;
    MemoryNode memoryNode(bucketSet);

	ros::init(argc, argv, "memory_node");
	ros::NodeHandle nh;

		// setup subscribers to store data in memory
	ros::Subscriber netOutputSub = nh.subscribe("network_out_imgs", 5, &MemoryBucket<custom_msgs::ImagesAndBoxes>::storeDataInBuffer, &bucketSet.networkOutputBucket);
	ros::Subscriber actionSub = nh.subscribe("dispatched_actions", 5, &MemoryBucket<custom_msgs::Action>::storeDataInBuffer, &bucketSet.actionBucket);
	ros::Subscriber predictionSub = nh.subscribe("prediction_output", 5, &MemoryBucket<custom_msgs::ImagesAndBoxes>::storeDataInBuffer, &bucketSet.predictionOutputBucket);

		// setup services
	ros::ServiceServer fetchNetOutput = nh.advertiseService("fetch_network_output", &MemoryNode::fetchNetworkOutputSrv, &memoryNode);
	ros::ServiceServer fetchAction = nh.advertiseService("fetch_action", &MemoryNode::fetchActionSrv, &memoryNode);
	ros::ServiceServer fetchPredictionOut = nh.advertiseService("fetch_prediction_output", &MemoryNode::fetchPredictionOutputSrv, &memoryNode);

	ros::spin();

	return 0;
}