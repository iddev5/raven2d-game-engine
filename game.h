#ifndef COOL_RR_ENGINE
#define COOL_RR_ENGINE

#include "config.h"
#include "window.h"
#include "renderer.h"
#include "settings.h"
#include "assets.h"
#include "timer.h"

namespace raven2d {

    class Window;
    class Renderer;
    class Settings;
    class GameObject;
    class Sprite;

	class Game {
    public:
        Game();
        //Game(int w = 640, int h = 480);
        virtual ~Game();

        void create(int w = 640, int h = 480);
        void quit();

        virtual bool atBegining();
        virtual bool atStep();
        virtual bool atDestroy();

        void start();

    public:
        raven2d::Window   window;
        raven2d::Settings settings;
        raven2d::Renderer renderer;
        raven2d::AssetManager asset;

        bool isRunning;
        bool isFirstFrame;

        std::string AppName;

    private:
        bool init();
	};

}

#endif
