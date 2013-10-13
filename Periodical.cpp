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

Periodical::Periodical (string name, string id, string aType, string issn) {
    Library::Type = PERIODICAL;
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

     ISSN = issn;
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

    return *this;
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

string Periodical::GetType (void) const
{
    switch (Type)
    {
        case FICTION: return "FICTION";
        case NONFICTION: return "NONFICTION";
        default: return "";
    }
}

void Periodical::AddIssue(int volume, int volNum, string pubDate) {
    Issue issue;
    issue.Volume = volume;
    issue.Number = volNum;
    issue.PubDate = pubDate;

    Issues.push_back(issue);
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
    for (unsigned int i = 0; i < Issues.size(); ++i) {
        if (!Issues[i].CheckedOut.isNull()) {
            Issues[i].CheckedOut.SetNull();

            if (Issues[i].CheckedOutBy != NULL)
                Issues[i].CheckedOutBy = NULL;
        }
    }
}

void Periodical::ReadIn (istream & input)
{
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
        
        else if (value == "ISSN") 
            input >> ISSN;

        else if (value == "Issues") {
            int numIssues;
            input >> numIssues;

            for (int i; i < numIssues; i++) {
                Issue issue;

                for (value; input.good(); input >> value) {

                    if (value == "Volume:")
                        input >> issue.Volume;
                    
                    else if (value == "Number:")
                        input >> issue.Number;
                    
                    else if (value == "Publication_Date:")
                        input >> issue.PubDate;
                    
                    else if (value == "Checked_Out_On:") {
                        input >> issue.CheckedOut;
                        break;
                    }
                }

                Issues.push_back(issue);
            }
                    
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
                    
    for (unsigned int i = 0; i < Issues.size(); i++) {
        output << "Volume: " << Issues[i].Volume;
        output << "Number: " << Issues[i].Number << endl;
        output << "Publication_Date: " << Issues[i].PubDate << endl;
        output << "Checked_Out_On: " << Issues[i].CheckedOut << endl;;
        output << "Checked_Out_By: ";
                    
        if (Issues[i].CheckedOutBy != NULL)
            output << Issues[i].CheckedOutBy->GetID() << endl;
                    
        else
            output << "None.\n";
    }
}

Periodical::Issue::Issue(void)
{
    Volume = Number = 0;
    CheckedOutBy = NULL;
}
