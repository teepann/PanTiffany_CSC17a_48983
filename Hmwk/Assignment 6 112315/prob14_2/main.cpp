/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: November 5, 2015
 * Assignment: Problem 14.2 Day of the Year
 * Directions: Assuming that a year has 365 days, write a class named DayOfYear that
 * takes an int representing a day of the year and translates it to a string consisting
 * of the month followed by day of the month. For example,
 * Day 2 would be January 2
 * Day 32 would be February 1.
 * Day 365 would be December 31.
 * The constructor for the class should take as parameter an integer representing the day
of the year, and the class should have a member function print() that prints the day
in the month–day format. The class should have an integer member variable to represent
the day and should have static member variables holding string objects that can
be used to assist in the translation from the integer format to the month-day format.
Test your class by inputting various integers representing days and printing out their
representation in the month–day format. class should have a constructor that accepts a nonnegative integer and uses it to
initialize the Numbers object. It should have a member function print() that prints
the English description of the Numbers object. Demonstrate the class by writing a main
program that asks the user to enter a number in the proper range and then prints out
its English description.
 */

//System Libraries
#include <iostream>
#include "DayOfYear.h"
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    DayOfYear *date = new DayOfYear();
    date->print();
    return 0;
}
