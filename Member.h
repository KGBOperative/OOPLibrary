#ifndef MEMBER_H
#define MEMBER_H

// File: Member.h
// Authors: Kyle Janssen, Amandeep Gill
// Contents: This file contains the description of a class
// called Member.

#include <iostream>
#include <vector>
#include <string>
#include "Library.h"
#include "Asset.h"

using namespace std;

cleass Member: public Library
{
    public:
        // The default constructor creates a new member object.
        Member ();

        // This constructor will create a new member object identical to the passed member
        // object.
        Member (const Member & m);
        
        // This destructor currently does nothing.
        ~Member ();
        
        // This assignment operator will copy one object to another of the same type.
        Member & operator = (const Member & m);
        
        // This function adds the given Asset to the list off checked-out Assets
        // additionally, marks the Asset as checked out according to the Asset
        void CheckOut (Library *asset);
        
        // Checks in the Asset that matches assetID
        void Return (string assetID);
        
        // Reads in the state of the current Member from the record file
        void ReadIn (istream & input);
        
        // Writes out the state of the Member to the record file
        void WriteOut (ostream & output);

    private:
        vector <Library *> checkedOut;
        string address, city, state, zip;
        string phone;
};

#endif
