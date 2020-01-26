#ifndef ENGIPIXI_COLLISION_H
#define ENGIPIXI_COLLISION_H

#ifdef __linux__ 
#include "SDL2/SDL.h"
#elif _WIN32
#include "SDL.h"
#endif

#include "ECS/ColliderComponent.h"

class ColliderComponent;

class Collision{
public:
    // Access Allowed Bounding Box
    static bool AABB(const SDL_Rect& A, const SDL_Rect& B);
    static bool AABB(const ColliderComponent& A, const ColliderComponent& B);
    
};

#endif //ENGIPIXI_COLLISION_H
