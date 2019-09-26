#include "../objects.h"

namespace cool {
	GameObject::GameObject(std::string namev, int xv, int yv):
		name(namev), type("node"), x(xv), y(yv), firstUpdate(true), isPaused(false) { }

	GameObject::GameObject(std::string namev, cool::Vector2i pv):
		name(namev), x(pv.x), y(pv.y), firstUpdate(true), isPaused(false) { }

	GameObject::~GameObject() { }

	void GameObject::pause()  { isPaused = true;  }
	void GameObject::resume() { isPaused = false; }

	void GameObject::move(int xv, int yv) {
		if(!isPaused) {
			x += xv;
			y += yv;
			if(child != nullptr) {
				child->x += xv;
				child->y += yv;
			}
		}
	}

	void GameObject::reorder(int zv) {
		if(!isPaused) {
			zOrder += zv;
			if(child != nullptr)
				child->zOrder += zv;
		}
	}

	void GameObject::scale(int sxv, int syv) {
		if(!isPaused) {
			scaleX += sxv;
			scaleY += syv;
			if(child != nullptr) {
				child->scaleX += sxv;
				child->scaleY += syv;
			}
		}
	}

	void GameObject::rotate(short av) {
		if(!isPaused) {
			angle += av;
			if(child != nullptr) child->angle += av;
		}
	}

	void GameObject::flip(int fv) {
		if(!isPaused) {
			(fv == 0 ? flipHoriz = true :
			(fv == 1 ? flipVert = true:
			(flipHoriz = flipVert = false)));

			if(child != nullptr) {
				(fv == 0 ? child->flipHoriz = true :
				(fv == 1 ? child->flipVert = true:
				(child->flipHoriz = child->flipVert = false)));
			}
		}
	}

	bool GameObject::isFlipped(int fv) {
		return (fv == 0 ? flipHoriz : (fv == 1 ? flipVert : 0));
	}

	void GameObject::update(SDL_Renderer *renderer) {
		if(!isPaused) {
			if(firstUpdate) {
				onCreate();
				firstUpdate = false;
			}
			onStep(renderer);
			//if(child != nullptr) child->update();
		}
	}
}
