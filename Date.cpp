// File: Date.cpp
// Author:
// Contents: This file contains the implementation of a class called Date.

#include <iostream>
using namespace std;

Data::Date ()
{
    month = day = year = 0;
}

Date::Date (const Date & D);
{
    month = D.month;
    day = D.day;
    year = D.year;
}

Date:Date (int inMonth, int inDay, int inYear)
{
    month = inMonth;
    day = inDay;
    year = inYear;
}

Date & Date:operator = (const Date & D)
{
    month = D.month;
    day = D.day;
    year = D.year;
}

