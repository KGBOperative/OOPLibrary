#ifndef BOOK_H
#define BOOK_H

// File: Book.h
// Authors: Amandeep Gill, Kyle Janssen
// Contents: This file contains the description of a class
// called Book.

#include <iostream>
#include <memory>
#include "Asset.h"
#include "Date.h"

using namespace std;

class Book : public Asset
{
    public:
        // Enumerated type for Book Classification
        enum BookType {FICTION, NONFICTION};

        // The default constructor creates a new Book object.
        Book (void);

        // This overloaded constructor will set all informational data at once
        Book(string name, string id, string aType, string author, string isbn, string bType);

        // This copy constructor will create a new Book object identical to the
        // passed Book object.
        Book (const Book &B);

        // This assignment operator will copy the values of one Book object
        // to another.
        shared_ptr<Library> operator = (const Book &B);

        //
        inline void AddIssue(int volume, int number, string pubDate) {}

        // This function sets CheckedOut to the current date and designates
        // the passed member as having checked out the Book.
        void CheckOut (shared_ptr<Library> member);

        // This function designates the Book object as being checked in.
        void Return (void);

        // This function reads the state of the Book object from input.
        void ReadIn (istream & input);

        // This function writes the state of the Book object to output.
        void WriteOut (ostream & output);

    private:
        string Author;
        string ISBN;
        BookType Type;
        Date CheckedOut;
        shared_ptr<Library> CheckedOutBy;
};

#endif
