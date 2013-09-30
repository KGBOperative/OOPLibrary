#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{
    public:
        Date ();
	Date (const Date & D);
	Date (int inMonth, int inDay, int inYear);
	Date & operator = (const Date & D);
	~Date ();
	void SetMonth (int inMonth);
	void SetDay (int inDay);
	void SetYear (int inYear);
	int GetMonth () const;
	int GetDay () const;
	int GetYear () const;
	int operator - (const Date & D) const;
        bool operator < (const Date & D) const;
	bool operator > (const Date & D) const;
	friend istream & operator >> (istream & ins, Date & D);
	friend ostream & operator << (ostream & outs, const Date & D);
    private:
	int month;
	int day;
	int year;
};

#endif
