/*
 * PropertyDeck.h
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */

#ifndef PROPERTYDECK_H_
#define PROPERTYDECK_H_

#include "Property.h"


struct PropertyCard
{
	Property* value;
	// double-linked list makes it easier to delete from the middle of the list
	PropertyCard* next;
	PropertyCard* previous;
	unsigned int index;
};

class PropertyDeck
{
public:
	PropertyDeck();
	virtual ~PropertyDeck();
	void add(Property property);
	void remove(Property property);
	PropertyCard* get(unsigned int index);
	PropertyCard* findByName(const std::string &name);
private:
	PropertyCard* top;
	unsigned int count;
};

#endif /* PROPERTYDECK_H_ */
