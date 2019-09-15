#include "../objects.h"

namespace cool {
	Sprite::Sprite(std::string name, int xp, int yp):
		Node::Node(name, xp, yp), texture(NULL)
    {
        Node::type = "sprite";
    }

	Sprite::Sprite(std::string name, cool::Vector2i pv):
		Node::Node(name, pv.x, pv.y), texture(NULL) { }

    Sprite::~Sprite() { onDestroy(); }

    void Sprite::onCreate() {
        int x, y;

		if(texture != NULL)
			SDL_QueryTexture(texture, NULL, NULL, &x, &y);

        Node::scaleX = x;
        Node::scaleY = y;
	}

    void Sprite::onStep(SDL_Renderer *renderer) {
		if(changed) {
			if(texture != NULL)
				SDL_QueryTexture(texture, NULL, NULL,
					(int*)Node::scaleX, (int*)Node::scaleY);
			changed = false;
		}

        rfp = Node::flipHoriz ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE|
              Node::flipVert  ? SDL_FLIP_VERTICAL   : SDL_FLIP_NONE;

        dst = { Node::x, Node::y, Node::scaleX, Node::scaleY };

        SDL_RenderCopyEx(renderer, texture, NULL, &dst, Node::angle, NULL, rfp);
	}

    void Sprite::onDestroy() {
		SDL_DestroyTexture(texture);
	}

	void Sprite::update(SDL_Renderer *renderer) {
        if(!Node::isPaused) {
			if(Node::firstUpdate) {
				onCreate();
				firstUpdate = false;
			}
			onStep(renderer);
			//if(Node::child != nullptr) child->update();
		}
    }

}
