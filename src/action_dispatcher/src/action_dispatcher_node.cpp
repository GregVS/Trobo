//
// Created by greg on 11/20/18.
//

#include "action_dispatcher_node.h"
#include <custom_msgs/Action.h>

bool ActionDispatcherNode::dispatchSrv(std_srvs::EmptyRequest &req, std_srvs::EmptyResponse &res) {
    if(actionIntents_.empty()) return false;
    auto actionIter = std::min_element(actionIntents_.begin(), actionIntents_.end(), [](const custom_msgs::ActionConstPtr& act1, const custom_msgs::ActionConstPtr& act2) {
        return act1->id < act2->id;
    });
    assert(actionIter != actionIntents_.end());
    dispatchPub_.publish(*actionIter);
    actionIntents_.clear();
}

void ActionDispatcherNode::addActionIntent(const custom_msgs::ActionConstPtr& actionIntent) {
    actionIntents_.push_back(actionIntent);
}

int main(int argc, char **argv) {

    ros::init(argc, argv, "action_dispatcher");
    ros::NodeHandle nh;

    ros::Publisher dispatchPub = nh.advertise<custom_msgs::Action>("dispatched_actions", 5);

    ActionDispatcherNode dispatcherNode(dispatchPub);

    // setup subscribers to store data in memory
    ros::ServiceServer dispatchSrv = nh.advertiseService("dispatch_action", &ActionDispatcherNode::dispatchSrv, &dispatcherNode);
    ros::Subscriber intentSub = nh.subscribe("action_intents", 10, &ActionDispatcherNode::addActionIntent, &dispatcherNode);

    ROS_INFO("Action dispatcher running...");
    ros::spin();

    return 0;
}
