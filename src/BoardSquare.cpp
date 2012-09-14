/*
 * Board.cpp
 *
 *  Created on: 19 aug 2012
 *      Author: Chris Browne
 */
#if DEBUG >= 3
#include <iostream>
#endif
#include <SDL/SDL.h>
#include "BoardSquare.h"
#include "HumanAgent.h"
#include "ComputerAgent.h"
#include "SDLGame.h"

BoardSquare::BoardSquare()
{
	owner = NULL;
	occupiers = NULL;
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

// TODO: add initialization of rv[i].property field
// note: this will require a LOT of grunt work, so I'm putting it off
// for the time being
BoardSquare* BoardSquare::getFullBoard(SDLGame* context)
{
	BoardSquare* rv = new BoardSquare[40];
        unsigned int i;
        for(i=0;i<40;i++)
        {
          rv[i].owner = NULL;
          rv[i].occupiers = NULL;
          rv[i].cash = 0;
          // bit of a sneaky trick, but I don't care
          rv[i].value = i; 
          
          // TODO: pick up where you left off here
          // rv[i].location.x = 
        }
        
        rv[0].type = GO_SQUARE;
        rv[0].property = NULL;
        rv[0].occupiers = context->players;
        
        rv[1].type = PROPERTY;  
        
        rv[2].type = COMMUNITY_CHEST;
        
        rv[3].type = PROPERTY;
        
        rv[4].type = TAX;
        
        rv[5].type = STATION;
        
        rv[6].type = PROPERTY;
        
        rv[7].type = CHANCE;
        
        // TODO: finish this function!
        
        return rv;
}