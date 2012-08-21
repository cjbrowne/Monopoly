/*
 * Board.h
 *
 *  Created on: 19 aug 2012
 *      Author: Chris Browne
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "CommunityDeck.h"
#include "ChanceDeck.h"
#include "BoardSquare.h"

class Board
{
    public:
	Board();
	virtual
	~Board();
	void movePlayer(Player* whom,unsigned int howFar);
    private:
	BoardSquare squares[40];
	ChanceDeck chance;
	CommunityDeck community;
};

#endif /* BOARD_H_ */
