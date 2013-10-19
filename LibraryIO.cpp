#ifndef LIBRARYIO_CPP
#define LIBRARYIO_CPP

// File: LibraryIO.cpp
// Authors: Amandeep Gill, Marshall Jankovsky, Kyle Janssens
// Contents: This file contains the implememntation of the functions defined in Menu.h

#include "LibraryIO.h"
#include "Date.h"
#include <iostream>
#include <iomanip>

using namespace std;

void loadLib(vector<shared_ptr<Library> > &L) throw(const string) {
    string filename;
    cout << "Enter the filename of the library to load: ";
    cin >> filename; 
    ifstream infile(filename.c_str());
    
    if(infile.fail())
        throw (filename + " not found");
    
    map<string, vector<shared_ptr<COAsset> > > checkout;
    
    while (infile.good()) {
        string Type;
        infile >> Type;
        
        if (Type == "Type:") {
            infile >> Type;
            
            debug << "found Type = " << Type << endl;
            
            if (Type == "MEMBER") {
                L.push_back(readMember(infile, checkout));
            } 
            
            else if (Type == "BOOK") {
                L.push_back(readBook(infile, checkout));
            } 
            
            else if (Type == "PERIODICAL") {
                L.push_back(readPeriodical(infile, checkout));
            } 
            
            else {
                // Not a valid type
                throw "unknown type";
            }
        }
    }
    
    checkoutAll(L, checkout);
}

shared_ptr<Library> readMember(istream &infile, map<string, vector<shared_ptr<COAsset> > > &checkout) {
    debug << "Entering readMember()\n";
    // call function to make a member from input file
    shared_ptr<Library> member(new Member);
    infile >> member;
    
    string ignoreThis;
    infile >> ignoreThis;
    int coItems;
    infile >> coItems;
    
    debug << "number of checked out items = " << coItems << endl;
    
    string memberID = member->GetID();
    for (int i = 0; i < coItems; ++i) {
        string id;
        infile >> id;
        debug << "inside coItem loop with id = " << id << endl;
        
        shared_ptr<COAsset> coa(new COAsset);
        coa->assetID = id;
        
        auto assets = checkout[memberID];
        auto iter = find(assets.begin(), assets.end(), coa);
        
        if (iter == assets.end()) {
            debug << "coa = " << endl << *coa;
            //checkout[memberID].push_back(coa);
        }

        else {
            debug << "coa found " << endl; //<< *iter;
        }
    }

    debug << "Leaving readMember()\n\n";
    return member;
}

shared_ptr<Library> readPeriodical(istream &infile, map<string, vector<shared_ptr<COAsset> > > &checkout) {
    debug << "Entering readPeriodical()\n";
    // call function to make periodical from input file
    shared_ptr<Library> periodical(new Periodical);
    infile >> periodical;
    
    string field;
    int issues;
    
    infile >> field >> issues;
    
    debug << "number of periodical issues = " << issues << endl;
    
    for (int i = 0; i < issues; ++i) {
        string pubDate, date, id;
        int volume, number;
        
        infile >> field >> volume;
        infile >> field >> number;
        infile >> field >> pubDate;
        infile >> field >> date;
        infile >> field >> id;
        
        periodical->AddIssue(volume, number, pubDate);
        
        debug << "periodical issue #" << number << " checked out by = " << id << endl;
        
        if (id != "NONE") {
            shared_ptr<COAsset> coa(new COAsset);
            coa->assetID = periodical->GetID();
            coa->coBy = id;
            coa->coDate = date;
            coa->issueNum = number;
            
            auto assets = checkout[id];
            auto iter = find(assets.begin(), assets.end(), coa);
            
            if (assets.size() < 1 || iter == assets.end()) {
                debug << "new coa = " << endl << *coa;
                checkout[id].push_back(coa);
            }
            
            else
                debug << "coa found" << endl;
        }
    }
    
    debug << "Exiting readPeriodical()\n\n";
    return periodical;
}

shared_ptr<Library> readBook(istream &infile, map<string, vector<shared_ptr<COAsset> > > &checkout) {
    debug << "Entering readBook()\n";
    // call function to make a book from input file
    shared_ptr<Library> book(new Book);
    infile >> book;
    
    string id;
    infile >> id >> id;
    
    debug << "book " << book->GetID() << " is checked out by " << id << endl;
    
    if (id != "NONE") {
        shared_ptr<COAsset> coa(new COAsset);
        coa->assetID = book->GetID();
        coa->coDate = (book->GetCheckoutDates())[0];
        coa->coBy = id;
        
        auto assets = checkout[id];
        auto iter = find(assets.begin(), assets.end(), *coa);
        if (iter == assets.end()) {
            debug << "new coa = " << endl << *coa;
            checkout[id].push_back(coa);
        }
        
        else
            debug << "coa found" << endl;
    }
    
    debug << "Exiting readBook()\n\n";
    return book;
}

void checkoutAll(vector<shared_ptr<Library> > &L, map<string, vector<shared_ptr<COAsset> > > &m) {
    for (auto map_iter = m.begin(); map_iter != m.end(); ++map_iter) {
        debug << "member id = " << map_iter->first;
        
        shared_ptr<Library> searchMem(new Library(map_iter->first));
        shared_ptr<Library> member = *find(L.begin(), L.end(), searchMem);
        debug << " (" << member->GetID() << ")";
        auto assets = map_iter->second;
        
        debug << " has checked out " << assets.size() << " assets\n";
        
        for (unsigned int i = 0; i < assets.size(); ++i) {
            debug << "\t" << assets[i]->assetID << endl;
            shared_ptr<Library> asset = *find(L.begin(), L.end(), shared_ptr<Library>(new Library(assets[i]->assetID)));
            Library::CheckOut(member, asset, assets[i]->coDate, assets[i]->issueNum);
            // checkoutAsset(member, asset, assets[i]->coDate, assets[i]->issueNum);
        }
        
        debug << endl;
    }
}

void saveLib(vector<shared_ptr<Library> > &L) {
    string filename;
    cout << "Enter file to write to: ";
    cin >> filename;
    cin.ignore();
    
    ofstream outfile(filename.c_str());
    
    for (unsigned int i = 0; i < L.size(); ++i)
        outfile << L[i];
}

void addMember(vector<shared_ptr<Library> > &L) {
    string name, id, address, city, state, zip, phone;
    cin.ignore();
    cout << "Creating new member\n";
    cout << "Member Name: ";
    getline(cin, name);
    cout << "Member ID: ";
    getline(cin, id);
    cout << "Member Address: ";
    getline(cin, address);
    cout << "Member City: ";
    getline(cin, city);
    cout << "Member State: ";
    getline(cin, state);
    cout << "Member Zip: ";
    getline(cin, zip);
    cout << "Member Phone #: ";
    getline(cin, phone);
    
    shared_ptr<Library> newMem(new Member(name, id, address, city, state, zip, phone));
    L.push_back(newMem);
    return;
}

void removeItem(vector<shared_ptr<Library> > &L, string id) throw(const string)  {
    for (unsigned int i = 0; i < L.size(); ++i) {
        if (*L[i] == id) {
            L.erase(L.begin() + i);
            return;
        }
    }
    
    throw ("ID: " + id + " not found");
}

void addAsset(vector<shared_ptr<Library> > &L) {
    char choice;
    bool valid = false; 
    while(!valid) {
        cout << "Enter Asset type to create-\n";
        cout << "\t1) Book\n";
        cout << "\t2) Periodical\n";
        cout << "Type: ";
        
        cin >> choice; 
        
        if (choice != '1' && choice != '2')
            cout << "Invalid choice\n";
        
        else
            valid = true;
    }
    
    // Book 
    if (choice == '1') {
        string name, id, asType, author, isbn, bookType; 
        
        cin.ignore();
        cout << "Creating new Book\n";
        cout << "Book Title: ";
        getline(cin, name);
        cout << "Book ID: ";
        getline(cin, id);
        cout << "Asset Type: ";
        getline(cin, asType);
        cout << "Author: ";
        getline(cin, author);
        cout << "ISBN: ";
        getline(cin, isbn);
        cout << "Book Type: ";
        getline(cin, bookType);
        
        shared_ptr<Library> newBook(new Book(name, id, asType, author, isbn, bookType));
        L.push_back(newBook);
    }	
    
    // Periodical 
    else {
        string name, author, id, asType, issn, pubDate;
        int numIssues, volume, volNum; 
        
        cin.ignore();
        cout << "Creating new Periodical:\n";
        cout << "Periodical Title: ";
        getline(cin, name);
        cout << "Periodical ID: ";
        getline(cin, id);
        cout << "Asset Type: ";
        getline(cin, asType);
        cout << "ISSN: ";
        getline(cin, issn);
        cout << "Number of issues to store: ";
        cin >> numIssues;
        
        shared_ptr<Library> newPeri(new Periodical(name, id, asType, issn));
        
        for (int i = 0; i < numIssues; ++i) {
            cout << "Volume: ";
            cin >> volume;
            volNum = i + 1;
            cout << "Publication Date (MM/DD/YYYY): ";
            cin >> pubDate;
            
            newPeri->AddIssue(volume, volNum, pubDate);
        }
        
        L.push_back(newPeri);
    }
}

void checkoutAsset(vector<shared_ptr<Library> > &L, string memberID, string assetID, Date date, int number) throw(const string) {
    int member = -1;
    int asset = -1;
    
    for (unsigned int i = 0; i < L.size() && (member < 0 || asset < 0); ++i) {
        if (*L[i] == memberID)
            member = i;
        else if (*L[i] == assetID)
            asset = i;
    }
    
    if (member >= 0 && asset >= 0)
        Library::CheckOut(L[member], L[asset], date, number);
    
    else if (member == -1) {
        throw ("member " + memberID + " not found");
    }
    
    else {
        throw ("asset " + assetID + " not found");
    }
}

void returnAsset(vector<shared_ptr<Library> > &L, string memberID, string assetID, int number) throw(const string) {
    int member = -1;
    int asset = -1;
    for (unsigned int i = 0; i < L.size() && (member < 0 || asset < 0); ++i) {
        if (*L[i] == memberID)
            member = i;
        else if (*L[i] == assetID)
            asset = i;
    }
    
    if (member >= 0 && asset >= 0)
        Library::Return(L[member], L[asset], number);
    
    else if (member == -1) {
        throw ("member " + memberID + " not found");
    }
    
    else {
        throw ("asset " + assetID + " not found");
    }
}

void makeReport(const vector<shared_ptr<Library> > &L) {
    char choice;
    Date today = Date::Today();
    do {
        cout << "Report Menu:\n";
        cout << "\t1) List overdue Assets\n";
        cout << "\t2) List members with overdue Assets\n";
        cout << "\t3) List members in a specified area code\n";
        cout << "\tq) Quit\n";
        cout << "Selection: ";
        
        cin >> choice; 
        choice = tolower(choice);
        
        switch (choice) {
            case '1': 
                overdueAssetList(L, today);
		break;
            case '2': 
                overdueMemberList(L, today);
		break;
            case '3': 
                areaCodeList(L, today);
		break;
            case 'q':
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 'q');
}

void overdueAssetList(const vector<shared_ptr<Library> >&L, Date & today)
{
    cout << "\n\t\tOverdue Assets as of " << today << endl << endl;

    for (unsigned int i=0;i<L.size();i++) {//for each Lib object 
        vector<Date> coDates = L[i]->GetCheckoutDates(); // Get the checkout dates for each object
        
        for (unsigned int j=0; j<coDates.size(); j++) {// iterate through each due date for each object 
	    if (L[i]->IsA() == Library::BOOK && today - coDates[j] > 27) { // if it is an overdue book
	        cout << "Days_Overdue: " << today - coDates[j] - 27 << endl;
	        L[i]->WriteOut(cout); // Write out the information
	    } else if (L[i]->IsA() == Library::PERIODICAL && today - coDates[j] > 11) // if it is an overdue peri
                L[i]->WriteOut(cout); // Write out the information
        }
    }
}

void overdueMemberList (const vector<shared_ptr<Library> > &L, const Date today) {
    return;
}

void areaCodeList (const vector<shared_ptr<Library> > &L, const Date today)
{
    string areaCode;
    vector<shared_ptr<Library> > areaMembers;
    cout << "Enter 3-digit area code: ";
    cin >> areaCode;
    cout << "\n\tMembers in Area Code " << areaCode << " as of " << today << endl << endl;
    cout << "ID    Name                  Phone\n";
    cout << "----------------------------------------\n";

    for (unsigned int i = 0; i < L.size(); i++)
        if (L[i]->IsA() == Library::MEMBER && L[i]->GetPhone().substr(0, 3) == areaCode)
	    areaMembers.push_back(L[i]);

    sort(areaMembers.begin(), areaMembers.end(), IDSort);

    for (unsigned int i = 0; i < areaMembers.size(); i++)
        cout << areaMembers[i]->GetID() << "  " << setw(20) << setfill(' ') << left
	     << areaMembers[i]->GetName() << "  " << areaMembers[i]->GetPhone() << endl;

    cout << endl;

    return;
}

bool IDSort (shared_ptr<Library> L1, shared_ptr<Library> L2)
{
    return *L1 < *L2;
}

bool OverdueSort (shared_ptr<Library> L1, shared_ptr<Library> L2)
{
  //int days1, days2;
  //days1 = (L1->IsA() == Library::BOOK) ? (L1->  ) : (  ) 

    return false;
}

#endif
