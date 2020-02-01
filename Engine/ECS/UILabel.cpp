#include "UILabel.h"

UILabel::UILabel(const std::string& text, int xPosition, int yPostion, const std::string& font, SDL_Color& color)
    : textColor(color), labelText(text)
{
    this->position.x = xPosition;
    this->position.y = yPostion;
    this->font = Engine::assets->getFont(font);
    // this->setText(text, font);
}

UILabel::~UILabel()
{
}

void UILabel::setText(const std::string& text, const std::string& fontId)
{
        SDL_Surface* surface = TTF_RenderText_Blended(this->font, text.c_str(), this->textColor);
        this->labelTexture = SDL_CreateTextureFromSurface(Engine::renderer, surface);       
        SDL_QueryTexture(this->labelTexture, nullptr, nullptr, &this->position.w, &this->position.h);
        SDL_FreeSurface(surface);
}

void UILabel::draw()
{
    SDL_RenderCopy(Engine::renderer, this->labelTexture, nullptr, &this->position);
    SDL_DestroyTexture(this->labelTexture);
}
