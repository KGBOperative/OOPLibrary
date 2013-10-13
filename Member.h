#ifndef MEMBER_H
#define MEMBER_H

// File: Member.h
// Authors: Kyle Janssen, Amandeep Gill
// Contents: This file contains the description of a class
// called Member.

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Library.h"

using namespace std;

class Member: public Library
{
    public:
        // The default constructor creates a new member object.
        Member ();

        // The overloaded constructor to set all informational data at once
        Member (string name, string id, string address, string city, string state, string zip, string phone);

        // This constructor will create a new member object identical to the passed member
        // object.
        Member (const Member & m);
        
        // This assignment operator will copy one object to another of the same type.
        Member &  operator = (const Member & m);
        
        // Reads in the state of the current Member from the record file
        void ReadIn (istream & input);
        
        // Writes out the state of the Member to the record file
        void WriteOut (ostream & output);

        // 
        inline void AddIssue(int volume, int number, string pubDate) {}

        // test for make
        // inline void testing(void) {}

    private:
        // Adds the asset given into the list of checked out items
        void Add(shared_ptr<Library> asset, Date date);

        // Removes the asset given from the list of checked out items
        void Remove(shared_ptr<Library> asset);

        vector <shared_ptr<Library> > checkedOut;
        string address, city, state, zip;
        string phone;
};

#endif
