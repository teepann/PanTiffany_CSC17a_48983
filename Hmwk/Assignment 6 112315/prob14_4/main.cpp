/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: November 5, 2015
 * Assignment: Problem 14.4 NumDays Class
 * Directions: Design a class called NumDays . The class’s purpose is to store a value that represents a
number of work hours and convert it to a number of days. For example, 8 hours would
be converted to 1 day, 12 hours would be converted to 1.5 days, and 18 hours would
be converted to 2.25 days. The class should have a constructor that accepts a number
of hours, as well as member functions for storing and retrieving the hours and days.
The class should also have the following overloaded operators: +, -, ++, --
 */

//System Libraries
#include <iostream>
#include "NumDays.h"
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    NumDays n1;
    NumDays n2(12);
    n1 = n2++;
    n1 = n2--;
    n1 = --n2;
    cout << n1.getNumDays();
    return 0;
}
