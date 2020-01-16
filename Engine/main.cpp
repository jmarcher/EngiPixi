#include "Engine.h"
#include <iostream>
#include "Helpers/Debug/FpsHelper.h"

Engine *engine = nullptr;

int main(int argc, char **argv) {
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    FpsHelper fps;

    unsigned long int frameStart;
    int frameTime;
    bool showFps = true;
    engine = new Engine(showFps);
    engine->start("game", 1600, 1280, false);

    // put this as close as possible to the start of the loop (before it starts!)
    if (showFps)
        FpsHelper fps;
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
            fps.calculateFps();
            engine->drawFPS(fps.framesPerSecond().c_str());
        }
    }

    engine->clean();
    return 0;
}
