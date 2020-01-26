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
#include <string>

class TransformComponent;

class SpriteComponent : public Component {
protected:
    SDL_Texture *texture;
    SDL_Rect sourceRect, destinationRect;
    TransformComponent *transformation;

    std::map<std::string, Animation> animations;

    int frames = 1;

    int animationSpeed = 100;

    int animationIndex = 0;

    bool animated = false;

    SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

public:
    SpriteComponent() = default;

    SpriteComponent(const std::string &path);

    SpriteComponent(const std::string &path, bool isAnimated) ;

    ~SpriteComponent();

    void setTexture(const std::string &path);

    void init() override;

    void update() override;

    void draw() override;

    void play(const std::string& animationName) ;

    void setHorizontalFlip();
    void setVerticalFlip();
    void setNoFlip();

    SDL_Rect getDestinationRect() const;
};

#endif // ENGIPIXI_SPRITECOMPONENT_H
