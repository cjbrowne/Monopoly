/*
 * Board.h
 *
 *  Created on: 19 aug 2012
 *      Author: Chris Browne
 */

#ifndef BOARDSQUARE_H_
#define BOARDSQUARE_H_

#include "Rules.h"
#include "Player.h"

enum SquareType
{
    UNINITIALISED = 0,
    GO_SQUARE = 1,
    PROPERTY = 2,
    CHANCE = 3,
    COMMUNITY_CHEST = 4,
    STATION = 5,
    JAIL = 6,
    FREE_PARKING = 7,
    WATER_WORKS = 8,
    ELECTRICITY_COMPANY = 9,
    INCOME_TAX = 10,
    SUPER_TAX = 11
};

class BoardSquare
{
    public:
	BoardSquare();
	BoardSquare(SquareType type);
	BoardSquare(Property property);
	void
	landOn(Player* player, Rules rules);
	void
	pass(Player* player, Rules rules);
	unsigned int cash; // rent if property and rentOnSquare is true, fines if free parking and strictFreeParking is false
    private:
	void
	auction();
	SquareType type;
	Property property;
	Player* owner;
	Player* occupier;

};

#endif /* BOARDSQUARE_H_ */
