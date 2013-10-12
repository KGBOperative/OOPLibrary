#ifndef PERIODICAL_H
#define PERIODICAL_H

// File: Periodical.h
// Authors: Amandeep Gill, 
// Contents: This file contains the description of a class called Periodical.

#include <iostream>
#include <vector>
#include <memory>
#include "Asset.h"
#include "Date.h"

using namespace std;

class Periodical : public Asset
{
    public:
        // Enumerated type for Periodical classification.
        enum PeriodicalType {FICTION, NONFICTION};

        // The default constructor creates a new Periodical object.
        Periodical (void);

        // This copy constructor will create a new Periodical object identical to the
        // passed Periodical object.
        Periodical (const shared_ptr<Periodical> P);

        // This destructor currently does nothing.
        ~Periodical (void);

        // This assignment operator will copy the values of one Periodical object
        // to another.
        shared_ptr<Periodical> operator = (const shared_ptr<Periodical> P);

        // The IsA function will return the appropriate LibType.
        LibType IsA (void) const;
	
        // This function sets Type based on a string value.
        void SetType (string TypeS);

        // This function returns Type as a string.
        void GetString () const;

        // This function sets CheckedOut to the current date and designates
        // the passed member as having checked out the Book.
        void CheckOut (shared_ptr<Library> member);

        // This function designates the Periodical object as being checked in.
        void Return (void);

        // This function reads the state of the Periodical object from input.
        void ReadIn (istream & input);

        // This function writes the state of the Periodical object to output.
        void WriteOut (ostream & output);

    private:
        struct Issue {
            // default constructor for the Issue
            Issue(void);
            
            int Volume;
            int Number;
            Date PubDate;
            Date CheckedOut;
            shared_ptr<Library> CheckedOutBy;
        };

        PeriodicalType Type;
        String ISSN;
        vector <Issue> Issues;
};

#endif
