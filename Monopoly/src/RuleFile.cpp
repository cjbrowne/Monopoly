/*
 * RuleFile.cpp
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */
#include <iostream>
#include <cstdlib>
#include "RuleFile.h"

RuleFile::RuleFile(std::string file_name)
{
    fileOnDisk.open(file_name.c_str());
}

RuleFile::RuleFile(char* file_name)
{
    fileOnDisk.open(file_name);
}

RuleFile::~RuleFile()
{

}

Rules RuleFile::load()
{
    Rules rv;
    char* buf = (char*) malloc(BUF_SIZE);
    std::string current_line(buf);
    if (fileOnDisk.is_open())
    {
	fileOnDisk.getline(buf, BUF_SIZE);
	if (current_line.substr(0, std::string("start_cash").length()).compare(
		"start_cash") == 0)
	{
	    // rv.startCash = current_line.substr(current_line.find(':'));
	}
    }
    else
    {
	std::cerr << "Could not open rules file, using default rules.\n";
    }
#if DEBUG >= 3
    std::cout << "Rules:\n";
    rv.printAll();
#endif
    return rv;
}

