/*
 * Player.cpp
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */

#include "Player.h"

Player::Player()
{
    // TODO Auto-generated constructor stub

}

Player::~Player()
{
    // TODO Auto-generated destructor stub
}

void Player::receiveCash(unsigned int amount, std::string reason)
{
}

void Player::payRent(Player* to, unsigned int amount)
{
}

bool Player::canAfford(unsigned int amount)
{
    return (amount <= cash);
}

void Player::purchaseProperty(Property property, unsigned int cost)
{
}


