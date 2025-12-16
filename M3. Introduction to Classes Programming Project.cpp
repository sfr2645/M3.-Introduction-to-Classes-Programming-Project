// M3. Introduction to Classes Programming Project.cpp
//This is the class called date for the Number Array Class program 

#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

class NumberArray
{
private:
    int size;          // size of the array
    double* numbers;   // pointer to dynamic array

public:
    // Named constants
    static const int MAX_SIZE = 10;
    static const double DEFAULT_VALUE;

    // Constructor & Destructor
    NumberArray(int size = MAX_SIZE);
    ~NumberArray();

    // Mutator
    void setNumber(int index, double value);

    // Accessor
    double getNumber(int index) const;

    // Operations
    double getMin() const;
    double getMax() const;
    double getAverage() const;

    // Print function (for testing)
    void print() const;

    // Accessor for size (inline)
    int getSize() const { return size; }
};

#endif
