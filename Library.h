#ifndef LIBRARY_H
#define LIBRARY_H

// File: Library.h
// Author:
// Contents: This file contains the description of a virtual class
// called Library.

#include <iostream>
#define DEBUG 0
#define debug if (DEBUG) cout

using namespace std;

class Library
{
    public:
        // Enumerated types for Library Objects
        enum LibType {LIBRARY, MEMBER, ASSET, BOOK, PERIODICAL};
	// The default constructor creaes a new library object.
	Library ();
	// This constructor will create a new library object identical to the passed library
	// object.
	Library (const Library & S);
	// This destructor currently does nothing.
	~Library ();
	// This assignment operator will copy one object to another of the same type.
	Library & operator = (const Library & S);
	// The IsA function will return the appropriate LibType value.
	virtual LibType IsA () const;
	// The input operator will call the ReadIn function for the passed library object.
	friend istream & operator >> (istream & outs, const Library & S);
	// The output operator will call the WriteOut function for the passed library object.
	friend ostream & operator << (ostream & outs, const Library & S);
	//
	virtual void CheckOut ();
	//
	virtual void Return ();
	//
	virtual void ReadIn (istream & input);
	//
	virtual void WriteOut (ostream & output);
    protected:
	LibType Type;
	string Name;
	string ID;
    private:
};

#endif
