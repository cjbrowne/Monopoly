#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#ifdef DEBUG
#include <iostream>
#endif
#include "Menu.h"
#include "SDLGame.h"


Menu::Menu(SDLGame* context)
{
	this->context = context;
	shown = false; // we probably want to load the menu before we display it

	short int margin_x = (context->resolution.w - MENU_WIDTH)/2;
	short int margin_y = (context->resolution.h - MENU_HEIGHT)/2;

	// I know, they're horrible, but I'm lazy.  Screw you.
	#define X(x) static_cast<short int>(x + margin_x)
	#define Y(y) static_cast<short int>(y + margin_y)

	// WARNING: here be dragons (well, magic numbers)
	buttonLocations[PLACEHOLDER_1] = { X(134), Y(50),500,80 };
	buttonLocations[CLOSE_MENU] = {X(170), Y(360), 450, 80 };
	buttonLocations[QUIT_GAME] = {X(190), Y(460), 410, 80 };

}

void Menu::init()
{
	// render directly to screen
	renderTarget = context->getRenderContext();
	SDL_Surface* menuBufferTMP = IMG_Load("img/menu_blank.png"); // set up the menu buffer with a blank menu to start with
	if(menuBufferTMP == NULL)
	{
		#if DEBUG > 0
		std::cerr << "ERROR [CRASH]: Menu image file could not be loaded (check permissions?)\n";
		#endif
		context->stop(); // crash!
		return;
	}
	menuBuffer = SDL_DisplayFormatAlpha(menuBufferTMP);
	
	SDL_FreeSurface(menuBufferTMP);

	SDL_Surface* menuSelectedTMP = IMG_Load("img/menu_selected.png");
	if(menuSelectedTMP == NULL)
	{
		#if DEBUG > 1
		std::cerr << "WARNING: Menu selected image file could not be loaded, proceeding with no hover animation\n";
		#endif
		menuSelected = menuBuffer;
		SDL_FreeSurface(menuSelectedTMP);
		return;
	}
	menuSelected = SDL_DisplayFormatAlpha(menuSelectedTMP);

	SDL_FreeSurface(menuSelectedTMP);
}

void Menu::show()
{
	shown = true;
	render();
}

void Menu::hide()
{
	shown = false;
}

void Menu::handleEvent(SDL_Event event)
{
	Util util = context->util;
	switch(event.type)
	{
		case SDL_MOUSEMOTION:
		{
			int x,y;
			x = event.motion.x;
			y = event.motion.y;
			if(util.coordInsideRect(buttonLocations[QUIT_GAME],x,y))
			{
				highlightedButton = QUIT_GAME;
			}
			else if(util.coordInsideRect(buttonLocations[CLOSE_MENU],x,y))
			{
				highlightedButton = CLOSE_MENU;
			}
			else
			{
				highlightedButton = NONE_HIGHLIGHTED;
			}
			break;
		}
		case SDL_MOUSEBUTTONDOWN:
		{
			if(event.button.button == SDL_BUTTON_LEFT )
			{
				int x,y;
				x = event.button.x;
				y = event.button.y;
				#if DEBUG == 3
					std::cerr << "Left button pressed @ (" << x << "," << y << ")\n";
				#endif
				if(util.coordInsideRect(buttonLocations[QUIT_GAME],x,y))
				{
					exitGame();
				}
				else if(util.coordInsideRect(buttonLocations[CLOSE_MENU],x,y))
				{
					hide();
				}
			}
			break;
		}
	}
}

void Menu::render()
{
	if(!shown) return; // don't render anything if we're not showing the menu (allows some amount of laziness elsewhere, although such laziness does pollute the call stack so be careful)
	// if we haven't got anywhere to render to...
	if(renderTarget == NULL)
	{
		// ... first, try and recover by getting the target from our Game context ...
		renderTarget = context->getRenderContext();

		// ... if all else fails ...
		if(renderTarget == NULL)
		{
			#if DEBUG > 0
			std::cerr << "ERROR [CRASH]: Menu could not be displayed, the render target was NULL!\n";
			#endif
			context->stop(); // ... crash (if the menu can't be rendered, the game can't recover).
			return;
		}
	}

	SDL_Rect menuSpace;

	menuSpace.x = (renderTarget->w / 2) - (MENU_WIDTH/2);
	menuSpace.y = (renderTarget->h / 2) - (MENU_HEIGHT/2);

	if(highlightedButton != NONE_HIGHLIGHTED)
	{
		SDL_Rect locationInsideFile;
		short int margin_x = (context->resolution.w - MENU_WIDTH)/2;
		short int margin_y = (context->resolution.h - MENU_HEIGHT)/2;

		locationInsideFile.x = buttonLocations[highlightedButton].x - margin_x;
		locationInsideFile.y = buttonLocations[highlightedButton].y - margin_y;
		locationInsideFile.w = buttonLocations[highlightedButton].w;
		locationInsideFile.h = buttonLocations[highlightedButton].h;

		SDL_BlitSurface(menuSelected,&locationInsideFile,renderTarget,&buttonLocations[highlightedButton]);
	}

	SDL_BlitSurface(menuBuffer,NULL,renderTarget,&menuSpace);

}

void Menu::exitGame()
{
	context->stop();
}


Menu::~Menu()
{

}