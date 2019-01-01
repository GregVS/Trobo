//
// Created by greg on 11/18/18.
//

#ifndef PROJECT_NAVIGATOR_H
#define PROJECT_NAVIGATOR_H

#include <custom_msgs/ImagesAndBoxes.h>
#include <custom_msgs/Action.h>
#include <custom_msgs/Box.h>
#include "box_tracker.h"

class Navigator {

public:
    // PRECONDITION: THE PROVIDED BOXES SHOULD HAVE ID'S THAT ARE NOT EQUAL TO 0
    custom_msgs::Action chooseNavigationAction(const custom_msgs::ImagesAndBoxes &imgAndBoxes);

private:
    BoxTracker boxTracker_;

    bool shouldDriveForward() const;

    custom_msgs::Action forwardAction() const;
    custom_msgs::Action turnAction() const;
    custom_msgs::Action stopAction() const;
};

#endif //PROJECT_NAVIGATOR_H
