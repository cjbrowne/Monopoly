/*
 * RuleFile.h
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */

#ifndef RULEFILE_H_
#define RULEFILE_H_

#include <fstream>
#include "Rules.h"

class RuleFile {
public:
	RuleFile();
	RuleFile(std::string file_name);
	RuleFile(char* file_name);
	virtual ~RuleFile();
	Rules load();
private:
	std::ifstream fileOnDisk;
	std::string fileName;
};

#define BUF_SIZE 1500

#endif /* RULEFILE_H_ */
