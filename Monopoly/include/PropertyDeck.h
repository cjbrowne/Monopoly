/*
 * PropertyDeck.h
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */

#ifndef PROPERTYDECK_H_
#define PROPERTYDECK_H_

#include "Property.h"

/*
 OLD_KENT_ROAD,
 WHITECHAPEL_ROAD,
 THE_ANGEL_ISLINGTON,
 EUSTON_ROAD,
 PENTONVILLE_ROAD,
 PALL_MALL,
 // TODO: missing property
 WHITEHALL,
 BOW_STREET,
 VINE_STREET,
 MARLBOROUGH_STREET,
 THE_STRAND,
 FLEET_STREET,
 // TODO: missing property
 COVENTRY_STREET,
 PICADILLY,
 LIVERPOOL_STREET,
 REGENT_STREET,
 OXFORD_STREET,
 BOND_STREET,
 PARK_LANE,
 MAYFAIR*/

class PropertyDeck
{
    public:
	PropertyDeck();
	virtual
	~PropertyDeck();
    private:
	Property properties[];
	unsigned int numProperties;
};

#endif /* PROPERTYDECK_H_ */
