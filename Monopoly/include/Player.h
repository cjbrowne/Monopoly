/*
 * Player.h
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include "Agent.h"
#include "PropertyDeck.h"

enum Piece
{
    BAD_CHOICE,
    CAR,
    BOAT,
    DOG,
    TOP_HAT,
    IRON,
    WHEELBARROW,
    HORSE,
    THIMBLE,
};

class Player
{
    public:
	Player(std::string name,Piece chosenPiece);
	virtual
	~Player();
	void
	receiveCash(unsigned int amount, std::string reason);
	void
	payRent(Player* to, unsigned int amount);
	bool
	canAfford(unsigned int amount);
	void
	purchaseProperty(Property property, unsigned int cost);
	Player* next;
	Agent* controller;
	std::string name;
    private:
	unsigned int cash;
	PropertyDeck properties;
	bool hasGetOutOfJailFreeChance;
	bool hasGetOutOfJailFreeCommunity;
	bool inJail; // used for distinguishing between "jail" and "just visiting"
	Piece piece;
};

#endif /* PLAYER_H_ */
