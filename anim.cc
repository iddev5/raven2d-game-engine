// WIP (Untested)

#include "anim.h"

namespace raven2d {
	
	Frame::Frame(std::string namev, SDL_Texture *tex):
		name(namev), texture(tex) { }
		
	Frame::~Frame() {
		if(texture != NULL)
			SDL_DestroyTexture(texture);
	}
	
	SDL_Texture *Frame::getTexture() {
		return texture;
	}
	
	int Frame::getXOffset() {
		return xOffset;
	}
	
	int Frame::getYOffset() {
		return yOffset;
	}
	
	void Frame::setTexture(SDL_Texture *tex) {
		texture = tex;
	}
	
	void Frame::setXOffset(int x) {
		xOffset = x;
	} 
	
	void Frame::setYOffset(int y) {
		yOffset = y;
	}
	
	//////////////////////////////////////////////
	
	Animation::Animation(std::string namev):
		name(namev) { }

	Animation::~Animation() { }
	
	raven2d::Frame *Animation::getFrame(std::string frameName) {
		for(size_t i = 0; i < frames.size(); i++)
			if(frames[i]->name == frameName) return frames[i];
	}
	
	float Animation::getTimebreak() {
		return time;
	}
	
	void Animation::setTimeout(float tb) {
		time = td;
	}
	
	void Animation::addFrame(raven2d::Frame *frame) {
		frames.append(frame);
	}
	
}