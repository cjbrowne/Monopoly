/*
 * SDLGame.cpp - a replacement for the development-only CLI Game class
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */
#include <SDL/SDL.h>
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
}

void SDLGame::start()
{
	if(init()==false) running = false;
	mainMenu->init();

	SDL_Event* event = new SDL_Event();

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
	}

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
	return true;
}

void SDLGame::handleEvent(SDL_Event* event)
{
	if(event->type == SDL_QUIT) running = false;
}

void SDLGame::logic()
{

}

void SDLGame::render()
{

	// render the menu just before flipping, so that it appears in front of everything else
	if(mainMenu->shown) mainMenu->render();
	
	// last but not least!
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