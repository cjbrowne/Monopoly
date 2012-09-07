#ifndef SDL_GAME_H
#define SDL_GAME_H

// I prefer forward declarations to #include commands in a header
union SDL_Event;

class SDLGame
{
public:
	SDLGame();
	~SDLGame();
	void start();
private:
	// private methods
	bool init();
	void handleEvent(SDL_Event* Event);
	void logic();
	void render();

	// private fields
	bool running;
	SDL_Surface* screen;
};


#endif