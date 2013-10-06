#ifndef DATE_H
#define DATE_H

// File: Date.h
// Author: Kyle Janssen
// Contents: This file contains the description of a class called Date.

#include <iostream>
using namespace std;

class Date
{
    public:
        // Default constructor for date
        Date ();

	// This copy constructor will create a Date object identical to
	// the passed Date object.
	Date (const Date & D);

	// This constructor will create a Date oject with that reprisents
	// the date of the passed values.
	Date (int inMonth, int inDay, int inYear);

	// This assignment operator will copy the values of one Date object
	// to another.
	Date & operator = (const Date & D);

	// This destructor currently does nothing.
	~Date ();

	// This mutator function sets the month of the date to the passed value.
	void SetMonth (int inMonth);

	// This mutator function sets the day of the date to the passed value.
	void SetDay (int inDay);

	// This mutator function sets the year of the date to the passed value.
	void SetYear (int inYear);

	// This accessor function returns the value of month.
	int GetMonth () const;

	// This accessor function returns the value of day.
	int GetDay () const;

	// This accessor function returns the value of year.
	int GetYear () const;

	// This subtraction operator retuns the difference in days between the
	// caller and the passed object.
	int operator - (const Date & D) const;

	// This less-than operator returns true if the calling Date is before
	// the passed Date.
        bool operator < (const Date & D) const;

	// This greater-than operator returns true if the calling Date is after
	// the passed Date.
	bool operator > (const Date & D) const;

	// This input operator sets the values of the passed Date object
	// according to the input mm/dd/yyyy.
	friend istream & operator >> (istream & ins, Date & D);

	// This output operator will output the date in the passed Date
	// object in the form mm/dd/yyyy.
	friend ostream & operator << (ostream & outs, const Date & D);
    private:
	int month;
	int day;
	int year;
};

#endif
