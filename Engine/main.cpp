#include "Engine.h"
#include <iostream>
#include <cstdint>
#include <thread>
#include <chrono>
#include "Helpers/FpsHelper.h"


int main(int argc, char **argv) {
    bool showFps = false;
    Engine engine(showFps);
    engine.start("Game", 800,640, false);
    
    // Put this as close as possible to the start of the loop (before it starts!)
    FpsHelper fps;
    while (Engine::isRunning) {
        fps.startFrame();

        engine.handleEvents();
        engine.update();
        engine.render();
        if (showFps) {
            fps.calculateFps();
            engine.drawFPS(fps.framesPerSecond());
        }
        
        fps.endFrame();
    }

    engine.clean();
    
    return 0;
}
