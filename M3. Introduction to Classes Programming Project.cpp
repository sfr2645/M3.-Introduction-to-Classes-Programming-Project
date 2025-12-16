// M3. Introduction to Classes Programming Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program will print the date in three seperate forms.

#include <iostream>
using namespace std;
#include <cstdlib>  

class date
{
private:
	int month, day, year;
	string monthNames[13] = { "", "January", "February", "March",
								"April", "May", "June",
								"July", "August", "September",
								"October", "November", "December" };

	int monthDays[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	//constructor - no argument

public:
	date() : month(0), day(0), year(0)
	{
	}
	//constructor - 3 arguments
	date(int m, int d, int y) : month(m), day(d), year(y)
	{
	}

	//format date 1
	void displayForm1()
	{
		cout << month << "/" << day << "/" << year << endl;
	}

	//format date 2
	void displayFormTwo()
	{

		cout << monthNames[month] << " " << day << ", " << year << endl;
	}

	date displayForm2()
	{

		cout << monthNames[month] << " " << day << ", " << year << endl;

		return date();
	}

	//format date 3
	void displayForm3()
	{
		cout << day << " " << monthNames[month] << " " << year << endl;
	}

	void getDate()
	{
		cout << "Enter date : " << endl;
		cout << "day: " << endl;
		cin >> day;
		while (day < 1 || day > 31)
		{
			cout << "enter valid day: " << endl;
			cin >> day;
		}
		cout << "month: " << endl;
		cin >> month;
		while (month < 1 || month > 12)
		{
			cout << "enter valid month: " << endl;
			cin >> month;
		}
		cout << "year: " << endl;
		cin >> year;
	}

	//overload prefix ++ operator
	date operator++() {
		++day;

		if (day > monthDays[month])
		{
			day = day - monthDays[month];
			month++;
		}

		//return modified calling object
		return *this;
	}

	//overload postfix ++ operator
	date operator++(int) {
		day++;

		if (day > monthDays[month])
		{
			day = day - monthDays[month];
			month++;
		}

		//return modified calling object
		return *this;
	}

	//overload prefix -- operator
	date operator--() {
		--day;

		if (day < 1)
		{
			day = monthDays[month];
			month--;
		}

		//return modified calling object
		return *this;
	}

	//overload postfix -- operator
	date operator--(int) {
		day--;

		if (day < 1)
		{
			day = monthDays[month];
			month--;
		}

		//return modified calling object
		return *this;
	}

	date operator << (date d) {
		return d.displayForm2();
	}

	date operator >> (date d)
	{
		cout << "Day: ";
		cin >> day;
		d.day = day;
		if (day < 1 || day > 31)
		{
			throw "Enter a valid day";
			cin >> day;
			d.day = day;
		}

		cout << "Month: ";
		cin >> month;
		d.month = month;
		if (month < 1 || month > 12)
		{
			cout << "enter valid month: " << endl;
			cin >> month;
			d.month = month;
		}

		cout << "Year: ";
		cin >> year;
		d.year = year;

		return d.displayForm2();
	}

	date operator - (const date& right)
	{
		date temp;

		temp.day = day - right.day;
		temp.month = month - right.month;

		cout << "The difference between current date and date 2 is ... " << temp.day << " days" << endl;
		return temp;
	}


};