#include "timer.h"

namespace cool {

    void Wait(int ms) {
        /* The reason SDL_Delay() is used instead of Sleep()
         * is that, SDL_Delay() contains some more security. */
        SDL_Delay(ms);
    }

    Timer::Timer() {
        //Initialize the variables
        mStartTicks = 0;
        mPausedTicks = 0;

        mPaused = false;
        mRunning = false;
    }

    Timer::~Timer() { }

    void Timer::start() {
        mRunning = true;
        mPaused = false;

        //Get the current clock time
        mStartTicks = SDL_GetTicks();
        mPausedTicks = 0;
    }

    void Timer::stop() {
        mRunning = false;
        mPaused = false;

        //Clear tick variables
        mStartTicks = 0;
        mPausedTicks = 0;
    }

    void Timer::pause() {
        if( mRunning && !mPaused )
        {
            //Pause the timer
            mPaused = true;

            //Calculate the paused ticks
            mPausedTicks = SDL_GetTicks() - mStartTicks;
            mStartTicks = 0;
        }
    }

    real Timer::getTimeElapsed() {
        real time = 0;

        if( mRunning ) {
            if( mPaused ) {
                //Return the number of ticks when the timer was paused
                time = mPausedTicks;
            }
            else {
                //Return the current time minus the start time
                time = SDL_GetTicks() - mStartTicks;
            }
        }

        return time/1000.0f;
    }

    bool Timer::isRunning() {
        return mRunning;
    }

    bool Timer::isPaused() {
        return mPaused;
    }


}
