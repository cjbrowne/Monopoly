/*
 * Board.cpp
 *
 *  Created on: 19 aug 2012
 *      Author: Chris Browne
 */

#ifdef SDL_VERSION
 #include <SDL/SDL.h>
 #include <SDL/SDL_image.h>
#endif
#include <iostream>
#include <sstream>
#include "Board.h"
#include "CommunityDeck.h"
#include "ChanceDeck.h"
#include "BoardSquare.h"
#include "SDLGame.h"

#ifndef SDL_VERSION
Board::Board()
{
    squares = BoardSquare::getFullBoard();
}
#endif

Board::~Board()
{
    // TODO Auto-generated destructor stub
}

void Board::movePlayer(Player* whom, unsigned int howFar)
{
	#ifdef SDL_VERSION
	updated = true;
	#endif
}

#ifdef SDL_VERSION

Board::Board(SDLGame* context)
{
	this->context = context;
	location.w = 768;
    location.h = 768;
	location.x = (context->resolution.w/2) - location.w/2;
	location.y = (context->resolution.h/2) - location.h/2;
	// start with updated == true so that it gets rendered on the first run
	updated = true;
}

void Board::forceUpdate()
{
	updated = true;
}

void Board::SDLInit()
{
	SDL_Surface* blankBoardTMP;
	std::stringstream imageLocation;
	imageLocation << "img/themes/" << context->theme << "/board.png";
	blankBoardTMP = IMG_Load(imageLocation.str().c_str());
	if(blankBoardTMP == NULL)
	{
		blankBoardTMP = IMG_Load("img/missing.png");
		location.w = 50;
		location.h = 50;
	}
	blankBoard = SDL_DisplayFormatAlpha(blankBoardTMP);
	SDL_FreeSurface(blankBoardTMP);
}

void Board::render()
{	
	if(!context->screenUpdated && !updated) return; // don't do anything if the board and screen are in sync already
	SDL_BlitSurface(blankBoard,NULL,context->getRenderContext(),&location);
	context->screenUpdated = true;
	updated = false; // the board has no longer been updated relative to the screen
}
#endif