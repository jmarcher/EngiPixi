#ifndef ENGIPIXI_FPSHELPER_H
#define ENGIPIXI_FPSHELPER_H

#if defined(__linux__) || defined(__APPLE__)
#include "SDL2/SDL.h"
#elif _WIN32
#include "SDL.h"
#endif
#include <string>


class deltaTime;
class FpsHelper {
private:
    static const unsigned int FRAME_VALUES;
    static const unsigned int FPS;
    static const unsigned int FRAME_DELAY;

    // An array to store frame times:
    static unsigned int frameTimes[8];

    // Last calculated SDL_GetTicks
    static unsigned int frameTimeLast;

    // total frames rendered
    static unsigned int frameCount;

    static double fps;
    
    // FrameTicks
    static unsigned int frameStart;
    static unsigned int frameEnd;
    
    static unsigned int ticksT1;
    
public:
    FpsHelper();
    
    // This function gets called once on startup.
    static void init();

    static std::string framesPerSecond();
    
    /**
     * @brief Calculates the average FPS and stores in a member in order to be 
     * retrieved with `std::string framesPerSecond()`
     */
    static void calculateFps();
    
    
    /**
     * @brief Start a frame it initializes all the variables in order to knwo
     * if we need to delay the next frame or not.
     */
    static void startFrame();
    
    /**
     * @brief Ends a frame, and in case it is necessary, delays the rendering
     * in order to reach the desired framerate.
     */
    static void endFrame();
    
    /**
     * @brief Returns seconds passed between the last call to startFrame and this function call.
     * @return 
     */
    static double deltaTime();

};


#endif //ENGIPIXI_FPSHELPER_H
