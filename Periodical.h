#ifndef PERIODICAL_H
#define PERIODICAL_H

// File: Periodical.h
// Author:
// Contents: This file contains the description of a class
// called Periodical.

#include <iostream>
#include <vector>
#include "Asset.h"
#include "Date.h"

#define DEBUG 0
#define debug if (DEBUG) cout

using namespace std;

enum PeriodicalType {FICTION, NONFICTION};

class Periodical : public Asset
{
    public:
	// More Methods - see Member
    private:
        struct Issue
	{
	    int Volume;
	    int Number;
	    Date PubDate;
	    Date CheckedOut;
	    Member * CheckedOutBy;
	    int CopyNumber;
	};
	String ISSN;
	vector <Issue> Issues;
};

#endif
