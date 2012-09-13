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
	QUIT_GAME=4,
	NONE_HIGHLIGHTED // should just select the highest available option
};

class Menu
{
public:
	Menu(SDLGame* context);
	~Menu();
	void exitGame();
	void show();
	void hide();
	void init();
	void setRules(char* filename);
	void handleEvent(SDL_Event event);
	void render();

	// public fields
	bool shown;
private:
	SDL_Surface* renderTarget;
	SDL_Surface* menuBuffer;
	SDL_Surface* menuSelected;
	SDLGame* context;
	SDL_Rect buttonLocations[NUM_BUTTONS];
	bool deferredDFACall;
	Button highlightedButton;
};

#endif