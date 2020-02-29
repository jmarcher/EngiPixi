#ifndef ENGIPIXI_SPRITECOMPONENT_H
#define ENGIPIXI_SPRITECOMPONENT_H

#if defined(__linux__) || defined(__APPLE__)
    #include "SDL2/SDL.h"
#elif _WIN32
    #include "SDL.h"
#endif

#include <map>
#include <string>

#include "Animation.h"
#include "Components.h"

#include "../Math/Vector2D.h"

class TransformComponent;


class SpriteComponent : public Component
{
protected:
    SDL_Texture* texture;
    SDL_Rect sourceRect, destinationRect;
    TransformComponent* transformation;

    std::map<const char*, Animation> animations;

    int frames = 1;

    int animationSpeed = 100;

    int animationIndex = 0;

    bool animated = false;

    SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

public:
    SpriteComponent() = default;

    SpriteComponent(const std::string& id);

    SpriteComponent(const std::string& id, bool isAnimated);

    ~SpriteComponent();

    void setTexture(const std::string& id);

    void init() override;

    void update() override;

    void draw() override;

    void play(const char* animationName);
    
    void play(const char* animationName, SDL_RendererFlip flip);

    void setHorizontalFlip();
    void setVerticalFlip();
    void setNoFlip();
    
    void setOffset(int offset, Direction direction){
      if(offset != 0){
          if(direction == X){
              this->sourceRect.x += offset;
              this->destinationRect.w = offset;
          }else{
              this->sourceRect.y += offset;
              this->destinationRect.h = offset;
          }
      }  
    };

    SDL_Rect getDestinationRect() const;
};

#endif // ENGIPIXI_SPRITECOMPONENT_H
