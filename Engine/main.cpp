#include "Engine.h"
#include "Helpers/FpsHelper.h"
#include <chrono>
#include <cstdint>
#include "Helpers/Debug/Assert.h"

int main(int argc, char** argv)
{
    Engine engine(D_SHOW_FPS);
    engine.start("Game", 800, 640, false);

    // Put this as close as possible to the start of the loop (before it starts!)
    FpsHelper::init();
    
    while(Engine::isRunning) {
        
        FpsHelper::startFrame();

        engine.handleEvents();
        engine.update();
        engine.render();
        
        if(engine.showFps()) {
            FpsHelper::calculateFps();
            engine.drawFPS(FpsHelper::framesPerSecond());
        }

        FpsHelper::endFrame();
        
    }

    engine.clean();
    return 0;
}
