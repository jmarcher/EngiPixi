#include "Collision.h"

const int Collision::COLLISION_THRESHOLD = 2;

bool Collision::AABB(const SDL_Rect& A, const SDL_Rect& B)
{
    return A.x + A.w >= B.x && B.x + B.w >= A.x && A.y + A.h >= B.y && B.y + B.h >= A.y;
}

bool Collision::AABB(const ColliderComponent& A, const ColliderComponent& B)
{
    return AABB(A.getCollider(), B.getCollider());
}

CollisionPart Collision::Colliding(const SDL_Rect& A, const SDL_Rect& B)
{
    if(AABB(A, B)) {
        float xCenterOfMass = (A.x + (A.w / 2));
        float yCenterOfMass = (A.y + (A.y / 2));
        
        std::cout << (A.y + A.h)  << "   --  " << B.y << std::endl;
         
        if(betweenThreshold(A.y + A.h, B.y) && (xCenterOfMass > B.x) && (xCenterOfMass < (B.x + B.w))) {
            return CP_TOP;
        }
        
        if(betweenThreshold(A.x + A.w, B.x) && (yCenterOfMass > B.y) && (yCenterOfMass < (B.y + B.h))) {
            return CP_LEFT;
        }
    }

    return CP_NONE;
}
CollisionPart Collision::Colliding(const ColliderComponent& A, const ColliderComponent& B)
{
    return Colliding(A.getCollider(), B.getCollider());
}
