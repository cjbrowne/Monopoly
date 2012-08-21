/*
 * ChanceDeck.h
 *
 *  Created on: 19 aug 2012
 *      Author: Chris Browne
 */

#ifndef CHANCEDECK_H_
#define CHANCEDECK_H_

#include "Chance.h"

class ChanceDeck
{
    public:
	ChanceDeck();
	virtual ~ChanceDeck();
	Chance drawCard();
    private:
	void shuffle();
	Chance active[]; // TODO: find out how many CHANCE cards there are in monopoly
	Chance discard[]; // TODO: find out how many CHANCE cards there are in monopoly
};

#endif /* CHANCEDECK_H_ */
