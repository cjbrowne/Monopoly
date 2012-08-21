/*
 * ComputerAgent.cpp
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */

#include "Dice.h"
#include "ComputerAgent.h"
#include "Player.h"
#include "Board.h"

ComputerAgent::ComputerAgent()
{
    isHuman = false;
}

ComputerAgent::~ComputerAgent()
{
}

bool ComputerAgent::makeDecision(std::string decisionText)
{
    // FIXME: implement some kind of AI engine for making decisions
    return true;
}

void ComputerAgent::takeTurn(Player* forWhom, Board on,Dice dice)
{
}

