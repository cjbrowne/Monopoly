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
    GO=0,
    OLD_KENT=1,
    COMMUNITY_CHEST_A=2,
    WHITECHAPEL=3,
    INCOME_TAX=4,
    KINGS_CROSS=5,
    THE_ANGEL_ISLINGTON=6,
    CHANCE_A=7,
    EUSTON=8,
    PENTONVILLE=9,
    JAIL=10,
    PALL_MALL=11,
    ELECTRIC_COMPANY=12,
    WHITEHALL=13,
    NORTHUMBERLAND=14,
    MARYLEBONE=15,
    BOW_STREET=16,
    COMMUNITY_CHEST_B=17,
    MARLBOROUGH_STREET=18,
    VINE_STREET=19,
    FREE_PARKING_VALUE=20,
    STRAND=21,
    CHANCE_B=22,
    FLEET_STREET=23,
    TRAFALGAR=24,
    FENCHURCH_ST=25,
    LEICESTER_SQUARE=26,
    COVENTRY_STREET=27,
    WATER_WORKS=28,
    PICCADILLY=29,
    GOTO_JAIL=30,
    REGENT_STREET=31,
    OXFORD_STREET=32,
    COMMUNITY_CHEST_C=33,
    BOND_STREET=34,
    LIVERPOOL_ST=35,
    CHANCE_C=36,
    PARK_LANE=37,
    SUPER_TAX=38,
    MAYFAIR=39
};

class BoardSquare
{
    public:
	BoardSquare();
        ~BoardSquare();
	void landOn(Player* player, Rules rules);
	void pass(Player* player, Rules rules);
	static BoardSquare* getFullBoard(SDLGame* context);
        
	unsigned int cash; // rent if property and rentOnSquare is true, fines if free parking and strictFreeParking is false
        SDL_Rect location;
        SquareType type;
        SquareValue value;
        Property* property;
        Player* owner;
        PlayerList* occupiers;

    private:
	void auction();

};

#endif /* BOARDSQUARE_H_ */
