#include "assets.h"

namespace cool {

    AssetManager::AssetManager() {}

    AssetManager::~AssetManager() {}

    void AssetManager::loadTexture(std::string name, std::string path) {

        //std::string totalPath = getPath("") + path;
        SDL_Texture *tex;
        SDL_Surface *image;

        image = SDL_LoadBMP(path.c_str());

        if(image != NULL) {
            tex = SDL_CreateTextureFromSurface(renderer.rRenderer, image);
            SDL_FreeSurface(image);

            if(tex == NULL) {
                printf("Cannot create texture\n");
            }
        }
        else {
            printf("Cannot load image: %s\n", path.c_str());
            loadTexture(name, "no_image.bmp");
        }
        textures[name] = tex;
    }

    SDL_Texture* AssetManager::getTexture(std::string name) {
        if(textures.empty()) {
            printf("texture array is empty\n");
            return NULL;
        }
        return textures[name];
    }

    void AssetManager::setRenderer(cool::Renderer &ren) {
        renderer = ren;
    }
}
