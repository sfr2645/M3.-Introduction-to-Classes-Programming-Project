// M3. Introduction to Classes Programming Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
    cout << "Test default constructor: ";
    Date d1;
    cout << d1.printNumeric() << endl << endl;

    cout << "Test constructor with valid date: ";
    Date d2(2, 28, 2009);
    cout << d2.printNumeric() << endl << endl;

    cout << "Test constructor with invalid month (45, 2, 2009): ";
    Date d3(45, 2, 2009);
    cout << d3.printNumeric() << endl << endl;

    cout << "Test constructor with invalid day (2, 29, 2009): ";
    Date d4(2, 29, 2009);
    cout << d4.printNumeric() << endl << endl;

    cout << "Test setDate with bad month (13): ";
    d2.setDate(13, 10, 2009);
    cout << d2.printNumeric() << endl << endl;

    cout << "Test setDate with bad day (4, 31, 2009): ";
    d2.setDate(4, 31, 2009);
    cout << d2.printNumeric() << endl << endl;

    cout << "Test for leap year with bad date (2/29/2009): ";
    d2.setDate(2, 29, 2009);
    cout << d2.printNumeric() << endl << endl;

    cout << "Test for leap year with good date (2/29/2008): ";
    Date d5(2, 29, 2008);
    cout << d5.printNumeric() << endl << endl;

    cout << "Test the print formats:" << endl;
    cout << d5.printMonthFirst() << endl;
    cout << d5.printDayFirst() << endl;

    return 0;
}