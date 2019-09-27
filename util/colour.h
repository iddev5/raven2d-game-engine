#ifndef COOL_RR_UTIL_COLOUR
#define COOL_RR_UTIL_COLOUR

namespace raven2d {
    class Colour {
    public:
        Colour() { }

        Colour(uint rv, uint gv, uint bv, uint av = 255):
            r(rv), g(gv), b(bv), a(av) { }

        Colour(const raven2d::Colour &colour):
            r(colour.r), g(colour.g), b(colour.b), a(colour.a) { }

        uint r, g, b, a;
    };

    namespace ColourList {
        static const raven2d::Colour
            White(255, 255, 255), Black(0, 0, 0), Blank(0, 0, 0, 0),
            Grey (192, 192, 192), DarkGrey (128, 128, 128),
		    Red  (255, 0, 0),     DarkRed  (128, 0, 0),
            Green(0, 255, 0),     DarkGreen(0, 128, 0),
            Blue (0, 0, 255),     DarkBlue (0, 0, 128),
            Yellow(255, 255, 0), Cyan  (0, 255, 255), Magenta(255, 0, 255),
            Orange(255,165,0),   Violet(238,130,238), Fuchsia(255, 0, 255);
    }
}

#endif

