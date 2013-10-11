#ifndef BOOK_H
#define BOOK_H

// File: Book.h
// Author: Kyle Janssen
// Contents: This file contains the description of a class
// called Book.

#include <iostream>
#include "Asset.h"
#include "Date.h"

using namespace std;

class Book : public Asset
{
    public:
        // Enumerated type for Book Classification
        enum BookType {FICTION, NONFICTION};

	// The default constructor creates a new Book object.
	Book ();

	// This copy constructor will create a new Book object identical to the
	// passed Book object.
	Book (const Book & B);

	// This destructor currently does nothing.
	~Book ();

	// This assignment operator will copy the values of one Book object
	// to another.
	Book & operator = (const Book & B);

	// The IsA function will return the appropriate LibType.
	LibType IsA () const;

	// This function sets Type based on a string value.
	void SetType (string TypeS);

	// This function sets CheckedOut to the current date and designates
	// the passed member as having checked out the Book.
	void CheckOut (Library * member);

	// This function designates the Book object as being checked in.
	void Return ();

	// This function reads the state of the Book object from input.
	void ReadIn (istream & input);

	// This function writes the state of the Book object to output.
	void WriteOut (ostream & output);

    private:
	string Author;
	string ISBN;
	BookType Type;
	Date CheckedOut;
	Library * CheckedOutBy;
};

#endif
