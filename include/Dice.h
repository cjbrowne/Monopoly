/*
 * Dice.h
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */

#ifndef DICE_H_
#define DICE_H_

class Dice
{
    public:
	Dice();
	virtual ~Dice();
	unsigned int roll();
	bool isDouble;
	void print();
    private:
	unsigned int dieA;
	unsigned int dieB;
};

#endif /* DICE_H_ */
