#include "Collision.h"

bool Collision::AABB(const SDL_Rect &A, const SDL_Rect &B) {
    return A.x + A.w >= B.x
           && B.x + B.w >= A.x
           && A.y + A.h >= B.y
           && B.y + B.h >= A.y;
}
