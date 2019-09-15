#ifndef COOL_WINDOW_H
#define COOL_WINDOW_H

#include "config.h"
#include "util/vector.h"

namespace cool {

    //typedef SDL_Window WindowRaw;
    //using WindowRaw = SDL_Window;

    class Window {
        public:
            Window();
            virtual ~Window();

            bool create(int w = 640, int h = 480, std::string t = "coolEngine Game");

            cool::Vector2u getMode();
            void setMode(int w = 640, int h = 480);
            void setTitle(std::string title);
            bool setFullscreen(bool td);

            void quit();

        public:
            static SDL_Window *rWindow; //<----------------------

            int width, height;
            std::string title;
    };

}

#endif // WINDOW_H
