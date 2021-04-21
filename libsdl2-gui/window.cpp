#include <libsdl2-gui/libsdl2-gui.hpp>
#include <libsdl2-gui/window.hpp>

Window::Window(int width, int height, std::string window_title, uint32_t window_flags)
{
    SDL_CreateWindowAndRenderer(width, height, window_flags, &this->window, &this->renderer);

    if(this->window == NULL) {
        std::cerr << "[libsdl2-gui//window.cpp:9] ERROR Failed to create an SDL2 Window!" << std::endl;
        return;
    }

    std::cout << "[libsdl2-gui/window.cpp:13] INFO SDL2 Window Created Successfully!" << std::endl;

    SDL_SetWindowTitle(this->window, window_title.c_str());
    
    this->transform.scale.x = width; 
    this->transform.scale.y = height;
    return;
}

Window::~Window()
{
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    return;
}

void Window::OnRender()
{
    //SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    //SDL_RenderClear(this->renderer);

    for(std::vector<void (* ) (SDL_Renderer * )>::size_type i = 0; i < this->render_callbacks.size(); i++) {
        if(this->render_callbacks.at(i) != NULL)
            this->render_callbacks.at(i) (this->renderer);
    }

    //SDL_RenderPresent(this->renderer);

    return;
}

int Window::AddRenderCallback(void(*callback) (SDL_Renderer * ))
{
    this->render_callbacks.push_back(callback);
    if (this->render_callbacks.at(this->render_callbacks.size() - 1) != callback) {
        return -1;
    }

    return (this->render_callbacks.size() - 1);
}

SDL_Window* Window::get_sdlwindow()
{
    return this->window;
}
