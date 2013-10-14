#ifndef LIBRARYIO_CPP
#define LIBRARY()_CPP

// File: LibraryIO.cpp
// Authors: Amandeep Gill, Marshall Jankovsky, Kyle Janssens
// Contents: This file contains the implememntation of the functions defined in Menu.h

#include "LibraryIO.h"
#include <iostream>
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
                debug << "Entering if (Type == \"MEMBER\")\n";
                // call function to make a member from input file
                shared_ptr<Library> member(new Member);
                infile >> member;
                L.push_back(member);
                
                int coItems;
                infile >> coItems;
                
                debug << "number of checked out items = " << coItems << endl;
                
                for (int i = 0; i < coItems; ++i) {
                    debug << "inside coItem loop\n";
                    string id;
                    infile >> id;
                    
                    shared_ptr<COAsset> coa(new COAsset);
                    coa->assetID = id;
                    
                    auto assets = checkout[member->GetID()];
                    auto iter = find(assets.begin(), assets.end(), coa);
                    if (iter != assets.end())
                        assets.push_back(coa);
                }

                debug << "Leaving if (Type == \"MEMBER\")\n";
            } 
            
            else if (Type == "BOOK") {
                // call function to make a book from input file
                shared_ptr<Library> book(new Book);
                infile >> book;
                L.push_back(book);
                
                string id;
                infile >> id >> id;
                
                debug << "book id = " << id << endl;
                
                if (id != "NONE") {
                    shared_ptr<COAsset> coa(new COAsset);
                    coa->assetID = book->GetID();
                    coa->coDate = (book->GetCheckoutDates())[0];
                    coa->coBy = id;
                    
                    auto assets = checkout[id];
                    auto iter = find(assets.begin(), assets.end(), coa);
                    if (iter != assets.end())
                        assets.push_back(coa);
                }
            } 
            
            else if (Type == "PERIODICAL") {
                // call function to make periodical from input file
                shared_ptr<Library> periodical(new Periodical);
                infile >> periodical;
                L.push_back(periodical);
                
                string field;
                int issues;
                
                infile >> field >> issues;
                
                for (int i = 0; i < issues; ++i) {
                    string pubDate, date, id;
                    int volume, number;
                    
                    infile >> field >> volume;
                    infile >> field >> number;
                    infile >> field >> pubDate;
                    infile >> field >> date;
                    infile >> field >> id;
                    
                    periodical->AddIssue(volume, number, pubDate);
                    
                    debug << "periodical id = " << id << endl;
                    
                    if (id != "NONE") {
                        shared_ptr<COAsset> coa(new COAsset);
                        coa->assetID = periodical->GetID();
                        coa->coDate = date;
                        coa->issueNum = number;

                        auto assets = checkout[id];
                        auto iter = find(assets.begin(), assets.end(), coa);
                        if (iter != assets.end())
                            assets.push_back(coa);
                    }
                }
            } 

            else {
                // Not a valid type
                throw "unknown type";
            }
        }
    }

    for (auto map_iter = checkout.begin(); map_iter != checkout.end(); ++map_iter) {
        cout << map_iter->first << endl;

        shared_ptr<Library> searchMem(new Library(map_iter->first));
        shared_ptr<Library> member = *find(L.begin(), L.end(), searchMem);
        auto assets = map_iter->second;

        for (unsigned int i = 0; i < assets.size(); ++i) {
            shared_ptr<Library> asset = *find(L.begin(), L.end(), shared_ptr<Library>(new Library(assets[i]->assetID)));
            if (assets[i]->issueNum > 0)
                Library::CheckOut(member, asset, assets[i]->coDate, assets[i]->issueNum);
            else
                Library::CheckOut(member, asset, assets[i]->coDate);
        }
    }
}

void saveLib(vector<shared_ptr<Library> > &L) {
    string filename;
    cout << "Enter file to write to: ";
    cin >> filename;

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

    string err = "ID: " + id + " not found";
    throw err;
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

void checkoutAsset(vector<shared_ptr<Library> > &L, string memberID, string assetID, string checkoutDate) throw(const string) {
    int member = -1;
    int asset = -1;
    Date date(checkoutDate);

    for (unsigned int i = 0; i < L.size() && (member < 0 || asset < 0); ++i) {
        if (*L[i] == memberID)
            member = i;
        else if (*L[i] == assetID)
            asset = i;
    }

    if (member >= 0 && asset >= 0)
        Library::CheckOut(L[member], L[asset], date);

    else if (member == -1) {
        string err = "member " + memberID + " not found";
        throw err;
    }

    else {
        string err = "asset " + assetID + " not found";
        throw err;
    }
}

void returnAsset(vector<shared_ptr<Library> > &L, string memberID, string assetID) throw(const string) {
    int member = -1;
    int asset = -1;
    for (unsigned int i = 0; i < L.size() && (member < 0 || asset < 0); ++i) {
        if (*L[i] == memberID)
            member = i;
        else if (*L[i] == assetID)
            asset = i;
    }

    if (member >= 0 && asset >= 0)
        Library::Return(L[member], L[asset]);

    else if (member == -1) {
        string err = "member " + memberID + " not found";
        throw err;
    }

    else {
        string err = "asset " + assetID + " not found";
        throw err;
    }
}

void makeReport(const vector<shared_ptr<Library> > &L) {
    char choice; 
    do {
        cout << "Report Menu:\n";
        cout << "\t1) List overdue Assets\n";
        cout << "\t2) List members with overdue Assets\n";
        cout << "\t3) List members in a specified area code\n";
        cout << "\tq) Quit\n";
        cout << "Selection: ";

        cin >> choice; 
        tolower(choice);

        switch (choice) {
            case '1':
            case '2':
            case '3':
            case 'q':
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 'q');
}

#endif
