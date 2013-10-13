// File: Library.cpp
// Author: Kyle Janssen
// Contents: This file contains the implementation of a class called Library.

#include <iostream>
#include "Library.h"
using namespace std;

Library::Library () {
    Type = LIBRARY;
}

Library::Library (const shared_ptr<Library> S) {
    Type = S->Type;
    Name = S->Name;
    ID = S->ID;
}


shared_ptr<Library> Library::operator = (const shared_ptr<Library> S) {
    Type = S->Type;
    Name = S->Name;
    ID = S->ID;

    return shared_ptr<Library>(this);
}


Library::LibType Library::IsA () const {
    return Type;
}


istream & operator >> (istream & ins, const shared_ptr<Library> S) {
    S->ReadIn(ins);
    return ins;
}


ostream & operator << (ostream & outs, const shared_ptr<Library> S) {
    S->WriteOut(outs);
    return outs;
}

void Library::SetType (string TypeS) {
    if (TypeS == "LIBRARY") 
        Type = LIBRARY;

    else if (TypeS == "MEMBER") 
        Type = MEMBER;
    
    else if (TypeS == "ASSET") 
        Type = ASSET;
    
    else if (TypeS == "BOOK") 
        Type = BOOK;
    
    else if (TypeS == "PERIODICAL") 
        Type = PERIODICAL;
    
    else 
        cout << "Not a valid LibType" << endl;
}

string Library::GetType () const {
    switch (Type)
    {
        case LIBRARY: return "LIBRARY";
        case MEMBER: return "MEMBER";
        case ASSET: return "ASSET";
        case BOOK: return "BOOK";
        case PERIODICAL: return "PERIODICALa";
        default: return "";
    }
}

void Library::CheckOut (shared_ptr<Library>member, shared_ptr<Library>asset, Date date) {
    member->Add(asset, date);
    asset->Add(member, date);
}


void Library::Return (shared_ptr<Library>member, shared_ptr<Library>asset) {
    member->Remove(asset);
    asset->Remove(member);
}


void Library::ReadIn (istream & input) {
}


void Library::WriteOut (ostream & output) {
    output << "Type: LIBRARY" << endl;
    output << "Name: " << Name << endl;
    output << "ID: "   << ID   << endl;
}

string Library::GetID(void) {
    return ID;
}

bool Library::operator==(const shared_ptr<Library> lib) {
    return ID == lib->ID;
}

bool Library::operator==(const string &id) {
    return ID == id;
}

bool Library::operator<(const shared_ptr<Library> lib) {
    return ID < lib->ID;
}

