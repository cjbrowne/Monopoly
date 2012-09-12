#ifndef SDL_GAME_H
#define SDL_GAME_H

#include "Util.h"

// I prefer forward declarations to #include commands in a header
class Menu;

class SDLGame
{
public:
	SDLGame();
	~SDLGame();
	void start();
	void stop();
	SDL_Surface* getRenderContext();
	SDL_Rect resolution;
	Util util;
private:
	// private methods
	bool init();
	void handleEvent(SDL_Event* Event);
	void logic();
	void render();
	void renderMenuButton();

	// private fields
	bool running;
	SDL_Surface* screen;
	Menu* mainMenu;
	SDL_Rect menuButtonLoc;
	SDL_Surface* menuButton;
	unsigned int frames;
};


#endif