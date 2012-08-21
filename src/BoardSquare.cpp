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

BoardSquare::BoardSquare()
{
    type = UNINITIALISED;
    owner = 0;
}

BoardSquare::BoardSquare(SquareType type)
{
    this->type = type;
}

BoardSquare::BoardSquare(Property property)
{
    this->type = PROPERTY;
    this->property = property;
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
		player->receiveCash(rules.salary * 2, "Landed on GO!");
	    else
		player->receiveCash(rules.salary, "Landed on GO.");
	    break;
	case PROPERTY:
	    if (owner != 0)
	    {
		if (rules.rentOnSquare)
		{
		    cash += property.getRent();
		}
		else
		{
		    player->payRent(owner, property.getRent());
		}
	    }
	    else
	    {
		if (player->canAfford(property.getPrice()) && player->controller->makeDecision("Will you buy " + property.getName() + "?"))
		{
		    player->purchaseProperty(property,property.getPrice());
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

