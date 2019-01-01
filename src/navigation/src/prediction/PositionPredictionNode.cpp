//
// Created by greg on 12/22/18.
//

#include "ros/ros.h"
#include "PositionPredictionNode.h"
#include <algorithm>
#include <math.h>
#include "PositionPrediction.h"

int main(int argc, char **argv) {

    PositionPredictionNode predictionNode;

    ros::init(argc, argv, "position_prediction_node");
    ros::NodeHandle nh;

    ros::Subscriber netOutputSub = nh.subscribe("dispatched_actions", 5, &PositionPredictionNode::storeLatestAction, &predictionNode);

    // setup services
    ros::ServiceServer fetchPredictionOut = nh.advertiseService("predict_position_change", &PositionPredictionNode::predictPositionChange, &predictionNode);

    ros::spin();

    return 0;
}

bool PositionPredictionNode::predictPositionChange(custom_msgs::PositionChangeSrv::Request& req, custom_msgs::PositionChangeSrv::Response& res) {
    if (!latestAction_) return false;
    prediction::PositionChange positionChange = prediction::predictMovement(latestAction_, (std::chrono::system_clock::now() - dispatchedTime_).count());
    res.dx = static_cast<float>(positionChange.dx);
    res.dy = static_cast<float>(positionChange.dy);
    res.rotation = static_cast<float>(positionChange.rotation);
    return true;
}

void PositionPredictionNode::storeLatestAction(const custom_msgs::Action::ConstPtr &action) {
    latestAction_ = action;
    dispatchedTime_ = std::chrono::system_clock::now();
}
