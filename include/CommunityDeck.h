/*
 * CommunityDeck.h
 *
 *  Created on: 19 aug 2012
 *      Author: Chris Browne
 */

#ifndef COMMUNITYDECK_H_
#define COMMUNITYDECK_H_

#include "Community.h"

class CommunityDeck
{
    public:
	CommunityDeck();
	virtual ~CommunityDeck();

    private:
	void shuffle();
	Community active[];
	Community discard[];
};

#endif /* COMMUNITYDECK_H_ */
