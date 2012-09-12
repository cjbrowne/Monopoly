#ifndef MENU_H
#define MENU_H

#define MENU_WIDTH 800
#define MENU_HEIGHT 600
#define NUM_BUTTONS 5

class SDLGame;
class SDL_Surface;

enum Button
{
	PLACEHOLDER_1=0,
	PLACEHOLDER_2=1,
	PLACEHOLDER_3=2,
	CLOSE_MENU=3,
	QUIT_GAME=4
};

class Menu
{
public:
	Menu(SDLGame* context);
	~Menu();
	void exitGame();
	void showMenu();
	void hideMenu();
	void init();
	void setRules(char* filename);
	void handleEvent(SDL_Event event);
	void render();

	// public fields
	bool shown;
private:
	SDL_Surface* renderTarget;
	SDL_Surface* menuBuffer;
	SDLGame* context;
	SDL_Rect buttonLocations[NUM_BUTTONS];
	bool deferredDFACall;
};

#endif