#define COOLDEBUG
#include "raven2dEngine.h"

raven2d::Sprite spr("spr", 10, 10);
raven2d::Timer thisTime;
int i = 1;
real OldTime, NewTime;

class crowbar: public raven2d::Game {
public:
    crowbar() {
        AppName = "sdl game engine";
        settings.setFramerateLimit(60);

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

        window.setTitle("SDL Game Engine: FPS: " + std::to_string(settings.getFramerate()));

        NewTime = thisTime.getTimeElapsed();
        if(OldTime <= (NewTime-2)) {
            i++;
            renderer.setPixelSize(i, i);
            OldTime = NewTime;
        }

        renderer.clear(255, 255, 255);
        renderer.drawBorderedRect(10, 10, 30, 40, raven2d::ColourList::Orange, raven2d::ColourList::Black);
        renderer.drawBorderedCircle(200, 200, 25, raven2d::ColourList::Cyan, raven2d::ColourList::Black);

        spr.x = 320-(spr.scaleX/2);
        spr.y = 240-(spr.scaleY/2);
        //spr.rotate(1);
        spr.update(renderer.rRenderer);

        return true;
    }
};

int main(int argc, char **argv) {

    crowbar crowbargame;

    crowbargame.create();
    crowbargame.start();

    return 0;
}
