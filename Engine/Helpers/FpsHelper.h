#ifndef ENGIPIXI_FPSHELPER_H
#define ENGIPIXI_FPSHELPER_H

#include "SDL2/SDL.h"
#include <string>
const unsigned int FRAME_VALUES = 10;
const unsigned int FPS = 60;
const unsigned int FRAME_DELAY = 1000 / FPS;

class FpsHelper {
private:
    // An array to store frame times:
    unsigned int frameTimes[FRAME_VALUES];

    // Last calculated SDL_GetTicks
    unsigned int frameTimeLast;

    // total frames rendered
    unsigned int frameCount;

    float fps;
    
    // FrameTicks
    unsigned int frameStart;
    unsigned int frameEnd;
    
public:
    FpsHelper();

    // This function gets called once on startup.
    void init();

    const std::string framesPerSecond() const;
    
    void startFrame();
    
    void endFrame();

    void calculateFps();
};


#endif //ENGIPIXI_FPSHELPER_H
