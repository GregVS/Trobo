//
// Created by greg on 11/30/18.
//

#ifndef PROJECT_PERSPECTIVE_H
#define PROJECT_PERSPECTIVE_H

#include <utility>

namespace screen {
    const float vanishing = 0.8;
    const float firstMarker = 0.1;
    const float secondMarker = 0.1;
    const float cmToFrameRatio = 100; //horizontal pixels per cm
}

namespace world {
    const float firstMarker = 10;
    const float secondMarker = 20;
}

class Perspective {

public:
    std::pair<float, float> screenToWorld(float screenX, float screenY);
    std::pair<float, float> worldToScreen(float worldX, float worldY);

private:
    float solveCrossRatio(float A, float B, float C, float D);
    float solveCrossRatioForD(float A, float B, float C, float L);

};


#endif //PROJECT_PERSPECTIVE_H
