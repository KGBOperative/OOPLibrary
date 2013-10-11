// File: Book.cpp
// Author: Kyle Janssen
// Contents: This file contains the implementation of a class
// called Book.

#include <iostream>
#include <ctime>
#include "Library.h"
#include "Asset.h"
#include "Book.h"

Book::Book ()
{
    Library::Type = BOOK;
    Author = "";
    ISBN = "";
    CopyNumber = 0;
    CheckedOut = Date (0, 0, 0);
    CheckedOutBy = NULL;
}

Book::Book (const Book & B)
{
    Library::Type = BOOK;
    Asset::Type = B.Asset::Type;
    Type = B.Type;
    Author = B.Author;
    ISBN = B.ISBN;
    CopyNumber = B.CopyNumber;
    CheckedOut = B.CheckedOut;
    CheckedOutBy = B.CheckedOutBy;
}

Book & Book::operator = (const Book & B)
{
    Library::Type = BOOK;
    Asset::Type = B.Asset::Type;
    Type = B.Type;
    Author = B.Author;
    ISBN = B.ISBN;
    CopyNumber = B.CopyNumber;
    CheckedOut = B.CheckedOut;
    CheckedOutBy = B.CheckedOutBy;
}

LibType Book::IsA () const
{
    return BOOK;
}

void Book::SetType (string TypeS)
{
    switch (TypeS)
    {
        case "FICTION": Type = FICTION; break;
        case "NONFICTION": Type = NONFICTION; break;
        default: cout << "Not a valid Type" << endl;
    }
}

void Book::CheckOut (Library * L)
{
    time_t t = time(0);
    struct tm * now = localtime (&t);
    CheckedOut = Date (now->tm_mon + 1, now->tm_mday, now->tm_year + 1900);
    CheckedOutBy = L;
}

void Book::Return ()
{
    CheckedOut = Date (0, 0, 0);
    CheckedOutBy = NULL;
}

void Book::ReadIn (istream & input)
{
    input.ignore(256, ' ');
    Name = input.getline();

    input.ignore(256, ' ');
    ID = input.getline();

    input.ignore(256, ' ');
    Asset::Type = input.getline();

    input.ignore(256, ' ');
    Author = input.getline();

    input.ignore(256, ' ');
    ISBN = input.getline();

    input.ignore(256, ' ');
    Type = input.getline();

    input.ignore(256, ' ');
    input >> CheckedOut;

    input.ignore(256, ' ');
    // need to convert ID to pointer to library object
}

void Book::WriteOut (ostream & output)
{
    output << "Type: BOOK" << endl;
    output << "Name: " << Name << endl;
    output << "ID: " << ID << endl;
    output << "Asset_Type: " << Asset::Type << endl; // Not sure how to print enums
    output << "Author: " << Author << endl;
    output << "ISBN: " << ISBN << endl;
    output << "Type: " << Type << endl; // Again, not sure how to print enums
    output << "Checked_Out_On: " << CheckedOut << endl;
    output << "Checked_Out_By: " << CheckedOutBy->ID << endl;
}
