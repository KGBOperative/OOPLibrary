#ifndef BOOK_H
#define BOOK_H

// File: Book.h
// Author:
// Contents: This file contains the description of a class
// called Book.

#include <iostream>
#include "Asset.h"
#include "Date.h"

#define DEBUG 0
#define debug if (DEBUG) cout

using namespace std;

class Book : public Asset
{
    public:
        // Enumerated type for Book Classification
        enum BookType {FICTION, NONFICTION};
	// More Methods - see Member
    private:
	string Author;
	string ISBN;
	BookType Type;
	int CopyNumber;
	Date CheckedOut;
	Member * CheckedOutBy;
};

#endif
