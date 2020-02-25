#ifndef ENGIPIXI_COLLISION_H
#define ENGIPIXI_COLLISION_H

#ifdef __linux__

#include "SDL2/SDL.h"

#elif _WIN32
#include "SDL.h"
#endif

#include "ECS/ColliderComponent.h"

class ColliderComponent;

enum CollisionPart {
    CP_TOP, CP_RIGHT, CP_BOTTOM, CP_LEFT, CP_NONE
};

class Collision {
private:
    static const int COLLISION_THRESHOLD;
public:
    // Access Allowed Bounding Box
    static bool AABB(const SDL_Rect &A, const SDL_Rect &B);

    static bool AABB(const ColliderComponent &A, const ColliderComponent &B);

    static CollisionPart Colliding(const SDL_Rect &A, const SDL_Rect &B);

    static CollisionPart Colliding(const ColliderComponent &A, const ColliderComponent &B);

    inline static bool InRangeWithEpsilon(int a, int b) {
        return (a >= (b - COLLISION_THRESHOLD)) && (a <= (b + COLLISION_THRESHOLD));
    }

    inline static bool betweenThreshold(float a, float b) {
        return (a >= (b - static_cast<float>(COLLISION_THRESHOLD))) &&
               (a <= (b + static_cast<float>(COLLISION_THRESHOLD)));
    }
};

#endif // ENGIPIXI_COLLISION_H
