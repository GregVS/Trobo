//
// Created by greg on 11/18/18.
//

#ifndef PROJECT_NAVIGATOR_H
#define PROJECT_NAVIGATOR_H

#include <custom_msgs/ImagesAndBoxes.h>
#include <custom_msgs/Action.h>
#include <custom_msgs/Box.h>
#include "BoxTracker.h"

class Navigator {

public:
    // PRECONDITION: THE PROVIDED BOXES SHOULD HAVE ID'S THAT ARE NOT EQUAL TO 0
    custom_msgs::Action chooseNavigationAction(const custom_msgs::ImagesAndBoxes &imgAndBoxes);

private:
    BoxTracker boxTracker_;

    bool shouldDriveForward();

    custom_msgs::Action forwardAction();

    custom_msgs::Action turnAction();

    custom_msgs::Action stopAction();
};

#endif //PROJECT_NAVIGATOR_H
