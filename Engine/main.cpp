#include "Engine.h"
#include <iostream>

Engine * engine = nullptr;

int main(int argc, char** argv)
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    
    unsigned long int frameStart;
    int frameTime;
    
    engine = new Engine();
    engine->start("game", 1200, 900, false);

    while(engine->isRunning()) {
        frameStart = SDL_GetTicks();
        engine->handleEvents();
        engine->update();
        engine->render();
        
        frameTime = SDL_GetTicks() - frameStart;
        // Check if we need to delay the frames
        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }

    engine->clean();
    return 0;
}
