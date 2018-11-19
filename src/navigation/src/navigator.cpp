//
// Created by greg on 11/18/18.
//

#include "navigator.h"
#include <vector>
#include <algorithm>
#include <cmath>

custom_msgs::Action Navigator::navigate(const custom_msgs::ImagesAndBoxes &imgAndBoxes) {
    if(imgAndBoxes.top_img_boxes.empty()) {
        custom_msgs::Action action;
        action.id = 2;
        return action;
    }
    if (!verifyTrackedBoxExists(imgAndBoxes.top_img_boxes)) {
        trackedBox_ = std::make_unique<custom_msgs::Box>(nearestBox(imgAndBoxes.top_img_boxes));
    }

}

bool Navigator::shouldDriveStraight(const custom_msgs::ImagesAndBoxes &imgAndBoxes) {

}

custom_msgs::Box Navigator::nearestBox(std::vector<custom_msgs::Box> boxes) {
    auto it = std::min_element(boxes.begin(), boxes.end(), [](const custom_msgs::Box& box1, const custom_msgs::Box& box2) {
        return std::abs((box1.left + box1.right) / 2.0f - 0.5f) < std::abs((box2.left + box2.right) / 2.0f - 0.5f);
    });
    assert(it != boxes.end());
    return *it;
}

bool Navigator::verifyTrackedBoxExists(std::vector<custom_msgs::Box> boxes) {
    if (!trackedBox_) return false;
    auto it = std::find_if(boxes.begin(), boxes.end(), [this] (const custom_msgs::Box& box) { return trackedBox_->id == box.id; });
    return it != boxes.end();
}
