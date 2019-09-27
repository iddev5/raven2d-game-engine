#include "assets.h"

namespace raven2d {

    AssetManager::AssetManager() {}

    AssetManager::~AssetManager() {}

    void AssetManager::loadTexture(std::string name, std::string path) {

        //std::string totalPath = getPath("") + path;
        SDL_Texture *tex;
        SDL_Surface *image;

        //image = SDL_LoadBMP(path.c_str());
        image = IMG_Load(path.c_str());

        if(image != NULL) {
            tex = SDL_CreateTextureFromSurface(renderer.rRenderer, image);
            SDL_FreeSurface(image);

            if(tex == NULL) {
                raven2d::Warn("Cannot create texture of image: " + name);
            }
        }
        else {
            raven2d::Warn("Cannot load image: " + path + " : " + raven2d::toCCString(IMG_GetError()));
            loadTexture(name, "no_image.bmp");
        }
        textures[name] = tex;
    }

    SDL_Texture* AssetManager::getTexture(std::string name) {
        if(textures.empty()) {
            raven2d::Warn("Texture Array is empty");
            return NULL;
        }
        return textures[name];
    }

    void AssetManager::setRenderer(raven2d::Renderer &ren) {
        renderer = ren;
    }
}
