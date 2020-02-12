#ifndef ENGIPIXI_SPRITECOMPONENT_H
#define ENGIPIXI_SPRITECOMPONENT_H
#ifdef __linux__
#include "SDL2/SDL.h"
#elif _WIN32
#include "SDL.h"
#endif

#include "Animation.h"
#include "Components.h"
#include <map>

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

    SpriteComponent(const char* id);

    SpriteComponent(const char* id, bool isAnimated);

    ~SpriteComponent();

    void setTexture(const char* id);

    void init() override;

    void update() override;

    void draw() override;

    void play(const char* animationName);
    
    void play(const char* animationName, SDL_RendererFlip flip);

    void setHorizontalFlip();
    void setVerticalFlip();
    void setNoFlip();

    SDL_Rect getDestinationRect() const;
};

#endif // ENGIPIXI_SPRITECOMPONENT_H
