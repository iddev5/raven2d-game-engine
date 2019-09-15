#define COOLDEBUG
#include "coolEngine.h"

cool::Sprite spr("spr", 10, 10);
cool::Timer thisTime;
int i = 1;
real OldTime, NewTime;
//static SDL_Texture *tex = NULL;

class crowbar: public cool::Game {
public:
    crowbar() {
        AppName = "sdl game engine";
        setFramerateLimit(60);
    }

    bool atBegining() override {
        asset.loadTexture("tex", "test.bmp");

        spr.texture = asset.getTexture("tex");

        renderer.clear(255, 255, 255);

        thisTime.start();
        OldTime = thisTime.getTimeElapsed();

        return true;
    }

    bool atStep() override {

        //renderer.clear(rand() % 255, rand() % 255, rand() % 255);

        window.setTitle("SDL Game Engine: FPS: " + std::to_string(getFramerate()));

        NewTime = thisTime.getTimeElapsed();
        if(OldTime <= (NewTime-2)) {
            i++;
            renderer.setPixelSize(i, i);
            OldTime = NewTime;
        }

        renderer.clear(255, 255, 255);
        renderer.drawBorderedRect(10, 10, 30, 40, cool::ColourList::Orange, cool::ColourList::Black);
        //renderer.drawBorderedCircle(200, 200, 100, cool::ColourList::Cyan, cool::ColourList::Black);

        //std::cout << "OldTime: " << OldTime << " , NewTime: " << NewTime << std::endl;
        //std::cout << "Timer: " << thisTime.getTimeElapsed() << std::endl;
        //spr.x = 320-(spr.scaleX/2);
        //spr.y = 240-(spr.scaleY/2);
        //spr.rotate(1);
        //spr.update(renderer.rRenderer);

        return true;
    }
};

int main(int argc, char **argv) {

    crowbar crowbargame;

    crowbargame.create();
    crowbargame.start();

    return 0;
}
