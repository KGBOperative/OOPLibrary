// File: Library.cpp
// Author: Kyle Janssen
// Contents: This file contains the implementation of a class called Library.

#include <iostream>
#include "Library.h"
using namespace std;

Library::Library ()
{
    Type = LIBRARY;
}

Library::Library (const Library & S);
{
    Type = S.Type;
    Name = S.Name;
    ID = S.ID;
}


Library & Library::operator = (const Library & S);
{
    Type = S.Type;
    Name = S.Name;
    ID = S.ID;
}


virtual LibType Library::IsA () const;
{
    return Type;
}


friend istream & operator >> (istream & ins, const Library & S);
{
    S.ReadIn(ins);
    return ins;
}


friend ostream & operator << (ostream & outs, const Library & S);
{
    S.WriteOut(outs);
    return outs;
}

virtual void Library::SetType (string TypeS)
{
    switch (TypeS)
    {
        case "LIBRARY": Type = LIBRARY; break;
        case "MEMBER": Type = MEMBER; break;
        case "ASSET": Type = ASSET; break;
        case "BOOK": Type = BOOK; break;
        case "PERIODICAL": Type = PERIODICAL; break;
        default: cout << "Not a valid LibType" << endl;
    }
}

virtual string Library::GetType () const
{
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

void Library::CheckOut (Library *member, Library *asset, Date date);
{
    member->Add(asset, date);
    asset->Add(member, date);
}


virtual void Library::Return (Library *member, Library *asset);
{
    member->Remove(asset);
    asset->Remove(member);
}


virtual void Library::ReadIn (istream & input);
{
}


virtual void Library::WriteOut (ostream & output);
{
    output << "Type: LIBRARY" << endl;
    output << "Name: " << Name << endl;
    output << "ID: "   << ID   << endl;
}

bool Library::operator==(const Library *lib1, const Library *lib2) {
    return lib1->ID == lib2->ID;
}

bool Library::operator<(const Library *lib1, const Library *lib2) {
    return lib1->ID < lib2->ID;
}

