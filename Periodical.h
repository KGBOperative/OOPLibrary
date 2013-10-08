#ifndef PERIODICAL_H
#define PERIODICAL_H

// File: Periodical.h
// Authors: Amandeep Gill, 
// Contents: This file contains the description of a class called Periodical.

#include <iostream>
#include <vector>
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
        Periodical (const Periodical & P);

        // This destructor currently does nothing.
        ~Periodical (void);

        // This assignment operator will copy the values of one Periodical object
        // to another.
        Periodical & operator = (const Periodical & P);

        // The IsA function will return the appropriate LibType.
        LibType IsA (void) const;

        // This function sets CheckedOut to the current date and designates
        // the passed member as having checked out the Book.
        void CheckOut (Member * member);

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
            Member * CheckedOutBy;
            int CopyNumber;
        };

        PeriodicalType Type;
        String ISSN;
        vector <Issue> Issues;
};

#endif
