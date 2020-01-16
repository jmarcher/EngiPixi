#include "Engine.h"
#include <iostream>

#define FRAME_VALUES 10

// An array to store frame times:
Uint32 frameTimes[FRAME_VALUES];

// Last calculated SDL_GetTicks
Uint32 frameTimeLast;

// total frames rendered
Uint32 frameCount;

float framesPerSecond;
// Frames per second as char*
char c_framesPerSecond[5];

Engine *engine = nullptr;

// This function gets called once on startup.
void fpsInit() {
    // Set all frame times to 0ms.
    memset(frameTimes, 0, sizeof(frameTimes));
    frameCount = 0;
    framesPerSecond = 0;
    frameTimeLast = SDL_GetTicks();
}

void calculateFps() {
    Uint32 frameTimesIndex;
    Uint32 currentTicks;
    Uint32 count;

    // frameTimesIndex is the transformation in the array. It ranges from 0 to FRAME_VALUES.
    // This value rotates back to 0 after it hits FRAME_VALUES.
    frameTimesIndex = frameCount % FRAME_VALUES;

    // store the current time
    currentTicks = SDL_GetTicks();

    // save the frame time value
    frameTimes[frameTimesIndex] = currentTicks - frameTimeLast;

    // save the last frame time for the next calculateFps
    frameTimeLast = currentTicks;

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
    framesPerSecond = 0;
    for (Uint32 i = 0; i < count; i++) {
        framesPerSecond += frameTimes[i];
    }

    framesPerSecond /= count;

    // now to make it an actual frames per second value...
    framesPerSecond = 1000.f / framesPerSecond;

    snprintf(c_framesPerSecond, sizeof(c_framesPerSecond), "%f", framesPerSecond);
}

int main(int argc, char **argv) {
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    unsigned long int frameStart;
    int frameTime;
    bool showFps = true;
    engine = new Engine(showFps);
    engine->start("game", 1600, 1280, false);

    // put this as close as possible to the start of the loop (before it starts!)
    if (showFps)
        fpsInit();
    while (engine->isRunning()) {
        frameStart = SDL_GetTicks();
        engine->handleEvents();
        engine->update();
        engine->render();

        frameTime = SDL_GetTicks() - frameStart;
        // Check if we need to delay the frames
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
        if (showFps) {
            calculateFps();
            engine->drawFPS(c_framesPerSecond);
        }
    }

    engine->clean();
    return 0;
}
