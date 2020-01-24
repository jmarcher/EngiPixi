#include "Engine.h"
#include <iostream>
#include <cstdint>
#include <thread>
#include <chrono>
#include "SDL2/SDL_thread.h"
#include "Helpers/FpsHelper.h"

int threadTestFunction( void* data )
{
    //Print incoming data
    printf( "Running We can do some extreme calculations here thread with value = %d\n", intptr_t(data) );

    return 0;
}



int main(int argc, char **argv) {
    bool showFps = false;
    Engine engine(showFps);
    engine.start("game", 800,640, false);
    
    
    //Run the thread
    int data = 101;
    
    // Put this as close as possible to the start of the loop (before it starts!)
    FpsHelper fps;
    while (Engine::isRunning) {
        SDL_Thread* hudThread = SDL_CreateThread( threadTestFunction, "LazyThread", (void*)data );
        
        fps.startFrame();

        engine.handleEvents();
        engine.update();
        engine.render();
        if (showFps) {
            fps.calculateFps();
            engine.drawFPS(fps.framesPerSecond());
        }

        SDL_WaitThread( hudThread, NULL );
        
        fps.endFrame();
    }

    engine.clean();
    return 0;
}
