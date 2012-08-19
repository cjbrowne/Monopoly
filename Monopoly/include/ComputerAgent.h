/*
 * ComputerAgent.h
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */

#ifndef COMPUTERAGENT_H_
#define COMPUTERAGENT_H_

#include "Agent.h"

class ComputerAgent: public virtual Agent
{
    public:
	ComputerAgent();
	virtual
	~ComputerAgent();
	bool
	makeDecision(std::string decisionText);
};

#endif /* COMPUTERAGENT_H_ */
