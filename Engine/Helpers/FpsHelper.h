#ifndef ENGIPIXI_FPSHELPER_H
#define ENGIPIXI_FPSHELPER_H

#include "SDL2/SDL.h"
#include <string>
const unsigned int FRAME_VALUES = 8;
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

    double fps;
    
    // FrameTicks
    unsigned int frameStart;
    unsigned int frameEnd;
    
    // This function gets called once on startup.
    void init();
public:
    FpsHelper();

    std::string framesPerSecond() const;
    
    /**
     * @brief Calculates the average FPS and stores in a member in order to be 
     * retrieved with `std::string framesPerSecond()`
     */
    void calculateFps();
    
    
    /**
     * @brief Start a frame it initializes all the variables in order to knwo
     * if we need to delay the next frame or not.
     */
    void startFrame();
    
    /**
     * @brief Ends a frame, and in case it is necessary, delays the rendering
     * in order to reach the desired framerate.
     */
    void endFrame();

};


#endif //ENGIPIXI_FPSHELPER_H
