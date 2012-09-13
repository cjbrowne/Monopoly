/*
 * Board.cpp
 *
 *  Created on: 19 aug 2012
 *      Author: Chris Browne
 */

#ifdef SDL_VERSION
 #include <SDL/SDL.h>
#endif
#include "Board.h"
#include "CommunityDeck.h"
#include "ChanceDeck.h"
#include "BoardSquare.h"

Board::Board()
{
    squares = BoardSquare::getFullBoard();
}

Board::~Board()
{
    // TODO Auto-generated destructor stub
}

void Board::movePlayer(Player* whom, unsigned int howFar)
{
}

#ifdef SDL_VERSION
void Board::render(SDL_Surface* target)
{

}
#endif