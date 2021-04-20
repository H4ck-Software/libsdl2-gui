#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>

#include <libsdl2-gui/transform.hpp>

//namespace 
//{
    class Window
    {
    public:
        Window(int width, int height, std::string window_title, uint32_t window_flags = (SDL_WINDOW_SHOWN | SDL_RENDERER_ACCELERATED));
        ~Window();

        void OnRender();

        int AddRenderCallback(void(*callback)(SDL_Renderer*));

        SDL_Window* get_sdlwindow();
    protected:
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;

        Transform2d transform;

        std::vector<void(*)(SDL_Renderer*)> render_callbacks;
    };
//}
