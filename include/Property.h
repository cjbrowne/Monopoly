/*
 * Property.h
 *
 *  Created on: 19 aug 2012
 *      Author: Chris Browne
 */

#ifndef PROPERTY_H_
#define PROPERTY_H_

#include <string>

enum ImprovementStatus
{
    UNIMPROVED,
    ONE_HOUSE,
    TWO_HOUSES,
    THREE_HOUSES,
    FOUR_HOUSES,
    HOTEL
};

class Property
{
public:
	Property();
	virtual ~Property();
	unsigned int getHousePrice();
	ImprovementStatus getImprovementStatus();
	void setImprovementStatus(ImprovementStatus improvementStatus);
	std::string getName();
	unsigned int getPrice();
	unsigned int getRent();

	std::string name;
    
private:
	unsigned int rent[6];
	ImprovementStatus improvementStatus;
	unsigned int price;
	unsigned int housePrice;
};

#endif /* PROPERTY_H_ */
