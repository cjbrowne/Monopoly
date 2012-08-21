/*
 * Dice.cpp
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Dice.h"

unsigned int Dice::roll()
{
    dieA = std::rand()%6;
    dieB = std::rand()%6;
    isDouble = (dieA == dieB);
    return dieA + dieB;
}

void Dice::print()
{
    std::cout << dieA << ", " << dieB;
}

Dice::Dice()
{
    std::srand(std::time(NULL));
}

Dice::~Dice()
{
    // TODO Auto-generated destructor stub
}

