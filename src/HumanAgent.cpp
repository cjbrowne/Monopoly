/*
 * HumanAgent.cpp
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 *
 *
 * NOTE: this is a testing, command-line version of this file.  A replacement, SDL version is in the planning phase.
 */

#include <iostream>
#include <string>
#include "HumanAgent.h"
#include "Board.h"
#include "Dice.h"

HumanAgent::HumanAgent()
{
}

HumanAgent::~HumanAgent()
{
}

bool HumanAgent::makeDecision(std::string decisionText)
{
    bool rv;
    std::cout << decisionText;
    std::cin >> rv;
    return rv;
}

void HumanAgent::takeTurn(Player* forWhom, Board on,Dice dice)
{
}

bool HumanAgent::isHuman()
{
    // human agent is always human
    return true;
}

