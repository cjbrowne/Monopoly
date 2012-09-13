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

Board::Board()
{
    squares = BoardSquare::getFullBoard();
    location.w = 800;
    location.h = 800;
}

Board::~Board()
{
    // TODO Auto-generated destructor stub
}

void Board::movePlayer(Player* whom, unsigned int howFar)
{

}

#ifdef SDL_VERSION
void Board::render(SDLGame* context)
{
	SDL_Surface* blankBoardTMP;
	SDL_Surface* blankBoard;
	SDL_Surface* target = context->getRenderContext();
	std::stringstream imageLocation;
	imageLocation << "img/" << context->theme << "/board.png";
	blankBoardTMP = IMG_Load(imageLocation.str().c_str());
	if(blankBoardTMP == NULL)
	{
		blankBoardTMP = IMG_Load("img/missing.png");
		location.w = 50;
		location.h = 50;
	}
	blankBoard = SDL_DisplayFormatAlpha(blankBoardTMP);
	SDL_FreeSurface(blankBoardTMP);

	location.x = (context->resolution.w/2) - location.w/2;
	location.y = (context->resolution.h/2) - location.h/2;

	SDL_BlitSurface(blankBoard,NULL,target,&location);

}
#endif