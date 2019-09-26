#include "game.h"

namespace cool {

    Game::Game(): isRunning(true), isFirstFrame(true) {
        init();
    }

    Game::~Game() {
        quit();
    }

	// Initialization command
	bool Game::init(int flags) {

        srand(time(NULL));
		if(SDL_Init(flags) != 0) {
			printf("Couldn't initialise: %s\n", SDL_GetError());
			return false;
		}

		//Initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        if(!(IMG_Init(imgFlags)&imgFlags)) {
            printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
            return false;
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
            printf("coolEngine exit call: cool::Game::quit\n");
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

	    cool::Timer fpsTimer;
	    cool::Timer frmTimer;

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
                cool::Wait(ticksPerFrame - frmTicks);

            //std::cout << "Delaying time: " << ticksPerFrame - frmTicks << std::endl;
		}

        quit();
	}
}
