//
// Created by greg on 12/31/18.
//

#ifndef PROJECT_POSITIONPREDICTION_H
#define PROJECT_POSITIONPREDICTION_H

#include <custom_msgs/Action.h>
#include <cmath>

namespace prediction {

    struct PositionChange {
        double dx, dy, rotation;
    };

    PositionChange predictMovement(const custom_msgs::Action::ConstPtr &action, double delta) {
        PositionChange pos;

        double leftSpeed = action->params[0];
        double rightSpeed = action->params[1];

        if (leftSpeed == rightSpeed) { // driving straight
            pos.dx = 0;
            pos.dy = 19.7 * delta * (leftSpeed / 1.0); // 19.7 cm/s
            pos.rotation = 0;
            return pos;
        }

        double turningRadius = std::abs((23.5 / 2) + (rightSpeed * 23.5) / (leftSpeed - rightSpeed));
        double outerCircumference = std::max((turningRadius + (23.5 / 2)) * 2 * M_PI, (turningRadius - (23.5 / 2))  * 2 * M_PI); // distance between treads 23.5 cm
        double radiansTraveled = delta / (outerCircumference / 19.7) * 2 * M_PI; // 19.7 cm/s

        if (rightSpeed < leftSpeed) radiansTraveled = M_PI - radiansTraveled;
        if (std::min(leftSpeed, rightSpeed) + std::max(leftSpeed, rightSpeed) < 0) radiansTraveled = -radiansTraveled;

        pos.dx = turningRadius + std::cos(radiansTraveled) * std::abs(turningRadius);
        pos.dy = std::sin(radiansTraveled) * std::abs(turningRadius);
        pos.rotation = rightSpeed < leftSpeed ? radiansTraveled - M_PI : radiansTraveled;

        return pos;
    }

}

#endif //PROJECT_POSITIONPREDICTION_H
