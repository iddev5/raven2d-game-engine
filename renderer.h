#ifndef COOL_RR_DISPLAY
#define COOL_RR_DISPLAY

#include "config.h"
#include "window.h"
#include "objects.h"
#include "util/colour.h"
#include "util/vector.h"

namespace raven2d {

    class GameObject;
	class Renderer {
    public:
        bool create(SDL_Window *window);

        void quit();

		bool clear(uint r=0, uint g=0, uint b=0, uint a=255);
		bool clear(const raven2d::Colour &colour);

		void setPixelSize(real xSize, real ySize);

		bool drawPoint(int x, int y, const raven2d::Colour &c);
		bool drawLine(int x1, int y1, int x2, int y2, const raven2d::Colour &c);
		bool drawRect(int x, int y, int w, int h, const raven2d::Colour &c);
        bool drawFilledRect(int x, int y, int w, int h, const raven2d::Colour &c);
		bool drawBorderedRect(int x, int y, int w, int h, const raven2d::Colour &c1, const raven2d::Colour &c2);
        bool drawCircle(int x, int y, int radius, const raven2d::Colour &c);
        bool drawFilledCircle(int x, int y, int radius, const raven2d::Colour &c);
        bool drawBorderedCircle(int x, int y, int radius, const raven2d::Colour &c1, const raven2d::Colour &c2);
        bool drawTexture(int x, int y, SDL_Texture *tex);

        void updateSpriteObject(raven2d::GameObject *obj);

	public:
		static SDL_Renderer *rRenderer;

    private:
        bool priv_setColour(const raven2d::Colour &col);
        void priv_initRectSettings(int x, int y, int w, int h, const raven2d::Colour &c);

	};

}

#endif
