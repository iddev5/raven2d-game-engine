#ifndef RAVEN2D_SETTINGS_H
#define RAVEN2D_SETTINGS_H

#include "config.h"

namespace raven2d {

    class Settings
    {
        public:
            Settings();
            virtual ~Settings();

            void setFramerateLimit(int frames);
            int  getFramerateLimit();
            real getFramerate();

            void enableVSync(bool dec);
            int  getVSyncStatus();

            real fpsAvg;
            int  framerateLimit;

    };
}

#endif // RAVEN2D_SETTINGS_H
