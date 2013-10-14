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

Book::Book(string name, string id, string aType, string author, string isbn, string bType) {
    Library::Type = BOOK;
    Name = name;
    ID = id;
    
    if (aType == "SHORT") 
        Asset::Type = SHORT;
    else if (aType == "LITERARY")
        Asset::Type = LITERARY;
    else if (aType == "MYSTERY") 
        Asset::Type = MYSTERY;
    else if (aType == "SCIFI")
        Asset::Type = SCIFI;
    else if (aType == "SELFHELP")
        Asset::Type = SELFHELP;
    else if (aType == "BIOGRAPHY")
        Asset::Type = BIOGRAPHY;
    else if (aType == "COOKING")
        Asset::Type = COOKING;
    else if (aType == "SPORTS")
        Asset::Type = SPORTS;

    Author = author;
    ISBN = isbn;
    Library::Type = BOOK;

    if (bType == "FICTION")
        Book::Type = FICTION;
    else if (bType == "NONFICTION")
        Book::Type = NONFICTION;
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

vector<Date> Book::GetCheckoutDates(void) const {
    return vector<Date>(1, CheckedOut);
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
    output << "Asset_Type: " << Asset::GetType() << endl; 
    output << "Author: " << Author << endl;
    output << "ISBN: " << ISBN << endl;
    output << "Checked_Out_On: " << CheckedOut << endl;
    output << "Checked_Out_By: ";

    if (CheckedOutBy != NULL)
        output << CheckedOutBy->GetID();
    else
        output << "NONE";

    output << endl;
}

void Book::Add(shared_ptr<Library> member, Date checkoutDate, int number) {
    CheckedOut = checkoutDate;
    CheckedOutBy = member;
}

void Book::Remove(shared_ptr<Library> member, int number) {
    CheckedOut.SetNull();
    CheckedOutBy = NULL;
}
