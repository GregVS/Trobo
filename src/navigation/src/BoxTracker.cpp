//
// Created by greg on 11/19/18.
//

#include "BoxTracker.h"

custom_msgs::Box BoxTracker::bestBoxToTrack(std::vector<custom_msgs::Box> boxes) {
    auto it = std::min_element(boxes.begin(), boxes.end(), [](const custom_msgs::Box& box1, const custom_msgs::Box& box2) {
        return std::abs((box1.left + box1.right) / 2.0f - 0.5f) < std::abs((box2.left + box2.right) / 2.0f - 0.5f);
    });
    assert(it != boxes.end());
    return *it;
}

bool BoxTracker::updateTrackedBoxIfExists(std::vector<custom_msgs::Box> boxes) {
    if (!trackedBox_) return false;
    auto it = std::find_if(boxes.begin(), boxes.end(), [this] (const custom_msgs::Box& box) { return trackedBox_->id == box.id; });
    if (it == boxes.end()) return false;
    trackedBox_ = std::make_unique<custom_msgs::Box>(*it);
    return true;
}


void BoxTracker::updateBox(std::vector<custom_msgs::Box> boxes) {
    if (!updateTrackedBoxIfExists(boxes)) {
        trackedBox_ = std::make_unique<custom_msgs::Box>(bestBoxToTrack(boxes));
    }
    assert(trackedBox_ != nullptr);
}