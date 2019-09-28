#include "renderer.h"

namespace raven2d {

    SDL_Renderer *Renderer::rRenderer = NULL;

    bool Renderer::create(SDL_Window *window) {
        SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");

        rRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if(rRenderer == NULL) {
            printf("Cannot create renderer: %s", SDL_GetError());
            return false;
        }

        return true;
    }

    void Renderer::quit() {
        if(rRenderer != NULL)
            SDL_DestroyRenderer(rRenderer);
    }

    bool Renderer::clear(uint r, uint g, uint b, uint a) {
        if(SDL_SetRenderDrawColor(rRenderer, r, g, b, a ) != 0) return false;
        else {
            if(SDL_RenderClear(rRenderer) != 0) {
                printf("Cannot clear screen: %s\n", SDL_GetError());
                return false;
            }
        }
        return true;
    }

    bool Renderer::clear(const raven2d::Colour &colour) {
        if(clear(colour.r, colour.g, colour.b) == false) return false;
        return true;
    }

    void Renderer::setPixelSize(real xSize, real ySize) {
        SDL_RenderSetScale(rRenderer, xSize, ySize);
    }

    /* DRAWING FUNCTIONS */
    // Point
    bool Renderer::drawPoint(int x, int y, const raven2d::Colour &c) {
        priv_setColour(c);
        if(SDL_RenderDrawPoint(rRenderer, x, y) != 0) return false;
        return true;

    }

    // Line
    bool Renderer::drawLine(int x1, int y1, int x2, int y2, const raven2d::Colour &c) {
        priv_setColour(c);
        if(SDL_RenderDrawLine(rRenderer ,x1, y1, x2, y2) != 0) return false;
        return true;
    }

    // Rectangle
    bool Renderer::drawRect(int x, int y, int w, int h, const raven2d::Colour &c) {
        priv_initRectSettings(x, y, w, h, c);
        SDL_Rect i = {x, y, w, h};

        priv_setColour(c);
        if(SDL_RenderDrawRect(rRenderer, &i) != 0) return false;
        return true;

    }

    bool Renderer::drawFilledRect(int x, int y, int w, int h, const raven2d::Colour &c) {
        priv_initRectSettings(x, y, w, h, c);
        SDL_Rect i = {x, y, w, h};

        priv_setColour(c);
        if(SDL_RenderFillRect(rRenderer, &i) != 0) return false;
        return true;
    }

    bool Renderer::drawBorderedRect(int x, int y, int w, int h, const raven2d::Colour &c1, const raven2d::Colour &c2) {
        bool result = false;
        result |= drawFilledRect(x, y, w, h, c1);
        result |= drawRect(x, y, w, h, c2);
        return result;
    }

    // Circles
    bool Renderer::drawCircle(int x, int y, int radius, const raven2d::Colour &c) {
		int x0 = 0;
		int y0 = radius;
		int d = 3 - 2 * radius;
		if (!radius) return false;

		while (y0 >= x0)
		{
            drawPoint(x + x0, y - y0, c);
			drawPoint(x + y0, y - x0, c);
			drawPoint(x + y0, y + x0, c);
			drawPoint(x + x0, y + y0, c);
			drawPoint(x - x0, y + y0, c);
			drawPoint(x - y0, y + x0, c);
			drawPoint(x - y0, y - x0, c);
            drawPoint(x - x0, y - y0, c);
			if (d < 0) d += 4 * x0++ + 6;
			else d += 4 * (x0++ - y0--) + 10;
		}

		return true;
	}

	bool Renderer::drawFilledCircle(int x, int y, int radius, const raven2d::Colour &c) {
		// Taken from wikipedia
		int x0 = 0;
		int y0 = radius;
		int d = 3 - 2 * radius;
		if (!radius) return false;
        /*
		auto drawline = [&](int sx, int ex, int ny) {
		    drawLine(sx, ny, ex, ny, c);
		};
        */

		while (y0 >= x0)
		{
			// Modified to draw scan-lines instead of edges
			drawLine(x - x0, y - y0, x + x0, y - y0, c);
			drawLine(x - y0, y - x0, x + y0, y - x0, c);
			drawLine(x - x0, y + y0, x + x0, y + y0, c);
			drawLine(x - y0, y + x0, x + y0, y + x0, c);

			if (d < 0) d += 4 * x0++ + 6;
			else d += 4 * (x0++ - y0--) + 10;
		}

		return true;
	}

	bool Renderer::drawBorderedCircle(int x, int y, int radius, const raven2d::Colour &c1, const raven2d::Colour &c2) {
        bool result = false;
        result |= drawFilledCircle(x, y, radius, c1);
        result |= drawCircle(x, y, radius, c2);
        return result;
	}

	// Images
    bool Renderer::drawTexture(int x, int y, SDL_Texture *tex) {
        int w, h;
        SDL_Rect dst;

        if(SDL_QueryTexture(tex, NULL, NULL, &w, &h) != 0) printf("Cannot query texture\n");
        else {
            dst.w = w; dst.h = h;
        }

        if(SDL_RenderCopy(rRenderer, tex, NULL, &dst) != 0) return false;
        return true;
    }

    // Objects
    void Renderer::updateSpriteObject(raven2d::GameObject *obj) {
        obj->update(rRenderer);
    }

    /* PRIVATE FUNCTIONS */
    bool Renderer::priv_setColour(const raven2d::Colour &col) {
        if(SDL_SetRenderDrawColor(rRenderer, col.r, col.g, col.b, col.a) != 0) return false;
        return true;
    }

    void Renderer::priv_initRectSettings(int x, int y, int w, int h, const raven2d::Colour &c) {

        /* Test for special case - horizontal line, vertical line, point */
        if(w==0) {
            if(h==0) drawPoint(x, y, c);    /* Point */
            else drawLine(x, y, x, y+h, c); /* Horizontal Line */
        }
        else {
            if(h==0) drawLine(x, y, x+w, y, c); /* Vertical Line */
        }
    }
}
