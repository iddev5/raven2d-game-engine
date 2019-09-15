#include "objects.h"

namespace cool {
	
	AnimatedSprite::AnimatedSprite(std::string namev, int xv, int yv):
		Node::Node(namev, xv, yv) { }
	
	AnimatedSprite::AnimatedSprite(std::string namev, cool::Vector2i pv) {
		Node::Node(namev, pv.x, pv.y) { }
	}
	
	~AnimatedSprite::AnimatedSprite() { }
		
	cool::Animation AnimatedSprite::getAnimation(std::string animName) {
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
	
	void AnimatedSprite::addAnimation(cool::Animation *anim) {
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