//
// Created by greg on 11/20/18.
//

#ifndef PROJECT_ACTION_DISPATCHER_NODE_H
#define PROJECT_ACTION_DISPATCHER_NODE_H

#include <std_srvs/Empty.h>
#include "ros/ros.h"
#include <vector>
#include <custom_msgs/Action.h>

class ActionDispatcherNode {

private:
    ros::Publisher& dispatchPub_;
    std::vector<custom_msgs::Action::ConstPtr> actionIntents_;

public:
    explicit ActionDispatcherNode(ros::Publisher& dispatchPub): dispatchPub_(dispatchPub) {}

    bool dispatchSrv(std_srvs::Empty::Request& req, std_srvs::Empty::Response& res);
    void addActionIntent(const custom_msgs::Action::ConstPtr& actionIntent);

};


#endif //PROJECT_ACTION_DISPATCHER_NODE_H
