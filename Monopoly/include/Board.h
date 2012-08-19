/*
 * Board.h
 *
 *  Created on: 19 aug 2012
 *      Author: Chris Browne
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "BoardSquare.h"

class Board
{
public:
  Board();
  virtual ~Board();
private:
  BoardSquare squares[40];
};

#endif /* BOARD_H_ */
