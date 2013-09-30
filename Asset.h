#ifndef ASSET_H
#define ASSET_H

// File: Asset.h
// Author:
// Contents: This file contains the description of a class called Asset.

#include <iostream>
#include "Library.h"

using namespace std;

class Member;

class Asset : public Library
{
    public:
        // Enumerated type for Asset Classification
        enum AssetType {SHORT, LITERARY, MYSTERY, SCIFI, SELFHELP, BIOGRAPHY, COOKING, SPORTS};

	// More methods - see Member
    protected:
	AssetType Type;
    private:
};

#endif
