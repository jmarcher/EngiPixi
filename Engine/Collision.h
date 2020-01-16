#ifndef ENGIPIXI_COLLISION_H
#define ENGIPIXI_COLLISION_H

#include "SDL2/SDL.h"

class Collision{
public:
    // Access Allowed Bounding Box
    static bool AABB(const SDL_Rect& A, const SDL_Rect& B);
};

#endif //ENGIPIXI_COLLISION_H
