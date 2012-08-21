/*
 * Board.cpp
 *
 *  Created on: 19 aug 2012
 *      Author: Chris Browne
 */

#include "Board.h"

Board::Board()
{
    squares[0] = BoardSquare(GO_SQUARE);
    // squares[1] = BoardSquare(OLD_KENT_ROAD);
    squares[2] = BoardSquare(INCOME_TAX);
    // squares[3] = BoardSquare(WHITECHAPEL_ROAD);

}

Board::~Board()
{
    // TODO Auto-generated destructor stub
}

void Board::movePlayer(Player* whom, unsigned int howFar)
{
}

