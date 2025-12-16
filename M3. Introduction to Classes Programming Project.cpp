// M3. Introduction to Classes Programming Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program will print the date in three seperate forms.

#include "NumberArray.h"
#include <iostream>

using namespace std;

// Initialize static constant
const double NumberArray::DEFAULT_VALUE = 10000.0;

// Constructor
NumberArray::NumberArray(int s)
{
    if (s <= 0)
        size = MAX_SIZE;
    else
        size = s;

    numbers = new double[size];

    // Initialize array to 0
    for (int i = 0; i < size; i++)
        numbers[i] = 0.0;
}

// Destructor
NumberArray::~NumberArray()
{
    delete[] numbers;
    cout << "The destructor is running" << endl;
}

// Store a number
void NumberArray::setNumber(int index, double value)
{
    if (index < 0 || index >= size)
    {
        cout << "The index is out of the bounds of the array, number not stored" << endl;
        return;
    }

    numbers[index] = value;
}

// Retrieve a number
double NumberArray::getNumber(int index) const
{
    if (index < 0 || index >= size)
    {
        cout << "The Index is out of the bounds of the array, returning default" << endl;
        return DEFAULT_VALUE;
    }

    return numbers[index];
}

// Minimum value
double NumberArray::getMin() const
{
    double min = numbers[0];
    for (int i = 1; i < size; i++)
    {
        if (numbers[i] < min)
            min = numbers[i];
    }
    return min;
}

// Maximum value
double NumberArray::getMax() const
{
    double max = numbers[0];
    for (int i = 1; i < size; i++)
    {
        if (numbers[i] > max)
            max = numbers[i];
    }
    return max;
}

// Average value
double NumberArray::getAverage() const
{
    double sum = 0.0;
    for (int i = 0; i < size; i++)
        sum += numbers[i];

    return sum / size;
}

// Print array
void NumberArray::print() const
{
    for (int i = 0; i < size; i++)
        cout << numbers[i] << " ";
    cout << endl;
}
