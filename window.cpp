#include "window.h"

namespace raven2d {

    SDL_Window *Window::rWindow = NULL;

    Window::Window()
        /*: rWindow(NULL)*/ { }

    Window::~Window() {
        SDL_DestroyWindow(rWindow);
    }

    bool Window::create(int w, int h, std::string t) {
        rWindow = SDL_CreateWindow(t.c_str(), SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  w, h, SDL_WINDOW_SHOWN | SDL_WINDOW_ALWAYS_ON_TOP);

        if(rWindow == NULL) {
            printf("Cannot create window: %s\n", SDL_GetError());
            return false;
        }
        else {
            width = w; height = h; title = t;
        }
        return true;
    }

    void Window::quit() {
        SDL_DestroyWindow(rWindow);
    }

    raven2d::Vector2u Window::getMode() {
        raven2d::Vector2u i(width, height);
        //SDL_GetWindowSize(rWindow, (int*)&i.x, (int*)&i.y);
        return i;
    }

    void Window::setMode(int w, int h) {

        if(rWindow == NULL) create(w, h);
        else {
            SDL_SetWindowSize(rWindow, w, h);
            width = w, height = h;
        }
    }

    void Window::setTitle(std::string title) {
        SDL_SetWindowTitle(rWindow, title.c_str());
    }

    bool Window::setFullscreen(bool td) {
        int i = td ? SDL_WINDOW_FULLSCREEN : 0;
        if(SDL_SetWindowFullscreen(rWindow, i) != 0) return false;
        return true;
    }

}
