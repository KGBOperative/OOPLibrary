// File: Periodical.cpp
// Author: Kyle Janssen
// Contents: This file contains the implementation of a class called
// Periodical.

#include <iostream>
#include <ctime>
#include "Library.h"
#include "Asset.h"
#include "Periodical.h"
#include "Date.h"

using namespace std;

Periodical::Periodical ()
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

LibType Periodical::IsA () const
{
    return PERIODICAL;
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

void Periodical::Return ()
{
    // Unsure at this point how to determine which issue to return.
    // This function will need either the number of the issue or the
    // identity of the member who checked it out.
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
	output << "      Number: " << Issues[i].Number << endl;
	output << "Publication_Date: " << Issues[i].PubDate << endl;
	output << "Checked_Out_On: " << Issues[i].CheckedOut << endl;;
	output << "Checked_Out_By: " << Issues[i].CheckedOutBy->ID << endl;
    }
}
