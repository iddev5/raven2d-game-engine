#ifndef COOL_RR_ENGINE
#define COOL_RR_ENGINE

#include "config.h"
#include "window.h"
#include "renderer.h"
#include "assets.h"
#include "timer.h"

namespace cool {

    class Window;
    class Renderer;
    class GameObject;
    class Sprite;

	class Game {
    public:
        Game();
        //Game(int w = 640, int h = 480);
        virtual ~Game();

        void create(int w = 640, int h = 480);
        void quit();

        void setFramerateLimit(int frames);
        int  getFramerateLimit();
        real getFramerate();

        virtual bool atBegining();
        virtual bool atStep();
        virtual bool atDestroy();

        void start();

    public:
        cool::Renderer renderer;
        cool::Window   window;
        cool::AssetManager asset;

        bool isRunning;
        bool isFirstFrame;

        std::string AppName;

    private:
        real fpsAvg;
        bool init();
        int framerateLimit;

	};

}

#endif
