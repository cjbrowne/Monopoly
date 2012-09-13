/*
 * SDLGame.cpp - a replacement for the development-only CLI Game class
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */
#ifdef DEBUG
#include <iostream>
#endif
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "SDLGame.h"
#include "Menu.h"

SDLGame::SDLGame()
{
	screen = NULL;
	running = true;

	// make sure to set these before we call the Menu constructor...
	resolution.w = 1024;
	resolution.h = 768;
	
	mainMenu = new Menu(this);
	mainMenu->shown = true; // start off in the main menu

	// set up the menu button
	menuButtonLoc.w = 200;
	menuButtonLoc.h = 120;
	menuButtonLoc.x = resolution.w - menuButtonLoc.w - 15;
	menuButtonLoc.y = 5;
}

void SDLGame::start()
{
	if(init()==false) running = false;
	mainMenu->init();

	SDL_Event* event = new SDL_Event();
	frames = 0;
	while(running)
	{
		while(SDL_PollEvent(event)) {
			// allow the menu to handle mouse events that are relevant to it
			if(mainMenu->shown)
				mainMenu->handleEvent(*event);
			handleEvent(event);
		}
		logic();
		render();
		frames++;
	}
	#if DEBUG >= 3
	std::cerr << "Average framerate was: " << frames/(SDL_GetTicks()/1000) << " fps (" << frames << " frames over " << SDL_GetTicks()/1000 << " seconds)\n";
	#endif

	delete event;
}

void SDLGame::stop()
{
	// allow the loop to complete and clean-up to occur naturally and smoothly
	running = false;
}

bool SDLGame::init()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) return false;
	if((screen = SDL_SetVideoMode(resolution.w,resolution.h,32,SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) return false;

	// set up the menu button after the screen has been set
	SDL_Surface* menuButtonTMP = IMG_Load("img/menu_button.png");
	menuButton = SDL_DisplayFormatAlpha(menuButtonTMP);
	SDL_FreeSurface(menuButtonTMP);

	return true;
}

void SDLGame::handleEvent(SDL_Event* event)
{
	if(event->type == SDL_QUIT) running = false;
	if(event->type == SDL_MOUSEBUTTONDOWN)
	{
		if(event->button.button == SDL_BUTTON_LEFT)
		{
			int x,y;
			x = event->button.x;
			y = event->button.y;
			if(util.coordInsideRect(menuButtonLoc,x,y))
			{
				mainMenu->show();
			}
		}
	}
}

void SDLGame::logic()
{

}

void SDLGame::render()
{
	// start by clearing the screen
	SDL_FillRect(screen,NULL,0x00000000);

	// render the menu just before flipping, so that it appears in front of everything else
	if(mainMenu->shown) mainMenu->render();
	else SDL_BlitSurface(menuButton,NULL,screen,&menuButtonLoc); // render the menu button if the menu isn't already shown

	SDL_Flip(screen);
}

SDLGame::~SDLGame()
{
	SDL_Quit();
	delete mainMenu;
}

SDL_Surface* SDLGame::getRenderContext()
{
	return screen;
}