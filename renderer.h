#ifndef COOL_RR_DISPLAY
#define COOL_RR_DISPLAY

#include "config.h"
#include "window.h"
#include "objects.h"
#include "util/colour.h"
#include "util/vector.h"

namespace cool {

    class Node;
	class Renderer {
    public:
        bool create(SDL_Window *window);

        void quit();

		bool clear(uint r=0, uint g=0, uint b=0, uint a=255);
		bool clear(const cool::Colour &colour);

		void setPixelSize(real xSize, real ySize);

		bool drawPoint(int x, int y, const cool::Colour &c);
		bool drawLine(int x1, int y1, int x2, int y2, const cool::Colour &c);
		bool drawRect(int x, int y, int w, int h, const cool::Colour &c);
        bool drawFilledRect(int x, int y, int w, int h, const cool::Colour &c);
		bool drawBorderedRect(int x, int y, int w, int h, const cool::Colour &c1, const cool::Colour &c2);
        bool drawCircle(int x, int y, int radius, const cool::Colour &c);
        bool drawFilledCircle(int x, int y, int radius, const cool::Colour &c);
        bool drawBorderedCircle(int x, int y, int radius, const cool::Colour &c1, const cool::Colour &c2);
        bool drawTexture(int x, int y, SDL_Texture *tex);

        void updateSpriteObject(cool::Node *obj);

	public:
		static SDL_Renderer *rRenderer;

    private:
        bool priv_setColour(const cool::Colour &col);
        void priv_initRectSettings(int x, int y, int w, int h, const cool::Colour &c);

	};

}

#endif
