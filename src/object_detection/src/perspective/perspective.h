//
// Created by greg on 11/30/18.
//

#ifndef PROJECT_PERSPECTIVE_H
#define PROJECT_PERSPECTIVE_H

#include <utility>
#include <cassert>
#include "perspective.h"
#include "perspective_constants.h"
#include "perspective_math/cross_ratio.h"
#include "perspective_math/vector_2d.h"

namespace perspective {


// The y coordinate must be below the vanishing point
    static std::pair<double, double> screenToWorld(double screenX, double screenY) {
        assert(screenY < screen::vanishing);
        // solve for world y
        double lambda = perspective_math::solveCrossRatio(screen::vanishing, screen::firstMarker, screen::secondMarker, screenY);
        double worldY =  world::firstMarker - (lambda * (world::firstMarker - world::secondMarker));
        // solve for world x
        vector_2d<double> vanishingPoint(0, screen::vanishing);
        vector_2d<double> firstMarkerPoint(0, screen::firstMarker);
        vector_2d<double> coordinate(screenX, screenY);
        double theta = vector_2d<double>::angle(firstMarkerPoint - vanishingPoint, coordinate - vanishingPoint);
        double distX = tan(theta) * (screen::vanishing - screen::firstMarker) * screen::cmToFrameRatio;
        double worldX = screenX > 0 ? distX : -distX; // right half is positive quadrant, left is negative
        return std::pair(worldX, worldY);
    }

    static std::pair<double, double> worldToScreen(double worldX, double worldY)  {
        // solve for screen y. (it should always be below the vanishing point
        double lambda = (world::firstMarker - worldY) / (world::firstMarker - world::secondMarker);
        double screenY = perspective_math::solveCrossRatioForD(screen::vanishing, screen::firstMarker, screen::secondMarker, lambda);
        // solve for screen x
        double height = screen::vanishing - screen::firstMarker;
        double dist = worldX / screen::cmToFrameRatio;
        double screenX = (dist * (screen::vanishing - screenY) / height);
        return std::pair(screenX, screenY);
    }



}

#endif //PROJECT_PERSPECTIVE_H
