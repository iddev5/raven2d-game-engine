#ifndef COOL_OBJECTS_H
#define COOL_OBJECTS_H

#include "config.h"
#include "renderer.h"
#include "util/colour.h"
#include "util/vector.h"

namespace raven2d {

	enum flip {
		horizontal,
		vertical
	};

	class GameObject {
	public:
		GameObject(std::string namev, int xv=0, int yv=0);
		GameObject(std::string namev, raven2d::Vector2i pv={0,0});
		virtual ~GameObject();

		void pause();
		void resume();

		void move(int xv, int yv);
		void reorder(int zv);
		void scale(int sxv, int syv);
		void rotate(short av);
		bool isFlipped(int fv);
		void flip(int fv);

		virtual void onCreate()  = 0;
		virtual void onStep(SDL_Renderer *renderer) = 0;
		virtual void onDestroy() = 0;
		virtual void update(SDL_Renderer *renderer);

	public:
		std::string name;
		std::string type;
		int x;
		int y;
		int zOrder;
		short angle;
		int scaleX;
		int scaleY;
		bool flipVert;
        bool flipHoriz;
        bool firstUpdate;
        bool isPaused;
        raven2d::GameObject *child;
	};

	class Sprite: public raven2d::GameObject {
	public:
        Sprite(std::string name, int xv, int yv);
		Sprite(std::string name, raven2d::Vector2i pv);
        virtual ~Sprite();

		// METHODS
        virtual void onCreate();
        virtual void onStep(SDL_Renderer *renderer);
        virtual void onDestroy();
        virtual void update(SDL_Renderer *renderer);

    public:
        SDL_Texture *texture;

	private:
		bool         changed;
        SDL_Rect     dst;
        SDL_RendererFlip rfp;
	};
	/*
	class AnimatedSprite: public raven2d::GameObject {
	public:
		AnimatedSprite(std::string namev, int xv, int yv);
		AnimatedSprite(std::string namev, raven2d::Vector2i pv);
		virtual ~AnimatedSprite();

		raven2d::Animation getAnimation(std::string animName);
		size_t getAnimationID(std::string animName);
		std::string getAnimationName(size_t id);

		void setCurrentAnimation(std::string animName);
		void setCurrentAnimation(size_t id);

		void addAnimation(raven2d::Animation *anim);

		virtual void onCreate();
		virtual void onStep();
		virtual void onDestroy();
		virtual void update() = 0;

	protected:
		std::vector<raven2d::Animation> animations;
		size_t currentAnimation;

	private:
		bool 			 changed;
		SDL_Rect 		 dst;
		SDL_RendererFlip rfp;

	}
	*/

}

//typedef std::shared_ptr<raven2d::GameObject> GameObjectRef;

#endif
