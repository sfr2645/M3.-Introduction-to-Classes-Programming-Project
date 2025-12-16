// M3. Introduction to Classes Programming Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#ifndef DATE_H
#define DATE_H

#include <string>

class Date
{
private:
    int month;
    int day;
    int year;

    // Helper validation function
    bool isValidDate(int m, int d, int y) const;

public:
    // Constructor with default values
    Date(int m = 1, int d = 1, int y = 1900);

    // Mutator
    void setDate(int m, int d, int y);

    // Accessors (inline)
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }

    // Leap year functions
    bool isLeapYear() const;
    bool isLeapYear(int y) const;

    // Last day of month functions
    int lastDay() const;
    int lastDay(int m, int y) const;

    // Print functions
    std::string printNumeric() const;        // 12/25/2021
    std::string printMonthFirst() const;     // December 25, 2021
    std::string printDayFirst() const;       // 25 December 2021
};

#endif