// File: Date.cpp
// Author:
// Contents: This file contains the implementation of a class called Date.

#include <iostream>
#include <iomanip>
#include <sstream>

#include "Date.h"

using namespace std;

Date::Date (void) {
    month = day = year = -1;
}

Date::Date (const Date & D) {
    month = D.month;
    day = D.day;
    year = D.year;
}

Date::Date (string date) {
    /*
    stringstream ss(date);
    ss >> month >> day >> year;
    */
}

Date::Date (int inMonth, int inDay, int inYear) {
    month = inMonth;
    day = inDay;
    year = inYear;
}

Date & Date::operator = (const Date & D) {
    month = D.month;
    day = D.day;
    year = D.year;

    return *this;
}

void Date::SetDate (string date) {
    stringstream ss(date);
    ss >> month >> day >> year;
}

void Date::SetMonth (int inMonth) {
    month = inMonth;
}

void Date::SetDay (int inDay) {
    day = inDay;
}

void Date::SetYear (int inYear) {
    year = inYear;
}

string Date::GetDate (void) const {
    string date;
    stringstream ss(date);
    ss << month << "/" << day << "/" << year;

    return date;
}

int Date::GetMonth (void) const {
    return month;
}

int Date::GetDay (void) const {
    return day;
}

int Date::GetYear (void) const {
    return year;
}

void Date::SetNull(void) {
    day = month = year = -1;
}

bool Date::isNull(void) const {
    return (day == -1 || month == -1 || year == -1) ? true : false;
}

int Date::operator - (const Date & D) const {
    return isNull() ? julian_days(D.year, D.month, D.day) : julian_days(year, month, day) - julian_days(D.year, D.month, D.day);
}

bool Date::operator < (const Date & D) const {
    if (!isNull()) {
        if (year != D.year)
            return year < D.year;

        else if (month != D.month)
            return month < D.month;

        else
            return day < D.day;
    }
    else
        return D.isNull() ? false : true;
}

bool Date::operator > (const Date & D) const {
    if (!isNull()) {
        if (year != D.year)
            return year > D.year;

        else if (month != D.month)
            return month > D.month;

        else
            return day > D.day;
    }
    else
        return D.isNull() ? false : true;
}

istream & operator >> (istream & ins, Date & D) {
    ins >> D.month;
    ins.ignore();
    ins >> D.day;
    ins.ignore();
    ins >> D.year;

    return ins;
}

ostream & operator << (ostream & outs, const Date & D) {
    outs << setw(2) << setfill('0');

    if (!D.isNull()) 
         outs <<  D.month << "/" << D.day << "/" << D.year;
    else
        outs << "00/00/00";

    return outs;
}


