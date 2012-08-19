/*
 * HumanAgent.cpp
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */

#include <iostream>
#include <string>
#include "HumanAgent.h"

inline bool strtobool(std::string str)
{
    if (str.compare("yes") == 0) return true;
    if (str.compare("true") == 0) return true;
    if (str.compare("1") == 0) return true;
    return false;
}

bool HumanAgent::makeDecision(std::string decisionText)
{
    // for now, we'll use a text-only approach for this class
    std::string rv;
    std::cout << decisionText;
    std::cin >> rv;
    return strtobool(rv);
}

