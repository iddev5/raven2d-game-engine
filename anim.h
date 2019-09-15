// WIP (Untested)

#ifndef COOL_ANIM_H
#define COOL_ANIM_H

#include "config.h"

namespace cool {
	
	class Frame {
	public:
		Frame(std::string name, SDL_Texture *tex);
		virtual ~Frame();
		
		SDL_Texture *getTexture();
		int getXOffset(); 
		int getYOffset();
		
		void setTexture(SDL_Texture *tex);
		void setXOffset(int x);
		void setYOffset(int y);
	
	private:
		SDL_Texture *texture;
		std::string name;
		int xOffset, yOffset;
	}
	
	class Animation {
	public:
		Animation(std::string namev);
		virtual ~Animation();
		
		cool::Frame *getFrame(std::string frameName);
		float getTimebreak();
		
		void setFrame(std::string frameName, cool::Frame *frame);
		void setTimebreak(float tb);
		
		void addFrame(cool::Frame *frame);
		
	private:
		std::vector<cool::Frame> frames;
		float time = 0.1f;
	}
	
	cool::Frame operator[](cool::Animation *anim) {
		anim->frames;
	}

}

#endif