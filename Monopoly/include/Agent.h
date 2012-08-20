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

class Agent
{
    public:
	bool makeDecision(std::string decisionText);
	void takeTurn(Player* forWhom, Board on);
	bool isHuman;
    protected:
	Agent();
	virtual	~Agent();
};

inline Agent::Agent(){}
inline Agent::~Agent(){}

#endif /* AGENT_H_ */
