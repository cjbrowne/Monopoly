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
	    << startCash * exchangeRate << "\n";
    std::cout << "\tProperties are" << (dealProperties ? "" : " not")
	    << " dealt at start.\n";
    std::cout << "\tSalary:\t\t\t" << currencySymbol << salary * exchangeRate;
    std::cout << "\tSalary is" << (doubleIfLandOnGo ? "" : " not")
	    << " doubled when Go is landed upon.\n";
    std::cout << "\tNegative chance cards are"
	    << (onlyNiceChance ? "" : " not") << " removed.\n";
    std::cout << "\tNegative community chest cards are"
	    << (onlyNiceCommunity ? "" : " not") << " removed.\n";
    std::cout << "\tPositive chance cards are"
	    << (onlyMeanChance ? "" : " not") << " removed.\n";
    std::cout << "\tPositive community chest cards are"
	    << (onlyMeanCommunity ? "" : " not") << " removed.\n";
    std::cout << "\tExchange Rate:\t\t" << exchangeRate << "\n";
    std::cout << "\tCurrency Symbol:\t" << currencySymbol << "\n";
}
