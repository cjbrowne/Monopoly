/*
 * Agent.h
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */

#ifndef AGENT_H_
#define AGENT_H_

#include <string>

class Agent
{
    public:
	virtual bool makeDecision(std::string decisionText);
    protected:
	Agent();
	virtual	~Agent();
};

#endif /* AGENT_H_ */
