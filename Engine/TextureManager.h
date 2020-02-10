#ifndef TEXUREMANAGER_H
#define TEXUREMANAGER_H

#include "Engine.h"

class TextureManager
{
public:
    TextureManager();
    ~TextureManager();
    
    static SDL_Texture* load(const std::string& fileName);
    /**
     * @brief It draws the texture on the screen, take note that this method will not render
     * the texture if it is out of the screen (camera).
     * @param texture
     * @param source
     * @param destination
     * @param flip
     */
    static void draw(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination, SDL_RendererFlip flip);
};

#endif // TEXUREMANAGER_H
