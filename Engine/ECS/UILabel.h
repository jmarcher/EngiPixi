#ifndef UILABEL_H
#define UILABEL_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include <string>

#include "../AssetManager.h"
#include "../Engine.h"
#include "EntityComponentSystem.h"

class UILabel : public Component
{
protected:
    SDL_Rect position;
    SDL_Color textColor;
    std::string labelText;
    std::string labelFont;
    SDL_Texture* labelTexture;

public:
    UILabel(const std::string& text, int xPosition, int yPostion, const std::string& font, SDL_Color& color);
    ~UILabel();
    void setText(const std::string& text, const std::string& fontId);

    void draw() override;
};

#endif // UILABEL_H
