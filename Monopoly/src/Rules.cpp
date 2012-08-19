/*
 * Rules.cpp
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */

#include <iostream>
#include "Rules.h"

Rules::Rules()
{
    // default values follow the "official" rules of Monopoly

    // startup rules
    startCash = 1500;
    dealProperties = false;
    salary = 200;

    // rules that make the game easier
    doubleIfLandOnGo = false;
    onlyNiceChance = false;
    onlyNiceCommunity = false;
    strictFreeParking = true;

    // rules that make the game harder
    onlyMeanChance = false;
    onlyMeanCommunity = false;

    // rules to customise the gameplay experience
    exchangeRate = 1.0;
    currencySymbol = '£';

    // rules invented by Miranda and Chris
    rentOnSquare = false;
}

Rules::~Rules()
{
    // TODO Auto-generated destructor stub
}

void Rules::printAll()
{
    std::cout << "\tStart Cash:\t\t" << currencySymbol
	    << startCash * exchangeRate;
    std::cout << "\n\tProperties are" << (dealProperties ? "" : " not")
	    << " dealt at start.";
    std::cout << "\n\tSalary:\t\t\t" << currencySymbol << salary * exchangeRate;
    std::cout << "\n\tSalary is" << (doubleIfLandOnGo ? "" : " not")
	    << " doubled when Go is landed upon.";
    std::cout << "\n\tNegative chance cards are"
	    << (onlyNiceChance ? "" : " not") << " removed.";
    std::cout << "\n\tNegative community chest cards are"
	    << (onlyNiceCommunity ? "" : " not") << " removed.";
    std::cout << "\n\tPositive chance cards are"
	    << (onlyMeanChance ? "" : " not") << " removed.";
    std::cout << "\n\tPositive community chest cards are"
	    << (onlyMeanCommunity ? "" : " not") << " removed.";
    std::cout << "\n\tExchange Rate:\t\t" << exchangeRate;
    std::cout << "\n\tCurrency Symbol:\t" << currencySymbol;
}
