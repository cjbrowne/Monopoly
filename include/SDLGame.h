#ifndef SDL_GAME_H
#define SDL_GAME_H

#include "Util.h"
#include "PlayerList.h"

// I prefer forward declarations to #include commands in a header
class Menu;
class Board;

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
	bool screenUpdated;
	std::string theme;
        Board* board;
        PlayerList* players;
        PropertyDeck* bankOwnedProperties;
        
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