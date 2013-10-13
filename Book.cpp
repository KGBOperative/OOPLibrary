// File: Book.cpp
// Author: Kyle Janssen
// Contents: This file contains the implementation of a class
// called Book.

#include <iostream>
#include <ctime>
#include "Asset.h"
#include "Book.h"

Book::Book () {
    Library::Type = BOOK;
    Author = "";
    ISBN = "";
    CheckedOut = Date (0, 0, 0);
    CheckedOutBy = NULL;
}

Book::Book (const Book &B) {
    Library::Type = BOOK;
    Asset::Type = B.Asset::Type;
    Type = B.Type;
    Author = B.Author;
    ISBN = B.ISBN;
    CheckedOut = B.CheckedOut;
    CheckedOutBy = B.CheckedOutBy;
}

shared_ptr<Library> Book::operator = (const Book &B) {
    Library::Type = BOOK;
    Asset::Type = B.Asset::Type;
    Type = B.Type;
    Author = B.Author;
    ISBN = B.ISBN;
    CheckedOut = B.CheckedOut;
    CheckedOutBy = B.CheckedOutBy;

    return shared_ptr<Library>(this);
}

Library::LibType Book::IsA () const {
    return BOOK;
}

void Book::SetType (string TypeS) {
    if (TypeS == "FICTION") 
        Type = FICTION;

    else if("NONFICTION") 
        Type = NONFICTION;

/* Not sure if this line is necessary --Aman
    else
         cout << "Not a valid Type" << endl;
*/
}

string Book::GetType () const {
    switch (Type)
    {
        case FICTION: return "FICTION";
        case NONFICTION: return "NONFICTION";
        default: return "";
    }
}

void Book::CheckOut (shared_ptr<Library> member) {
    time_t t = time(0);
    unique_ptr<struct tm> now(localtime (&t));
    CheckedOut = Date (now->tm_mon + 1, now->tm_mday, now->tm_year + 1900);
    CheckedOutBy = member;
}

void Book::Return () {
    CheckedOut = Date (0, 0, 0);
    CheckedOutBy = NULL;
}

void Book::ReadIn (istream & input) {
    for (string value; input.good(); input >> value) {

        if (value == "Name:") 
            getline(input, Name);

        else if (value == "ID:") 
            input >> ID;

        else if (value == "Asset_Type:") {
            string type;
            input >> type;
            Asset::SetType(type);
        } 
        
        else if (value == "Author:")
            getline(input, Author);

        else if (value == "ISBN") 
            input >> ISBN;

        else if (value == "Type:") {
            string type;
            input >> type;
            SetType(type);
        } 
        
        else if (value == "Checked_Out_On") {
            input >> CheckedOut;
            return;
        }
    }
}

void Book::WriteOut (ostream & output) {
    output << "Type: BOOK" << endl;
    output << "Name: " << Name << endl;
    output << "ID: " << ID << endl;
    output << "Asset_Type: " << Asset::Type << endl; // Not sure how to print enums
    output << "Author: " << Author << endl;
    output << "ISBN: " << ISBN << endl;
    output << "Type: " << Type << endl; // Again, not sure how to print enums
    output << "Checked_Out_On: " << CheckedOut << endl;
    output << "Checked_Out_By: " << CheckedOutBy->GetID() << endl;
}
