#include "../Collision.h"
#include "../Helpers/Debug/Assert.h"
#include "TransformComponent.h"
#include <iostream>
#include "../Engine.h"

extern Manager manager;
extern std::vector<Entity *> &colliders;

//auto& tpColliders(manager.getGroup(Engine::groupColliders));
TransformComponent::TransformComponent() {
    position.zero();
}

TransformComponent::TransformComponent(int s) {
    position.x = 400 - 64;
    position.y = 320 - 64;
    scale = s;
}

TransformComponent::TransformComponent(float x, float y, int s) {
    setPosition(x, y);
    scale = s;
}

TransformComponent::TransformComponent(float x, float y) {
    setPosition(x, y);
}

TransformComponent::TransformComponent(float x, float y, int w, int h, int s) {
    setPosition(x, y);
    width = w;
    height = h;
    scale = s;
}

void TransformComponent::init() {
    velocity.zero();
}

void TransformComponent::update() {


    SDL_Rect playerCollider = *(&entity->getComponent<ColliderComponent>().getCollider());
//    std::cout << Vector2D(playerCollider.x, playerCollider.y) << std::endl;
    for (auto &collider : colliders) {
        if (!collider->hasComponent<ColliderComponent>()) continue;
        SDL_Rect cCollider = collider->getComponent<ColliderComponent>().getCollider();
        CollisionPart cp = Collision::Colliding(playerCollider, cCollider);
        switch (cp) {
            case CP_TOP:
                if (velocity.y > 0) {
                    velocity.y = 0;
                }
                break;
            case CP_LEFT:
                if (velocity.x > 0) {
                    velocity.x = 0;
                }
                break;
            case CP_RIGHT:
                if (velocity.x < 0) {
                    velocity.x = 0;
                }
                break;
            case CP_BOTTOM:
                if (velocity.y < 0) {
                    velocity.y = 0;
                }
                break;
        }
    }
    position.x += velocity.x * speed;
    position.y += velocity.y * speed;
}

void TransformComponent::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
}

TransformComponent::TransformComponent(int w, int h, int s) {
    width = w;
    height = h;
    scale = s;
    setPosition(0, 0);
}

void TransformComponent::bounce(const Vector2D &oldPosition) {
    if (velocity.y > 0)
        std::cout << velocity << std::endl;
    switch (static_cast<int>(velocity.x)) {
        case 1:
            position.x = position.x - 1;
            break;
        case -1:
            position.x = position.x + 1;
            break;
        default:
            break;
    }
    switch (static_cast<int>(velocity.y)) {
        case 1:
            position.y = position.y - 1;
            break;
        case -1:
            position.y = position.y + 1;
            break;
        default:
            break;
    }
}

TransformComponent::TransformComponent(float s) {
    speed = s;
}