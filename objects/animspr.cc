// WIP (Untested)

#include "objects.h"

namespace raven2d {
	
	AnimatedSprite::AnimatedSprite(std::string namev, int xv, int yv):
		GameObject::GameObject(namev, xv, yv) { }
	
	AnimatedSprite::AnimatedSprite(std::string namev, raven2d::Vector2i pv) {
		GameObject::GameObject(namev, pv.x, pv.y) { }
	}
	
	~AnimatedSprite::AnimatedSprite() { }
		
	raven2d::Animation AnimatedSprite::getAnimation(std::string animName) {
		for(size_t i = 0; i < animations.size(); i++)
			if(animations[i]->name == animName) return animations[i];
	}
	
	size_t AnimatedSprite::getAnimationID(std::string animName) {
		for(size_t i = 0; i < animations.size(); i++)
			if(animations[i]->name == animName) return i;
	}
	
	std::string AnimatedSprite::getAnimationName(size_t id) {
		return animations[id]->name;
	}
	
	void AnimatedSprite::addAnimation(raven2d::Animation *anim) {
		animations.append(anim);
	}
		
	void AnimatedSprite::setCurrentAnimation(std::string animName) {
		for(size_t i = 0; i < animations.size(); i++)
			if(animations[i]->name == animName) currentAnimation = i;
	}
	
	void AnimatedSprite::setCurrentAnimation(size_t id) {
		currentAnimation = id;
	}
		
	void AnimatedSprite::onCreate() {
	}
	
	void AnimatedSprite::onStep() { }
	void AnimatedSprite::onDestroy() { }
	
}