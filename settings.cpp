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


}
