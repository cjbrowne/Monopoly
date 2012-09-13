/*
 * Board.h
 *
 *  Created on: 19 aug 2012
 *      Author: Chris Browne
 */

#ifndef BOARD_H_
#define BOARD_H_

#ifdef SDL_VERSION
	#include <SDL/SDL.h>
#endif

 class CommunityDeck;
 class ChanceDeck;
 class BoardSquare;
 class Player;

class Board
{
    public:
	Board();
	virtual
	~Board();
	void movePlayer(Player* whom,unsigned int howFar);
	#ifdef SDL_VERSION
	void render(SDL_Surface* target);
	#endif

    private:
	BoardSquare* squares;
	ChanceDeck* chance;
	CommunityDeck* community;
};

#endif /* BOARD_H_ */
