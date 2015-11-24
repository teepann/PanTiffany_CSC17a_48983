/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: November 5, 2015
 * Assignment: Problem 14.3 Day of the Year Modification
 * Directions: Modify the DayOfYear class, written in Programming Challenge 2, to add a constructor
that takes two parameters: a string object representing a month and an integer in
the range 0 through 31 representing the day of the month. The constructor should then
initialize the integer member of the class to represent the day specified by the month
and day of month parameters. The constructor should terminate the program with an
appropriate error message if the number entered for a day is outside the range of days
for the month given.
 * ++ prefix and postfix increment operators. These operators should modify the
DayOfYear object so that it represents the next day. If the day is already the end
of the year, the new value of the object will represent the first day of the year.
 * −− prefix and postfix decrement operators . These operators should modify the
DayOfYear object so that it represents the previous day. If the day is already the
first day of the year, the new value of the object will represent the last day of the
year.
 */

//System Libraries
//System Libraries
#include <iostream>
#include "DayOfYear.h"

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    string m;
    int d;
    cout << "Please enter a month: ";
    cin >> m;
    cout << "Please enter a day of the month: ";
    cin >> d;
    DayOfYear date1(m,d);
    DayOfYear date2;
    date2 = date1--;
    date2.print();
    return 0;
}
