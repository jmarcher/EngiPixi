#include "Collision.h"

const int Collision::COLLISION_THRESHOLD = 2;

bool Collision::AABB(const SDL_Rect &A, const SDL_Rect &B) {
    return A.x + A.w >= B.x && B.x + B.w >= A.x && A.y + A.h >= B.y && B.y + B.h >= A.y;
}

bool Collision::AABB(const ColliderComponent &A, const ColliderComponent &B) {
    return AABB(A.getCollider(), B.getCollider());
}

CollisionPart Collision::Colliding(const SDL_Rect &A, const SDL_Rect &B) {
    if (AABB(A, B)) {

        if (InRangeWithEpsilon(A.y + A.h, B.y) && ((A.x + A.w) > (B.x)) &&
            (A.x < (B.x + B.w))) {
            return CP_TOP;
        }

        if (InRangeWithEpsilon(A.y, B.y + B.h) && ((A.x + A.w) > (B.x)) &&
            (A.x < (B.x + B.w))) {
            return CP_BOTTOM;
        }

        if (InRangeWithEpsilon(A.x + A.w, B.x) && ((A.y + A.h) > (B.y)) &&
            (A.y < (B.y + B.h))) {
            return CP_LEFT;
        }

        if (InRangeWithEpsilon(A.x, B.x + B.w) && ((A.y + A.h) > (B.y)) &&
            (A.y < (B.y + B.h))) {
            return CP_RIGHT;
        }
    }

    return CP_NONE;
}

CollisionPart Collision::Colliding(const ColliderComponent &A, const ColliderComponent &B) {
    return Colliding(A.getCollider(), B.getCollider());
}
