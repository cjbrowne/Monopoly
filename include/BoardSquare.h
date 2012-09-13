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
#include "PlayerList.h"

enum SquareType
{
    UNINITIALISED = 0,
    GO_SQUARE = 1,
    PROPERTY = 2,
    CHANCE = 3,
    COMMUNITY_CHEST = 4,
    STATION = 5,
    IN_JAIL = 6,
    JUST_VISITING = 7,
    FREE_PARKING_TYPE = 8,
    UTILITY = 9,
    TAX = 10
};

enum SquareValue
{
    GO,
    OLD_KENT,
    COMMUNITY_CHEST_A,
    WHITECHAPEL,
    INCOME_TAX,
    KINGS_CROSS,
    THE_ANGEL_ISLINGTON,
    CHANCE_A,
    EUSTON,
    PENTONVILLE,
    JAIL,
    PALL_MALL,
    ELECTRIC_COMPANY,
    WHITEHALL,
    NORTHUMBERLAND,
    MARYLEBONE,
    BOW_STREET,
    COMMUNITY_CHEST_B,
    MARLBOROUGH_STREET,
    VINE_STREET,
    FREE_PARKING_VALUE,
    STRAND,
    CHANCE_B,
    FLEET_STREET,
    TRAFALGAR,
    FENCHURCH_ST,
    LEICESTER_SQUARE,
    COVENTRY_STREET,
    WATER_WORKS,
    PICCADILLY,
    GOTO_JAIL,
    REGENT_STREET,
    OXFORD_STREET,
    COMMUNITY_CHEST_C,
    BOND_STREET,
    LIVERPOOL_ST,
    CHANCE_C,
    PARK_LANE,
    SUPER_TAX,
    MAYFAIR
};

class BoardSquare
{
    public:
	BoardSquare(BoardSquare* previous);
    ~BoardSquare();
	void landOn(Player* player, Rules rules);
	void pass(Player* player, Rules rules);
	static BoardSquare* getFullBoard();
    BoardSquare* next;
	unsigned int cash; // rent if property and rentOnSquare is true, fines if free parking and strictFreeParking is false
    

    private:
	void auction();
	SquareType type;
    SquareValue value;
	Property* property;
	Player* owner;
	PlayerList* occupiers;

};

#endif /* BOARDSQUARE_H_ */
