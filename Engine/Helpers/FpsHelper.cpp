#include "FpsHelper.h"

#include <iostream>
const unsigned int FpsHelper::FRAME_VALUES = 8;
const unsigned int FpsHelper::FPS = 120;
const unsigned int FpsHelper::FRAME_DELAY = 1000 / FPS;

    // An array to store frame times:
unsigned int FpsHelper::frameTimes[8];

    // Last calculated SDL_GetTicks
unsigned int FpsHelper::frameTimeLast = 0;

    // total frames rendered
unsigned int FpsHelper::frameCount = 0;

double FpsHelper::fps = 0;
    
    // FrameTicks
unsigned int FpsHelper::frameStart = 0;
unsigned int FpsHelper::frameEnd = 0;

unsigned int FpsHelper::ticksT1 = 0;
FpsHelper::FpsHelper() {
    this->init();
}

void FpsHelper::init() {
    // Set all frame times to 0ms.
    memset(frameTimes, 0, sizeof(frameTimes));
    frameCount = 0;
    fps = 0;
    frameTimeLast = SDL_GetTicks();
}

void FpsHelper::calculateFps() {
    unsigned int frameTimesIndex;
    unsigned int count;

    // frameTimesIndex is the transformation in the array. It ranges from 0 to FRAME_VALUES.
    // This value rotates back to 0 after it hits FRAME_VALUES.
    frameTimesIndex = frameCount % FRAME_VALUES;

    // save the frame time value
    frameTimes[frameTimesIndex] = frameStart - frameTimeLast;

    // save the last frame time for the next calculateFps
    frameTimeLast = frameStart;

    // increment the frame count
    frameCount++;

    // Work out the current framerate

    // The code below could be moved into another function if you don't need the value every frame.

    // I've included a test to see if the whole array has been written to or not. This will stop
    // strange values on the first few (FRAME_VALUES) frames.
    if (frameCount < FRAME_VALUES) {
        count = frameCount;
    } else {
        count = FRAME_VALUES;
    }

    // add up all the values and divide to get the average frame time.
    fps = 0;
    for (unsigned int i = 0; i < count; i++) {
        fps += frameTimes[i];
    }

    fps /= count;

    // now to make it an actual frames per second value...
    fps = 1000.f / fps;
}

std::string FpsHelper::framesPerSecond() {
    return std::to_string(FpsHelper::fps);
}

void FpsHelper::startFrame() {
    FpsHelper::frameStart = SDL_GetTicks();
}


void FpsHelper::endFrame() {
    FpsHelper::frameEnd = SDL_GetTicks() - frameStart;

    // Check if we need to delay the frames
    if (FRAME_DELAY > frameEnd) {
        SDL_Delay(FRAME_DELAY - frameEnd);
    }
}
double FpsHelper::deltaTime()
{
    unsigned int actualTicks =  SDL_GetTicks();
    double result = (actualTicks - FpsHelper::ticksT1) / 1000.0f;
    
    FpsHelper::ticksT1 = actualTicks;
    
    return result;
}
