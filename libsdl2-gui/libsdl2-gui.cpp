#include <libsdl2-gui/libsdl2-gui.hpp>

int GuiInitSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) < 0) {
		std::cerr << "[libsdl2-gui/libsdl2-gui.cpp:46] ERROR SDL could not initialize!\n\tSDL Error: " << SDL_GetError() << std::endl;
		return -1;
	}

   //Initialize SDL_ttf
    if(TTF_Init() == -1)
    {
        std::cerr << "[libsdl2-gui/libsdl2-gui.cpp:53] ERROR SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
        return -2;
    }

    return 0;
}

int GuiCloseSDL()
{
    TTF_Quit();
    SDL_Quit();

    return 0;
}
