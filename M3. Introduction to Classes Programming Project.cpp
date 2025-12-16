// M3. Introduction to Classes Programming Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Date.h"
#include <iostream>

using namespace std;

// Constructor
Date::Date(int m, int d, int y)
{
    setDate(m, d, y);
}

// Mutator with validation
void Date::setDate(int m, int d, int y)
{
    if (!isValidDate(m, d, y))
    {
        month = 1;
        day = 1;
        year = 1900;
        return;
    }

    month = m;
    day = d;
    year = y;
}

// Validation helper
bool Date::isValidDate(int m, int d, int y) const
{
    if (m < 1 || m > 12)
    {
        cout << "Month invalid" << endl;
        return false;
    }

    if (y <= 0)
        return false;

    int maxDay = lastDay(m, y);

    if (d < 1 || d > maxDay)
    {
        cout << "Day invalid" << endl;
        return false;
    }

    return true;
}

// Leap year (object year)
bool Date::isLeapYear() const
{
    return isLeapYear(year);
}

// Leap year (parameter year)
bool Date::isLeapYear(int y) const
{
    if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
        return true;
    return false;
}

// Last day (object month/year)
int Date::lastDay() const
{
    return lastDay(month, year);
}

// Last day (parameter month/year)
int Date::lastDay(int m, int y) const
{
    switch (m)
    {
    case 1: case 3: case 5: case 7:
    case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return isLeapYear(y) ? 29 : 28;
    default:
        return 0;
    }
}

// Print formats
string Date::printNumeric() const
{
    return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}

string Date::printMonthFirst() const
{
    static string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    return months[month - 1] + " " + to_string(day) + ", " + to_string(year);
}

string Date::printDayFirst() const
{
    static string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    return to_string(day) + " " + months[month - 1] + " " + to_string(year);
}
