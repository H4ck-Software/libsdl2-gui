#pragma once

#include <string>

#include <libsdl2-gui/libsdl2-gui.hpp>
#include <libsdl2-gui/transform.hpp>

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
     * \brief The transform of this texture.
     */
    Transform2d transform;

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
