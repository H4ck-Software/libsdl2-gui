#pragma once

#include <string>

#include <libyardland/gui/gui.hpp>

/**
 * \brief Texture wrapper class.
 */
class Texture
{
public:
    /**
     * \brief Initializes variables.
     */
    Texture();

    /** 
     * \brief Deallocates memory.
     */
    ~Texture();

    /**
     * \brief Loads image at specified path.
     */
    int LoadFromFile(std::string path);

    /**
     * \brief Load texture from text.
     */
    int LoadFromRenderedText(std::string textureText, SDL_Color textColor, TTF_Font* font = GuiFont);

    /** 
     * \brief Renders texture at given point
     */
    void OnRender(SDL_Renderer* renderer);

    /**
     * \brief Transform2D.
     */
    struct transform
    {
        /**
         * \brief The scale of this texture.
         */
        Vector2 scale;
        
        /**
         * \brief The position of this texture.
         */
        Vector2 position;
    } 
    /**
     * \brief The transform of this texture.
     */
    transform;

    SDL_Rect* clip = NULL;
    double angle = 0.0;
    SDL_Point* center = NULL;
    SDL_RendererFlip flip = SDL_FLIP_NONE;

protected:
    /** 
     * \brief Deallocates texture.
     */
    void FreeTexture();

private:
    /** 
     * The actual hardware texture.
     */
    SDL_Texture* mTexture;
    SDL_Surface* surface;
};
