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

vector<Date> Periodical::GetCheckoutDates(void) const {
    vector<Date> coDates;

    for (unsigned int i = 0; i < Issues.size(); ++i)
        coDates.push_back(Issues[i].CheckedOut);

    return coDates;
}

void Periodical::AddIssue(int volume, int volNum, string pubDate) {
    Issue issue;
    issue.Volume = volume;
    issue.Number = volNum;
    issue.PubDate = pubDate;

    Issues.push_back(issue);
}

void Periodical::ReadIn (istream & input)
{
    for (string line; input.good(); getline(input, line)) {
        int i = line.find(" ");
        string fieldName = line.substr(0, i);
        string fieldData = line.substr(i+1);

        if (fieldName == "Name:")  {
            Name = fieldData;
            debug << "Getting name = " << fieldData << endl;
        }

        else if (fieldName == "ID:") {
            ID = fieldData;
            debug << "Getting ID = " << fieldData << endl;
        }

        else if (fieldName == "Asset_Type:") {
            Asset::SetType(fieldData);
            debug << "Getting Asset_Type = " << fieldData << endl;
        } 

        else if (fieldName == "ISSN:") {
            ISSN = fieldData;
            debug << "Getting ISSN = " << fieldData << endl;
            
            return;
        }
    }
}

void Periodical::WriteOut (ostream & output)
{
    output << "Type: PERIODICAL" << endl;
    output << "Name: " << Name << endl;
    output << "ID: " << ID << endl;
    output << "Asset_Type: " << Asset::GetType() << endl;
    output << "ISSN: " << ISSN << endl;
    output << "Issues: " << Issues.size() << endl;
                    
    for (unsigned int i = 0; i < Issues.size(); i++) {
        output << "Volume: " << Issues[i].Volume;
        output << "\tNumber: " << Issues[i].Number << endl;
        output << "Publication_Date: " << Issues[i].PubDate << endl;
        output << "Checked_Out_On: " << Issues[i].CheckedOut << endl;;
        output << "Checked_Out_By: ";
                    
        if (Issues[i].CheckedOutBy != NULL)
            output << Issues[i].CheckedOutBy->GetID() << endl;
                    
        else
            output << "NONE\n";
    }
}

void Periodical::Add(shared_ptr<Library> member, Date checkedOutDate, int number) {
    Issues[number-1].CheckedOut = checkedOutDate;
    Issues[number-1].CheckedOutBy = member;
}

void Periodical::Remove(shared_ptr<Library> member, int number) {
    Issues[number-1].CheckedOut.SetNull();
    Issues[number-1].CheckedOutBy = NULL;
}

Periodical::Issue::Issue(void)
{
    Volume = Number = 0;
    CheckedOutBy = NULL;
}
