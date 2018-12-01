//
// Created by greg on 11/30/18.
//

#include <cassert>
#include "Perspective.h"
#include "Vector2D.h"

std::pair<float, float> Perspective::screenToWorld(float screenX, float screenY) {
    // solve for world y
    float lambda = solveCrossRatio(screen::vanishing, screen::firstMarker, screen::secondMarker, screenY);
    float worldY =  world::firstMarker - (lambda * (world::firstMarker - world::secondMarker));
    // solve for world x
    Vector2D<float> vanishingPoint(0, screen::vanishing);
    Vector2D<float> firstMarkerPoint(0, screen::firstMarker);
    Vector2D<float> coordinate(screenX, screenY);
    float theta = Vector2D<float>::angle(firstMarkerPoint - vanishingPoint, coordinate - vanishingPoint);
    float distX = tan(theta) * (screen::vanishing - screen::firstMarker) * screen::cmToFrameRatio;
    float worldX = screenX > 0 ? distX : -distX; // right half is positive quadrant, left is negative
    return std::pair(worldX, worldY);
}

std::pair<float, float> Perspective::worldToScreen(float worldX, float worldY) {
    // solve for screen x
    float lambda = (world::firstMarker - worldY) / (world::firstMarker - world::secondMarker);
    float screenY = solveCrossRatioForD(screen::vanishing, screen::firstMarker, screen::secondMarker, lambda);
    // solve for screen y
    float height = screen::vanishing - screen::firstMarker;
    float dist = worldX / screen::cmToFrameRatio;
    float screenX = (dist * screenY / height);
    return std::pair(screenX, screenY);
}

float Perspective::solveCrossRatio(float A, float B, float C, float D) {
    float numerator = (A - C) * (B - D);
    float denominator = (A - D) * (B - C);
    return numerator / denominator;
}

float Perspective::solveCrossRatioForD(float A, float B, float C, float L) {
    float numerator = (L * A * B) - (L * A * C) - (A * B) + (C * B);
    float denominator = (L * B) - (L * C) + C - A;
    assert(denominator != 0);
    return numerator / denominator;
}
