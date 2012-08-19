/*
 * HumanAgent.h
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */

#ifndef HUMANAGENT_H_
#define HUMANAGENT_H_

#include "Agent.h"

class HumanAgent : public virtual Agent
{
public:
  HumanAgent();
  virtual ~HumanAgent();
  bool makeDecision(std::string decisionText);
};

#endif /* HUMANAGENT_H_ */
