#include "FpsHelper.h"

FpsHelper::FpsHelper() {
    this->init();
}

void FpsHelper::init() {
    // Set all frame times to 0ms.
    memset(this->frameTimes, 0, sizeof(this->frameTimes));
    this->frameCount = 0;
    this->fps = 0;
    this->frameTimeLast = SDL_GetTicks();
}

void FpsHelper::calculateFps() {
    unsigned int frameTimesIndex;
    unsigned int count;

    // frameTimesIndex is the transformation in the array. It ranges from 0 to FRAME_VALUES.
    // This value rotates back to 0 after it hits FRAME_VALUES.
    frameTimesIndex = frameCount % FRAME_VALUES;

    // save the frame time value
    frameTimes[frameTimesIndex] = this->frameStart - frameTimeLast;

    // save the last frame time for the next calculateFps
    frameTimeLast = this->frameStart;

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

std::string FpsHelper::framesPerSecond() const {
    return std::to_string(fps);
}

void FpsHelper::startFrame() {
    this->frameStart = SDL_GetTicks();
}

void FpsHelper::endFrame() {
    this->frameEnd = SDL_GetTicks() - this->frameStart;

    // Check if we need to delay the frames
    if (FRAME_DELAY > this->frameEnd) {
        SDL_Delay(FRAME_DELAY - this->frameEnd);
    }
}