/*
 * Board.h
 *
 *  Created on: 19 aug 2012
 *      Author: Chris Browne
 */

#ifndef BOARDSQUARE_H_
#define BOARDSQUARE_H_

#include "Player.h"

enum SquareType
{
  GO = 0,
  PROPERTY = 1,
  CHANCE = 2,
  COMMUNITY_CHEST = 3,
  STATION = 4,
  JAIL = 5,
  FREE_PARKING = 6,
  UTILITY = 7
};

class BoardSquare
{
public:
  BoardSquare(SquareType type);
  void landOn(Player* player);
  void purchase(Player* player);
  void pass(Player* player);
private:
  SquareType type;
  Player* owner;
  Player* occupier;
  unsigned int cash; // rent if property and rentOnSquare is true, fines if free parking and strictFreeParking is false
};

#endif /* BOARDSQUARE_H_ */
