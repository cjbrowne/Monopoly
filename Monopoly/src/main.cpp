/*
 * main.cpp
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */

#include "RuleFile.h"
#include "Rules.h"
#include "Game.h"

int main(void)
{
	RuleFile ruleFile(std::string("rules.mrf"));
	Rules rules = ruleFile.load();
	Game game(rules,2);

	return 0;
}

