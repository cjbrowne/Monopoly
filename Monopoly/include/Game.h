/*
 * Game.h
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */

#ifndef GAME_H_
#define GAME_H_

#include "Board.h"
#include "Dice.h"
#include "Player.h"
#include "Rules.h"

class Game
{
    public:
	Game(Rules rules, unsigned int numPlayers);
	virtual
	~Game();
	void
	start();
	void
	takeTurn();

	bool isOver;
    private:
	Player* currentPlayer;
	unsigned int numPlayers;
	Rules rules;
	Dice dice;
	Board board;
};

#endif /* GAME_H_ */
