/*
 * HumanAgent.h
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */

#ifndef HUMANAGENT_H_
#define HUMANAGENT_H_

#include <map>
#include "Rules.h"
#include "Agent.h"

class HumanAgent: public Agent
{
    public:
	HumanAgent(Rules r);
	virtual
	~HumanAgent();
	bool makeDecision(std::string decisionText);
	void takeTurn(Player* forWhom, Board on,Dice dice);
	bool isHuman();
    private:
	enum MenuOption
	{
	    BAD_CHOICE,
	    ROLL, // r
	    TRADE, // t
	    IMPROVE_PROPERTY, // i
	    PROPERTY_INFO, // p
	    PRINT_BOARD, // b

	};
	Rules rules;
	std::map<std::string,MenuOption> menuOptions;
};

#endif /* HUMANAGENT_H_ */
