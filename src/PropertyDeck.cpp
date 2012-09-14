/*
 * PropertyDeck.cpp
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */
#include "PropertyDeck.h"

PropertyDeck::PropertyDeck()
{
	count = 0;
}

PropertyDeck::~PropertyDeck()
{
    while(top->next != NULL)
    {
    	delete top->value;
    	top = top->next;
    }
    while(top->previous != NULL)
    {
    	top = top->previous;
    	delete top->next;
    }
    delete top;
}

// TODO: untested, probably fucked up function.  Sorry about that.
void PropertyDeck::add(Property property)
{
	PropertyCard* newElement = new PropertyCard();
	newElement->value = new Property(property);
	PropertyCard* current = top;
	while(newElement->value->name < current->value->name)
		current = current->next;

	newElement->next = current->previous->next;
	newElement->previous = current->next->previous;

	newElement->index = count-1;

	current->previous->next = newElement;
	current->next->previous = newElement;


	count++;
}

void PropertyDeck::remove(Property property)
{
	PropertyCard* toRemove = findByName(property.name);
	toRemove->previous->next = toRemove->next;
	toRemove->next->previous = toRemove->previous;
	delete toRemove;
}

PropertyCard* PropertyDeck::get(unsigned int index)
{
	if(index >= count) return NULL;
	PropertyCard* current = top;
	while(current->index != index)
		current = current->next;
	return current;
}

PropertyCard* PropertyDeck::findByName(const std::string &name)
{
	PropertyCard* current = top;
	while(current->index < count)
	{
		if(current->value->name == name) return current;
		// because it's alphabetically sorted, we can jump out as soon as we "pass" the name
		if(current->value->name < name) break;
	}
	return NULL;
}