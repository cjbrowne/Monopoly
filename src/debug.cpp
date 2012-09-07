/*
 * debug.cpp
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 *
 *  Debug (CLI) version of the entrypoint
 */

#include "RuleFile.h"
#include "Rules.h"
#include "Game.h"

int main(void)
{
    RuleFile ruleFile(std::string("rules.mrf"));
    Rules rules = ruleFile.load();
    Game game(rules, 2);

    return 0;
}

