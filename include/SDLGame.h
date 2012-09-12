#ifndef SDL_GAME_H
#define SDL_GAME_H

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
private:
	// private methods
	bool init();
	void handleEvent(SDL_Event* Event);
	void logic();
	void render();

	// private fields
	bool running;
	SDL_Surface* screen;
	Menu* mainMenu;
};


#endif