#include "UILabel.h"

UILabel::UILabel(const std::string& text, int xPosition, int yPostion, const std::string& font, SDL_Color& color)
    : textColor(color)
{
    this->position.x = xPosition;
    this->position.y = yPostion;
    this->setText(text, font);
}

UILabel::~UILabel()
{
}

void UILabel::setText(const std::string& text, const std::string& fontId)
{
    SDL_Surface* surface =
        TTF_RenderText_Blended(Engine::assets->getFont(fontId), text.c_str(), this->textColor);
    this->labelTexture = SDL_CreateTextureFromSurface(Engine::renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(this->labelTexture, nullptr, nullptr, &this->position.w, &this->position.h);
}

void UILabel::draw()
{
    SDL_RenderCopy(Engine::renderer, this->labelTexture, nullptr, &this->position);
}
