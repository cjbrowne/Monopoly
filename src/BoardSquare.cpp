/*
 * Board.cpp
 *
 *  Created on: 19 aug 2012
 *      Author: Chris Browne
 */
#if DEBUG >= 3
#include <iostream>
#endif
#include "BoardSquare.h"
#include "HumanAgent.h"
#include "ComputerAgent.h"

BoardSquare::BoardSquare(BoardSquare* previous)
{
	owner = NULL;
	occupiers = NULL;
	if(previous == NULL)
	{
		value = GO;
		type = GO_SQUARE;
		cash = 0;
		property = NULL;
	}
	switch(previous->value)
	{

	}

}

BoardSquare::~BoardSquare()
{
	if(owner != NULL) delete owner;
	if(occupiers != NULL) delete occupiers;
}

void BoardSquare::landOn(Player* player, Rules rules)
{
    if (player == 0) return; // sanity check
    switch (type)
    {
	case UNINITIALISED:
#if DEBUG >= 3
	    std::cerr << "warning: player landed on uninitialised square";
#endif
	    return;
	case GO_SQUARE:
	    if (rules.doubleIfLandOnGo)
		player->receiveCash(rules.salary * 2);
	    else
		player->receiveCash(rules.salary);
	    break;
	case PROPERTY:
	    if (owner != NULL)
	    {
		if (rules.rentOnSquare)
		{
		    cash += property->getRent();
		}
		else
		{
		    player->payRent(owner, property->getRent());
		}
	    }
	    else
	    {
		if (player->canAfford(property->getPrice()) && player->controller->makeDecision("Will you buy " + property->getName() + "?"))
		{
		    player->purchaseProperty(*property,property->getPrice());
		}
		else
		    auction();
	    }
	    break;
	case CHANCE:

	    break;
	default:
	    break;
    }
}

void BoardSquare::pass(Player* player, Rules rules)
{
    // TODO: implement pass method
}

void BoardSquare::auction()
{
    // TODO: implement auction method
}

BoardSquare* BoardSquare::getFullBoard()
{
	return NULL;
}