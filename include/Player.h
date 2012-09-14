/*
 * Player.h
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <SDL/SDL.h>
#include <string>
#include "PropertyDeck.h"
#include "Piece.h"

class Agent;

class Player
{
public:
	Player(const std::string &name,Piece chosenPiece,SDLGame* context);
	virtual
	~Player();
	void
	receiveCash(unsigned int amount);
	void
	payRent(Player* to, unsigned int amount);
	bool
	canAfford(unsigned int amount);
	void
	purchaseProperty(Property property, unsigned int cost);
	bool resolveDebt(unsigned int amount);
	Player* next;
	Agent* controller;
	std::string name;
	Piece piece;
	unsigned int cash;
	bool isOut;

private:
	PropertyDeck properties;
	bool hasGetOutOfJailFreeChance;
	bool hasGetOutOfJailFreeCommunity;
	bool inJail; // used for distinguishing between "jail" and "just visiting"
	SDLGame* context;
};

#endif /* PLAYER_H_ */
