#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

/**
 * \brief Initialize SDL.
 * 
 * \return A non-zero value on error.
 */
extern int GuiInitSDL();

extern int GuiCloseSDL();
