#include "game.h"

namespace raven2d {

    Game::Game(): isRunning(true), isFirstFrame(true) {
        init();
    }

    Game::~Game() {
        quit();
    }

	/* Initialization command */
	bool Game::init() {

        srand(time(NULL));
        int flags = SDL_INIT_VIDEO;
		if(SDL_Init(flags) != 0) {
			//printf("[ERROR] Couldn't initialize: %s\n", SDL_GetError());
			//return false;
			raven2d::Error("Could not initialize SDL: " + raven2d::toCCString(SDL_GetError()));
		}

		/* Initialize PNG loading */
        int imgflags = IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF;
        if(!(IMG_Init(imgflags)&imgflags)) {
            //printf("[ERROR] Could not initialize SDL_image: %s\n", IMG_GetError());
            //return false;
            raven2d::Error("Could not initialize SDL_image: " + raven2d::toCCString(IMG_GetError()));
        }

		asset.setRenderer(renderer);

		return true;

	}

	void Game::create(int w, int h) {
        window.create(w, h, AppName);
        renderer.create(window.rWindow);
	}

	void Game::quit() {
		atDestroy();
        //#if defined(COOLDEBUG)
            printf("raven2d exit call: raven2d::Game.quit()\n");
        //#endif
	    renderer.quit();
		window.quit();
		IMG_Quit();
		SDL_Quit();
	}

    void Game::setFramerateLimit(int frames) {
        framerateLimit = frames;
    }

    int  Game::getFramerateLimit() {
        return framerateLimit;
    }

    real Game::getFramerate() {
        return fpsAvg;
    }

	bool Game::atBegining() {
		return false;
	}

	bool Game::atStep() {
		return false;
	}

	bool Game::atDestroy() {
		return true;
	}

	void Game::start() {

	    raven2d::Timer fpsTimer;
	    raven2d::Timer frmTimer;

		SDL_Event event;

        int frames = 0;
        fpsTimer.start();
		while(isRunning) {

            frmTimer.start();

            SDL_PollEvent(&event);
			if(event.type == SDL_QUIT) isRunning = false;

            fpsAvg = frames/fpsTimer.getTimeElapsed();
			if(fpsAvg > 20000) fpsAvg = 0.0f;

			//std::cout << "Average FPS: " << fpsAvg << std::endl;

			if(isFirstFrame) {
				atBegining();
				isFirstFrame = false;
			}
			atStep();

			if(renderer.rRenderer != NULL) {
				SDL_RenderPresent(renderer.rRenderer);
			}

			frames++;

			int frmTicks = frmTimer.getTimeElapsed()*1000;
			int ticksPerFrame = 1000/getFramerateLimit();

			//std::cout << "frm Ticks: " << frmTicks << " , ticksPerFrame: " << ticksPerFrame << std::endl;

			if(frmTicks < ticksPerFrame)
                raven2d::Wait(ticksPerFrame - frmTicks);

            //std::cout << "Delaying time: " << ticksPerFrame - frmTicks << std::endl;
		}

        quit();
	}
}
