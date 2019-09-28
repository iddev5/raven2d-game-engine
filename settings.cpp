#include "settings.h"

namespace raven2d {

    Settings::Settings() { }
    Settings::~Settings(){ }

    void Settings::setFramerateLimit(int frames) {
        framerateLimit = frames;
    }

    int  Settings::getFramerateLimit() {
        return framerateLimit;
    }

    real Settings::getFramerate() {
        return fpsAvg;
    }

    void Settings::enableVSync(bool dec) {
        if(dec) SDL_GL_SetSwapInterval(1);
        else    SDL_GL_SetSwapInterval(0);
    }

    int  Settings::getVSyncStatus() {
        return SDL_GL_GetSwapInterval();
    }

}
