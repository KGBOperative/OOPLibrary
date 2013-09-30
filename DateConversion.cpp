// File: DateConversion.cpp
// Authors: Amandeep Gill
// Contents: This file contains a function that converts the date into the
// number of days using the Julian day conversion algorithm

int julian_days(int year, int month, int day) {
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;

    if (year > 1582 || (year == 1582 && month > 10) || (year == 1582 && month == 10 && day >= 15))
        return day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
    else
        return day + (153 * m + 2) / 5 + 365 * y + y / 4 - 32083;
}
