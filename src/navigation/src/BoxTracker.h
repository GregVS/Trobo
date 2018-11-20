//
// Created by greg on 11/19/18.
//

#ifndef PROJECT_BOX_TRACKER_H
#define PROJECT_BOX_TRACKER_H

#include <custom_msgs/Box.h>

class BoxTracker {

private:
    std::unique_ptr<custom_msgs::Box> trackedBox_;

    // PRECONDITION: boxes list is not empty
    // will return true if it was able to update the tracked box or false if it did not exist
    bool updateTrackedBoxIfExists(std::vector<custom_msgs::Box> boxes);

    // this algorithm basically just for now picks the other that is closest to the center
    custom_msgs::Box bestBoxToTrack(std::vector<custom_msgs::Box> boxes);

public:
    void updateBox(std::vector<custom_msgs::Box> boxes);

    // PRECONDITION: tracked box must not be null (call updateBox first)
    const custom_msgs::Box trackedBox() const { assert(trackedBox_ != nullptr); return *trackedBox_; }

};


#endif //PROJECT_BOX_TRACKER_H
