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

HumanAgent::HumanAgent(Rules r)
{
    rules = r;
    menuOptions["roll"] = ROLL;
    menuOptions["r"] = ROLL;
    menuOptions[""] = ROLL;
    menuOptions["trade"] = TRADE;
    menuOptions["t"] = TRADE;
    menuOptions["improve"] = IMPROVE_PROPERTY;
    menuOptions["i"] = IMPROVE_PROPERTY;
    menuOptions["property info"] = PROPERTY_INFO;
    menuOptions["p"] = PROPERTY_INFO;
    menuOptions["print"] = PRINT_BOARD;
    menuOptions["b"] = PRINT_BOARD;

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

void HumanAgent::takeTurn(Player* forWhom, Board board,Dice dice)
{
    unsigned int roll_amount;
    bool turnEnded = false;
    do
    {
	std::string prompt;
	char* inputBuffer = malloc(1024);
	prompt += forWhom->name + " (" + rules.currencySymbol;
	prompt += forWhom->cash * rules.currencySymbol + ") :";
	std::cout << prompt;
	std::cout.flush();
	std::cin.getline(inputBuffer,1024);

	switch(inputBuffer)
	{
	    case ROLL:
		roll_amount = dice.roll();
		std::cout << "Rolled: ";
		dice.print();
		board.movePlayer(forWhom,roll_amount);
	}

    } while(!turnEnded);
}

bool HumanAgent::isHuman()
{
    // human agent is always human
    return true;
}

