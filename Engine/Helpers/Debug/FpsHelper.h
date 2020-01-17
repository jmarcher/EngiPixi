#ifndef ENGIPIXI_FPSHELPER_H
#define ENGIPIXI_FPSHELPER_H

#include "SDL2/SDL.h"
#include <string>
#define FRAME_VALUES 10

class FpsHelper {
private:
    // An array to store frame times:
    unsigned int frameTimes[FRAME_VALUES];

    // Last calculated SDL_GetTicks
    unsigned int frameTimeLast;

    // total frames rendered
    unsigned int frameCount;

    float fps;
public:
    FpsHelper();

    // This function gets called once on startup.
    void init();

    std::string framesPerSecond() const;

    void calculateFps();
};


#endif //ENGIPIXI_FPSHELPER_H
