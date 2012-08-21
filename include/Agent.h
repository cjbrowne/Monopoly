/*
 * Agent.h
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 *
 * Abstract Base Class from which both human control interfaces and artificial intelligence agents are derived
 * see HumanAgent for the human control interface
 * see ComputerAgent for an artificial intelligence agent
 */

#ifndef AGENT_H_
#define AGENT_H_

#include <string>

// Forward declarations necessary for ABC
class Player;
class Board;
class Dice;

class Agent
{
    public:
	virtual bool makeDecision(std::string decisionText) = 0;
	virtual void takeTurn(Player* forWhom, Board on,Dice dice) = 0;
	virtual bool isHuman() = 0;
	virtual ~Agent() {};
};

#endif /* AGENT_H_ */
