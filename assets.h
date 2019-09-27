#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include "config.h"
#include "renderer.h"
/*
namespace {
    std::string getPath(const std::string &dir) {

        const char pathDelimiter = '\\';
        std::string path;

        char *basePath = SDL_GetBasePath();
        if(basePath) {
            path = basePath;
            SDL_free(base_path);
        }
        else {
            printf("raven2dEngine: SDL: Cannot get base path.\n");
            return "";
        }

        size_t pos = path.rfind("bin");

        if(dir == "") path = path.substr(0, pos);
        else path = path.substr(0, pos) + dir + pathDelimiter;

        return path;

    }
}
*/
namespace raven2d {
    class AssetManager {
        public:
            AssetManager();
            virtual ~AssetManager();

            void loadTexture(std::string name, std::string path);
            SDL_Texture* getTexture(std::string name);

        public:
            void setRenderer(raven2d::Renderer &ren);

        protected:
            std::map<std::string, SDL_Texture*> textures;

        private:
            raven2d::Renderer renderer;

    };
}

#endif // ASSETMANAGER_H
