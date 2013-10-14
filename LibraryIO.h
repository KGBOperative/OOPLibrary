#ifndef LIBRARYIO_H
#define LIBRARYIO_H

// File: LibraryIO.h
// Authors: Amandeep Gill, Marshall Jankovsky
// Contents: This file contains the function prototypes for inputing and outputing Library objects

#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <map>
#include <iostream>
#include <exception>

#include "Library.h"
#include "Book.h"
#include "Periodical.h"
#include "Member.h"

using namespace std;

// Comparison operators for dealing with shared_ptr's 
// equality
template<class T> inline bool operator==(const shared_ptr<T> lhs, const shared_ptr<T> rhs) {
    return *lhs == *rhs;
}

// lessthan
template<class T> inline bool operator<(const shared_ptr<T> lhs, const shared_ptr<T> rhs) {
    return *lhs < *rhs;
}

// equality with one shared_ptr
template<class T, class U> inline bool operator==(const shared_ptr<T> lhs, const U &rhs) {
    return *lhs == rhs;
}

// lessthan with one shared_ptr
template<class T, class U> inline bool operator<(const shared_ptr<T> lhs, const U &rhs) {
    return *lhs < rhs;
}

// struct to hold the checkout information while the Library objects are being read in
struct COAsset {
    // Constructor
    inline COAsset(void) {
        assetID = "";
        coBy = "";
        coDate = Date("00/00/00");
        issueNum = 0;
    }

    // overloaded equality operator
    inline bool operator==(const string &id) {
        return assetID == id;
    }

    inline bool operator==(const COAsset &coa) {
        if (assetID == coa.assetID)
            return issueNum == coa.issueNum;
        return false;
    }

    // ID of the asset being checked out
    string assetID;
    // who checked-out the asset
    string coBy;
    // checkout date
    Date coDate;
    // issue num; -1 if asset is not a periodical
    int issueNum;
};

// function to load the library from the backup file specified by the user
void loadLib(vector<shared_ptr<Library> > &L) throw(const string);

// function to write the library to a backup file specified by the user
void saveLib(vector<shared_ptr<Library> > &L);

// function to allow the user to add a member to the library manually
void addMember(vector<shared_ptr<Library> > &L);

// function to read in and create a member from input stream
shared_ptr<Library> readMember(istream &input);

// function to allow the user to manually add an asset, (book or periodical)
void addAsset(vector<shared_ptr<Library> > &L);

// function to read in and create a periodical asset from input stream
shared_ptr<Library> readPeriodical(istream &input);

// function to read in and create a book asset from input stream
shared_ptr<Library> readBook(istream &input);

// function to allow the user to manually remove an item from the library
void removeItem(vector<shared_ptr<Library> > &L, string id) throw(const string);

// function to check out an asset to a member
void checkoutAsset(vector<shared_ptr<Library> > &L, string memberID, string assetID, string date) throw(const string);

// function currently does not do anything
void returnAsset(vector<shared_ptr<Library> > &L, string memberID, string assetID) throw(const string);

// function to create a report from the given library
void makeReport(const vector<shared_ptr<Library> > &L);


#endif  // LIBRARYIO_H
