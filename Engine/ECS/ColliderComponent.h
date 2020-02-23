#ifndef ENGIPIXI_COLLIDERCOMPONENT_H
#define ENGIPIXI_COLLIDERCOMPONENT_H

#ifdef __linux__ 
#include "SDL2/SDL.h"
#elif _WIN32
#include "SDL.h"
#endif

#include "Components.h"
#include "EntityComponentSystem.h"
#include <cstring>

#include "../Math/Vector2D.h"

struct Offset{
  int  m_transformOffsetX, m_transformOffsetY; 
  Offset(int x, int y){
    this->m_transformOffsetX = x;  
    this->m_transformOffsetY = y;  
  };
};

class ColliderComponent : public Component
{
protected:
    SDL_Rect collider;
    SDL_Texture* displayTexture;
    SDL_Rect sourceRect, destinationRect;
    TransformComponent* transform;
    const char * tag;
    bool m_transformsSprite = false;
    Offset m_transformOffset = {0,0};

public:
    ColliderComponent(const char* t);
    ColliderComponent(const char* t, int xPosition, int yPosition, int size);
    ColliderComponent(const char* t, int xPosition, int yPosition, int width, int height);
    ColliderComponent(const char* t, int xPosition, int yPosition, int size, const Offset& transformOffset);
    ColliderComponent(const char* t, const Offset& transformOffset);

    ColliderComponent& setCollider(const SDL_Rect& collider);

    ColliderComponent& setTag(const char* tag);

    ColliderComponent& setTransform(TransformComponent* transform);

    const SDL_Rect& getCollider() const;

    const char * getTag() const;
    
    bool transformsSprite() const { return m_transformsSprite; };
    
    int getOffset(Direction d) const {
        if(d == X){
            return this->m_transformOffset.m_transformOffsetX;
        }
        
        return this->m_transformOffset.m_transformOffsetY;
    };
    
    TransformComponent* getTransform();
    
    void init() override;

    void update() override;

    void draw() override;
};

#endif // ENGIPIXI_COLLIDERCOMPONENT_H
