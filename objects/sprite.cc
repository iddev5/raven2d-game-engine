#include "../objects.h"

namespace raven2d {
	Sprite::Sprite(std::string name, int xp, int yp):
		GameObject::GameObject(name, xp, yp), texture(NULL)
    {
        GameObject::type = "sprite";
    }

	Sprite::Sprite(std::string name, raven2d::Vector2i pv):
		GameObject::GameObject(name, pv.x, pv.y), texture(NULL) { }

    Sprite::~Sprite() { onDestroy(); }

    void Sprite::onCreate() {
        int x, y;

		if(texture != NULL)
			SDL_QueryTexture(texture, NULL, NULL, &x, &y);

        GameObject::scaleX = x;
        GameObject::scaleY = y;
	}

    void Sprite::onStep(SDL_Renderer *renderer) {
		if(changed) {
			if(texture != NULL)
				SDL_QueryTexture(texture, NULL, NULL,
					(int*)GameObject::scaleX, (int*)GameObject::scaleY);
			changed = false;
		}

        rfp = GameObject::flipHoriz ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE|
              GameObject::flipVert  ? SDL_FLIP_VERTICAL   : SDL_FLIP_NONE;

        dst = { GameObject::x, GameObject::y, GameObject::scaleX, GameObject::scaleY };

        SDL_RenderCopyEx(renderer, texture, NULL, &dst, GameObject::angle, NULL, rfp);
	}

    void Sprite::onDestroy() {
		SDL_DestroyTexture(texture);
	}

	void Sprite::update(SDL_Renderer *renderer) {
        if(!GameObject::isPaused) {
			if(GameObject::firstUpdate) {
				onCreate();
				firstUpdate = false;
			}
			onStep(renderer);
			//if(GameObject::child != nullptr) child->update();
		}
    }

}
