// File: Date.cpp
// Author:
// Contents: This file contains the implementation of a class called Date.

#include <iostream>
#include <iomanip>
#include "Date.h"
#include "DateConversion.cpp"
using namespace std;

Date::Date ()
{
    month = day = year = 0;
}

Date::Date (const Date & D)
{
    month = D.month;
    day = D.day;
    year = D.year;
}

Date::Date (int inMonth, int inDay, int inYear)
{
    month = inMonth;
    day = inDay;
    year = inYear;
}

Date & Date::operator = (const Date & D)
{
    month = D.month;
    day = D.day;
    year = D.year;
}

Date::~Date ()
{

}

void Date::SetMonth (int inMonth)
{
    month = inMonth;
}

void Date::SetDay (int inDay)
{
    day = inDay;
}

void Date::SetYear (int inYear)
{
    year = inYear;
}

int Date::GetMonth () const
{
    return month;
}

int Date::GetDay () const
{
    return day;
}

int Date::GetYear () const
{
    return year;
}

int Date::operator - (const Date & D) const
{
  return julian_days(year, month, day) - julian_days(D.year, D.month, D.day);
}

bool Date::operator < (const Date & D) const
{
    if (year != D.year)
        return year < D.year;

    else if (month != D.month)
        return month < D.month;

    else
        return day < D.day;
}

bool Date::operator > (const Date & D) const
{
    if (year != D.year)
        return year > D.year;

    else if (month != D.month)
        return month > D.month;

    else
        return day > D.day;

}

istream & operator >> (istream & ins, Date & D)
{
    ins >> D.month;
    ins.ignore();
    ins >> D.day;
    ins.ignore();
    ins >> D.year;

    return ins;
}

ostream & operator << (ostream & outs, const Date & D)
{
    outs << setw(2) << setfill('0') <<  D.month << "/" << D.day << "/" << D.year;

    return outs;
}

