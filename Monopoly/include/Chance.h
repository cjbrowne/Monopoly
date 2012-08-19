/*
 * Chance.h
 *
 *  Created on: 19 aug 2012
 *      Author: Chris Browne
 */

#ifndef CHANCE_H_
#define CHANCE_H_

#include <string>

class Chance
{
    public:
	Chance();
	virtual ~Chance();

    private:
	std::string cardText;
	int cash; // positive = reward, negative = cost
	unsigned int travel_to; // where to travel to
	bool repairHouses; // whether the card requires you to repair houses
	bool goBack; // whether the card requires you to travel backwards (old kent road)
	bool goForth; // whether the card requires you to travel forwards (mayfair)
	bool goDirect; // whether the card requires you to travel directly (jail) - do not pass go, do not collect £200!
};

#endif /* CHANCE_H_ */
