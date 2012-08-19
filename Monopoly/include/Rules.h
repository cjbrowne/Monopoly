/*
 * Rules.h
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */

#ifndef RULES_H_
#define RULES_H_

class Rules {
public:
	Rules();
	virtual ~Rules();
	void printAll();

	// startup rules
	unsigned int startCash; // set the amount of start cash
	bool dealProperties;    // deal out properties to begin with?
	unsigned int salary; // amount of money to get when you pass Go

	// rules that make the game easier
	bool doubleIfLandOnGo; // double salary if you land on go (cumulative with above)
	bool onlyNiceChance; // removes all negative chance cards
	bool onlyNiceCommunity; // removes all negative community chest cards
	bool strictFreeParking; // the house rule here is if this is set to false, and Free Parking accumulates money from fines

	// rules that make the game harder
	bool onlyMeanChance; // removes all positive chance cards
	bool onlyMeanCommunity; // removes all positive community chest cards

	// rules to customise the gameplay experience
	double exchangeRate; // changes the currency from £
	char currencySymbol; // changes the currency symbol (eg £, $, etc.)

	// rules invented by Miranda and Chris, see notes at the bottom of the file
	bool rentOnSquare;
};

#endif /* RULES_H_ */

/*
 * Notes on Miranda and Chris house rules
 *
 * rentOnSquare:
 *      this rule will cause any rent owed to be placed on the property's square.  The owner must pass or land on the square in order
 *      to collect the rent.  If the owner's piece is moved by anything other than a dice, the same rules apply as for the square
 *      GO in that instance.  If the property changes hands before the owner reaches the square, the new owner is entitled to any
 *      rent accumulated.  In other words, you must own the property when you pass it in order to collect the rent.
 *
 *
 *
 */
