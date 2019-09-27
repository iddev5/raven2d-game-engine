#ifndef COOL_TIMER_H
#define COOL_TIMER_H

#include "config.h"

namespace raven2d {

    void Wait(int ms);

    class Timer {
        public:
            Timer();
            virtual ~Timer();

            //The various clock actions
            void start();
            void stop();
            void pause();
            void unpause();

            //Gets the timer's time
            real getTimeElapsed();

            //Checks the status of the timer
            bool isRunning();
            bool isPaused();

        private:
            //The clock time when the timer started
            uint32_t mStartTicks;

            //The ticks stored when the timer was paused
            uint32_t mPausedTicks;

            //The timer status
            bool mPaused;
            bool mRunning;
    };

}

#endif // COOL_TIMER_H
