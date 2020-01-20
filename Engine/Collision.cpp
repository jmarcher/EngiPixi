#include "Collision.h"

bool Collision::AABB(const SDL_Rect &A, const SDL_Rect &B) {
    return A.x + A.w >= B.x
           && B.x + B.w >= A.x
           && A.y + A.h >= B.y
           && B.y + B.h >= A.y;
}

bool Collision::AABB(const ColliderComponent& A, const ColliderComponent& B)
{
    if(AABB(A.collider, B.collider)){
        std::cout << A.tag << " hit: " << B.tag << std::endl; 
        return true;
    }
    
    return false;
}
