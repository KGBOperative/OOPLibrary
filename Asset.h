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

        // This function sets Type based on a sring value.
        virtual void SetType (string TypeS);

        // This function returs Type as a string.
        virtual string GetType () const;

        // Default constructor
        Asset(void);

    protected:
        AssetType Type;
    private:
};

#endif
