// File: Periodical.cpp
// Authors: Amandeep Gill, Kyle Janssen
// Contents: This file contains the implementation of a class called
// Periodical.

#include <iostream>
#include <ctime>
#include "Periodical.h"
#include "Date.h"

using namespace std;

Periodical::Periodical (void)
{
    Library::Type = PERIODICAL;  
    ISSN = "";
}

Periodical::Periodical (const shared_ptr<Periodical> P)
{
    Library::Type = PERIODICAL;
    Type = P->Type;
    ISSN = P->ISSN;
    Issues = P->Issues;
}

shared_ptr<Periodical> Periodical::operator = (const shared_ptr<Periodical> P)
{
    Type = P->Type;
    ISSN = P->ISSN;
    Issues = P->Issues;
}

LibType Periodical::IsA (void) const
{
    return PERIODICAL;
}

void Periodical::SetType (string TypeS)
{
    if (TypeS == "FICTION") 
        Type = FICTION;

    else if (TypeS == "NONFICTION") 
        Type = NONFICTION;

/* Not sure if this line is necessary --Aman
    else 
        cout << "Not a valid Type" << endl;
*/
}

string Periodical::GetType () const
{
    switch (Type)
    {
        case FICTION: return "FICTION";
        case NONFICTION: return "NONFICTION";
        default: return "";
    }
}

void Periodical::CheckOut (shared_ptr<Library> member)
{
    int i = 0;
    while (Issues[i].CheckedOutBy != NULL)
      i++;

    Issues[i].CheckedOutBy = member;

    time_t t = time(0);
    unique_ptr<struct tm> now(localtime (&t));
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
    for (string value; input.good(); input >> value) {

        if (value == "Name:") 
            Name = input.getline();
        
        else if (value == "ID:") 
            input >> ID;

        else if (value == "Asset_Type:") {
            string type;
            input >> type;
            Asset::SetType(type);
        } 
        
        else if (value == "Author:") 
            Author = input.getline();

        else if (value == "ISSN") 
            input >> ISSN;

        else if (value == "Issues") {
            int issues;
            input >> issues;

            for (int i; i < issues; i++) {
                Issue issue;

                for (value; input.good(); input >> value) {

                    if (value == "Volume:")
                        input >> issue.Volume;
                    
                    else if (value == "Number:")
                        input >> issue.Number;
                    
                    else if (value == "Publication_Date:")
                        input >> PubDate;
                    
                    else if (value == "Checked_Out_On:")
                        input >> CheckedOut;
                }
            }
                    
            Issues.push_back(issue);
            return;
        }
    }
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
