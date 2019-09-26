#ifndef COOL_RR_CONFIG_H
#define COOL_RR_CONFIG_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <memory>
#include <map>
#include <functional>

#include <stdio.h>
#include <stdlib.h>
#include <ctime>

#include <windows.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

typedef signed char word;
typedef unsigned char uword;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned long ulong;
typedef float real;
typedef double breal;

namespace raven2d {
    inline bool Error(std::string str) {
        printf("[ERROR] %s\n", str.c_str());
        return false;
    }

    inline void Warn(std::string str) {
        printf("[WARNING] %s\n", str.c_str());
    }

    inline std::string toCCString(const char *cstr) {
        std::string s(cstr);
        return s;
    }
}

#endif
