#include "Engine.h"
#include <iostream>
#include "Helpers/FpsHelper.h"



int main(int argc, char **argv) {
    bool showFps = false;
    Engine engine(showFps);
    engine.start("game", 1600, 1280, false);
    
    // Put this as close as possible to the start of the loop (before it starts!)
    FpsHelper fps;
    while (engine.isRunning()) {
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
