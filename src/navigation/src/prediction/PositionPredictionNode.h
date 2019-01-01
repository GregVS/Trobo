//
// Created by greg on 12/22/18.
//

#ifndef PROJECT_POSITION_PREDICTION_NODE_H
#define PROJECT_POSITION_PREDICTION_NODE_H

#include <utility>
#include <custom_msgs/Action.h>
#include <custom_msgs/PositionChangeSrv.h>
#include <chrono>

class PositionPredictionNode {

private:
    custom_msgs::Action::ConstPtr latestAction_;
    std::chrono::time_point<std::chrono::system_clock> dispatchedTime_;

public:
    void storeLatestAction(const custom_msgs::Action::ConstPtr& action);
    bool predictPositionChange(custom_msgs::PositionChangeSrv::Request& req, custom_msgs::PositionChangeSrv::Response& res);

};


#endif //PROJECT_POSITION_PREDICTION_NODE_H
