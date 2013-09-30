#include <iostream>
#include "DateConversion.cpp"

using namespace std;

int main(void) {
    int d1, d2, m1, m2, y1, y2;

    cout << "Enter the first date (dd mm yyyy): ";
    cin >> d1 >> m1 >> y1;

    cout << "Enter the second date (dd mm yyyy): ";
    cin >> d2 >> m2 >> y2;

    int days = julian_days(y1, m1, d1) - julian_days(y2, m2, d2);

    cout << d1 << "/" << m1 << "/" << y1 << " - "
         << d2 << "/" << m2 << "/" << y2 << " = " << days << endl;

    return 0;
}
