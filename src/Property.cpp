/*
 * Property.cpp
 *
 *  Created on: 19 aug 2012
 *      Author: Chris Browne
 */

#include "Property.h"

Property::Property()
{
    // TODO Auto-generated constructor stub

}

Property::~Property()
{
    // TODO Auto-generated destructor stub
}

unsigned int Property::getHousePrice()
{
    return housePrice;
}

void Property::setImprovementStatus(ImprovementStatus improvementStatus)
{
    this->improvementStatus = improvementStatus;
}

std::string Property::getName()
{
    return name;
}

unsigned int Property::getPrice()
{
    return price;
}

unsigned int Property::getRent()
{
    return rent[improvementStatus];
}

