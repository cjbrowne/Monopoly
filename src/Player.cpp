/*
 * Player.cpp
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */

#include "Player.h"

Player::Player(const std::string &name,Piece chosenPiece,SDLGame* context) : piece(chosenPiece)
{
    this->name = name;
    isOut = false;
    this->context = context;
}

Player::~Player()
{
    // TODO Auto-generated destructor stub
}

void Player::receiveCash(unsigned int amount)
{
	cash += amount;
}

void Player::payRent(Player* to, unsigned int amount)
{
	if(!canAfford(amount))
	{
		int outstanding = amount - cash;
		to->cash += cash;
		cash = 0;
		if(resolveDebt(outstanding))
		{
			to->cash += outstanding;
			cash -= outstanding;
		}
		else
		{
			// if player fails to resolve debt, they must go out
			isOut = true;
		}
	}
	else
	{
		to->cash += amount;
		cash -= amount;
	}
}

bool Player::resolveDebt(unsigned int amount)
{
	// TODO: unimplemented method stub
	return false; // at the moment, we'll assume the player can never resolve the debt because they suck.  all players suck.  you suck.  fuck you.
}

bool Player::canAfford(unsigned int amount)
{
    return (amount <= cash);
}

void Player::purchaseProperty(Property property, unsigned int cost)
{
	// we're going to assume, ASSUME, that the player can afford to pay for it
	// if they can't, we're in big, big trouble.
	cash -= cost;
	properties.add(property);
}


