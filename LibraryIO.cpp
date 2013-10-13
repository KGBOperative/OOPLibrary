// File: LibraryIO.cpp
// Authors: Amandeep Gill, Marshall Jankovsky, Kyle Janssens
// Contents: This file contains the implememntation of the functions defined in Menu.h

#include "LibraryIO.h"

void loadLib(vector<shared_ptr<Library> > &L)
{
    char *filename;
    cout << "Enter the filename of the library to load:\n";
    cin >> filename; 
    ifstream infile(filename);

    if(infile.fail()) {
        cout << filename << " not found.\n";
        return;
    }

    while (infile.good()) {
        string Type;
        infile >> Type;

        if (Type == "Type:") {
            infile >> Type;

            if (Type == "MEMBER") {
                // call function to make a member from input file
            } 

            else if (Type == "BOOK") {
                // call function to make a book from input file
            } 

            else if (Type == "PERIODICAL") {
                // call function to make periodical from input file
            } 

            else {
                // Not a valid type
            }
        }
    }
}

void saveLib(vector<shared_ptr<Library> > &L) {
    char* filename;
    cout << "Enter file to write to: ";
    cin >> filename;

    ostream outfile(filename);

    for (int i = 0; i < L.size(); ++i)
        outfile << L[i];
}

void addMember(vector<shared_ptr<Library> > &L) {
    string name, id, address, city, stat, zip, phone;
    cout << "Creating new member\n";
    cout << "Member Name: ";
    cin >> name;
    cout << "Member ID: ";
    cin >> id;
    cout << "Member Address: ";
    cin >> address;
    cout << "Member City: ";
    cin >> city;
    cout << "Member State: ";
    cin >> state;
    cout << "Member Zip: ";
    cin >> zip;
    cout << "Member Phone #: ";
    cin >> phone;

    shared_ptr<Library> newMem(new Member(name, id, address, city, state, zip, phone));
    L.push_back(newMem);
    return;
}

void removeItem(vector<shared_ptr<Library> > &L, string id) throw(const char*)  {
    for (int i = 0; i < L.members.size(); ++i) {
        if (L[i] == id) {
            L[i]->erase(L.begin() + i);
            return;
        }
    }

    throw "ID: " + id " not found";
}

void addAsset(vector<shared_ptr<Library> > &L) {
    char choice;
    bool valid = false; 
    while(!valid) {
        cout << "Enter Asset type to create-\n";
        cout << "\t1) Book\n";
        cout << "\t2) Periodical\n";
        cout << "type: ";

        cin >> choice; 
        tolower(choice);

        if (choice != '1' && choice != '2')
            cout << "Invalid choice\n";

        else
            valid = true;
    }

    // Book 
    if (choice == '1') {
        string name, id, asType, author, isbn, bookType; 

        cout << "Creating new Book\n";
        cout << "Book Title: ";
        cin >> name;
        cout << "Book ID: ";
        cin >> id;
        cout << "Asset Type: ";
        cin >> asType;
        cout << "Author: ";
        cin >> author;
        cout << "ISBN: ";
        cin >> isbn;
        cout << "Book Type: ";
        cin >> bookType;
        
        shared_ptr<Library> newBook(new Book(name, id, asType, author, isbn, bookType));
        L.push_back(newBook);
    }	

    // Periodical 
    else {
        string name, id, asType, issn;
        int numIssues, volume, volNum; 
        Date pubDate;  

        cout << "Creating new Periodical:\n";
        cout << "Periodical Title: ";
        cin >> name;
        cout << "Periodical ID: ";
        cin >> id;
        cout << "Asset Type: ";
        cin >> asType;
        cout << "ISSN: ";
        cin >> author;
        cout << "Number of issues to store: ";
        cin >> numIssues;

        for (int i = 0; i < numIssues; ++i) {
            cout << "Volume: ";
            cin >> volume;
            cout << "Number: "
            cin >> volNum;
            cout << "Publication Date (MM/DD/YYYY): "
            cin >> pubDate;

            shared_ptr<Library> newPeri(new Periodical(name, id, asType, issn, numIssues, volume, volNum, pubDate));
            L.push_back(newPeri);
        }
    }
}

void checkoutAsset(vector<shared_ptr<Library> > &L, string memberID, string assetID) throw(const char*) {
    int member = -1;
    int asset = -1;

    for (int i = 0; i < L.size() && (member < 0 || asset < 0); ++i) {
        if (L[i] == memberID)
            member = i;
        else if (L[i] == assetID)
            asset = i;
    }

    if (member >= 0 && asset >= 0)
        Library.CheckOut(L[member], L[asset]);

    else if (member == -1)
        throw "member " + memberID + " not found";

    else
        throw "asset " + assetID + " not found";
}

void returnAsset(vector<shared_ptr<Library> > &L, string memberID, string assetID) throw(const char*) {
    int member = -1;
    int asset = -1;
    for (int i = 0; i < L.size() && (member < 0 || asset < 0); ++i) {
        if (L[i] == memberID)
            member = i;
        else if (L[i] == assetID)
            asset = i;
    }

    if (member >= 0 && asset >= 0)
        Library.Return(L[member], L[asset]);

    else if (member == -1)
        throw "member " + memberID + " not found";

    else
        throw "asset " + assetID + " not found";
}

void makeReport(vector<shared_ptr<Library> > &L const)
{
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
                return;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 'q');
}
