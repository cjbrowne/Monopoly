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
protected:
  Agent();
  virtual ~Agent();
  virtual bool makeDecision(std::string decisionText);
};

#endif /* AGENT_H_ */
