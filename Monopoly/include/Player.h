/*
 * Player.h
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Agent.h"
#include "PropertyDeck.h"

enum Piece
{
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
  Player();
  virtual ~Player();
  Player* next;
  Agent* controller;
private:
  PropertyDeck properties;
  unsigned int cash;
  bool hasGetOutOfJailFreeChance;
  bool hasGetOutOfJailFreeCommunity;
  bool inJail; // used for distinguishing between "jail" and "just visiting"
  Piece piece;
};

#endif /* PLAYER_H_ */
