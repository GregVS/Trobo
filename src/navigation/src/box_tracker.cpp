//
// Created by greg on 11/19/18.
//

#include "box_tracker.h"

const custom_msgs::Box BoxTracker::bestBoxToTrack(const std::vector<custom_msgs::Box>& boxes) const {
    auto it = std::min_element(boxes.begin(), boxes.end(), [](const custom_msgs::Box& box1, const custom_msgs::Box& box2) {
        return std::abs((box1.left + box1.right) / 2.0f) < std::abs((box2.left + box2.right) / 2.0f);
    });
    assert(it != boxes.end());
    return *it;
}

bool BoxTracker::updateTrackedBoxIfExists(const std::vector<custom_msgs::Box> &boxes) {
    if (!trackedBox_) return false;
    auto it = std::find_if(boxes.begin(), boxes.end(), [this] (const custom_msgs::Box& box) { return trackedBox_->id == box.id; });
    if (it == boxes.end()) return false;
    trackedBox_ = std::make_unique<custom_msgs::Box>(*it);
    return true;
}


void BoxTracker::updateBox(const std::vector<custom_msgs::Box>& boxes) {
    if (!updateTrackedBoxIfExists(boxes)) {
        trackedBox_ = std::make_unique<const custom_msgs::Box>(bestBoxToTrack(boxes));
    }
    assert(trackedBox_ != nullptr);
}
