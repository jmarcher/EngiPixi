#ifndef UILABEL_H
#define UILABEL_H

#ifdef __linux__
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#elif _WIN32
#include "SDL.h"
#include "SDL_ttf.h"
#endif



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
    TTF_Font* font;

public:
    UILabel(const std::string& text, int xPosition, int yPostion, const char* font, SDL_Color& color);
    ~UILabel();

    void setText(const std::string& text, const char* fontId);
    void draw() override;
};

#endif // UILABEL_H
