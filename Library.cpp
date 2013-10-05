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
    return LIBRARY;
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


virtual void Library::CheckOut ();
{
}


virtual void Library::Return ();
{
}


virtual void Library::ReadIn (istream & input);
{
}


virtual void Library::WriteOut (ostream & output);
{
    output << "Type: LIBRARY" << endl;
    output << "Name: " << S.Name << endl;
    output << "ID: "   << S.ID   << endl;
}

