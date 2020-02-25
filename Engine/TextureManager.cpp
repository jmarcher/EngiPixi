#include "TextureManager.h"

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

SDL_Texture* TextureManager::load(const std::string& fileName)
{
    SDL_Texture* result;
    SDL_Surface* temporalSurface = IMG_Load(fileName.c_str());
    ASSERT_MSG(temporalSurface != nullptr, "Image could not be loaded");
    result = SDL_CreateTextureFromSurface(Engine::renderer, temporalSurface);
    ASSERT_MSG(result != nullptr, "Texture could not be loaded " << SDL_GetError());
    SDL_FreeSurface(temporalSurface);

    return result;
}

void TextureManager::draw(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination, SDL_RendererFlip flip)
{
    // Now we check if we need to render the texture or not.
    if(destination.x < (Engine::camera.w + destination.w) && destination.x >= ((-1) * destination.w))
        if(destination.y < (Engine::camera.h + destination.h) && destination.y >= ((-1) * destination.h))
            SDL_RenderCopyEx(Engine::renderer, texture, &source, &destination, 0, NULL, flip);
}
