//
// Created by greg on 11/18/18.
//

#include "navigator.h"
#include <vector>

custom_msgs::Action Navigator::chooseNavigationAction(const custom_msgs::ImagesAndBoxes &imgAndBoxes) {
    if(imgAndBoxes.top_img_boxes.empty()) return stopAction(); // required precondition for updateBox
    boxTracker_.updateBox(imgAndBoxes.top_img_boxes);
    if (shouldDriveForward()) return forwardAction();
    else return turnAction();
}

bool Navigator::shouldDriveForward() const {
    const auto& trackedBox = boxTracker_.trackedBox();
    return std::abs((trackedBox.left + trackedBox.right) / 2.0f - 0.5f) < 0.15;
}

custom_msgs::Action Navigator::forwardAction() const {
    custom_msgs::Action action;
    action.id = 1;
    action.params = { 1.0, 1.0 };
    return action;
}

custom_msgs::Action Navigator::turnAction() const {
    const auto& trackedBox = boxTracker_.trackedBox();
    bool boxOnRightSide = (trackedBox.left + trackedBox.right) / 2.0f > 0.5f;
    custom_msgs::Action action;
    action.id = 1;
    action.params = { boxOnRightSide ? 0.9f : 0.0f, boxOnRightSide ? 0.0f : 0.9f };
    return action;
}

custom_msgs::Action Navigator::stopAction() const {
    custom_msgs::Action action;
    action.id = 2;
    return action;
}
