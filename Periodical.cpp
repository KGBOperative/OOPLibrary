// File: Periodical.cpp
// Authors: Amandeep Gill, Kyle Janssen
// Contents: This file contains the implementation of a class called
// Periodical.

#include <iostream>
#include <ctime>
#include "Library.h"
#include "Asset.h"
#include "Periodical.h"
#include "Date.h"

using namespace std;

Periodical::Periodical (void)
{
    Library::Type = PERIODICAL;  
    ISSN = "";
}

Periodical::Periodical (const Periodical & P)
{
    Library::Type = PERIODICAL;
    Type = P.Type;
    ISSN = P.ISSN;
    Issues = P.Issues;
}

Periodical & Periodical::operator = (const Periodical & P)
{
    Type = P.Type;
    ISSN = P.ISSN;
    Issues = P.Issues;
}

LibType Periodical::IsA (void) const
{
    return PERIODICAL;
}

void Periodical::SetType (string TypeS)
{
    switch (TypeS)
    {
        case "FICTION": Type = FICTION; break;
        case "NONFICTION": Type = NONFICTION; break;
        default: cout << "Not a valid Type" << endl;
    }
}


void Periodical::CheckOut (Member * member)
{
    int i = 0;
    while (Issues[i].CheckedOutBy != NULL)
      i++;

    Issues[i].CheckedOutBy = member;

    time_t t = time(0);
    struct tm * now = localtime (&t);
    Issues[i].CheckedOut = Date (now->tm_mon + 1, now->tm_mday, now->tm_year + 1900);
}

void Periodical::Return (void)
{
    for (int i = 0; i < Issues.size(); ++i) {
        if (!Issues[i].CheckedOut.isNull()) {
            Issues[i].CheckedOut.setNull();
            if (Issues[i].CheckedOutBy != NULL)
                Issues[i].CheckedOutBy = NULL;
        }
    }
}

void Periodical::ReadIn (istream & input)
{

}

void Periodical::WriteOut (ostream & output)
{
    output << "Type: PERIODICAL" << endl;
    output << "Name: " << Name << endl;
    output << "ID: " << ID << endl;
    output << "Asset_Type: " << endl;
    output << "ISSN: " << ISSN << endl;
    output << "Issues: " << Issues.size() << endl;
    for (int i = 0; i < Issues.size(); i++) {
        output << "Volume: " << Issues[i].Volume;
        output << "Number: " << Issues[i].Number << endl;
        output << "Publication_Date: " << Issues[i].PubDate << endl;
        output << "Checked_Out_On: " << Issues[i].CheckedOut << endl;;
        output << "Checked_Out_By: ";
        if (Issues[i].CheckedOutBy != NULL)
            output << Issues[i].CheckedOutBy->ID << endl;
        else
            output << "None.\n";
    }
}

Periodical::Issue::Issue(void)
{
    Volume = Number = CopyNumber = 0;
    CheckedOutBy = NULL;
}
