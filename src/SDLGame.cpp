/*
 * SDLGame.cpp - a replacement for the development-only CLI Game class
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */
#include <SDL/SDL.h>
#include "SDLGame.h"

SDLGame::SDLGame()
{
	screen = NULL;
	running = true;
}

void SDLGame::start()
{
	if(init()==false) running = false;

	SDL_Event* event = new SDL_Event();

	while(running)
	{
		while(SDL_PollEvent(event)) {
			handleEvent(event);
		}
		logic();
		render();
	}

	delete event;
}

bool SDLGame::init()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) return false;
	if((screen = SDL_SetVideoMode(640,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) return false;
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

}

SDLGame::~SDLGame()
{
	SDL_Quit();
}