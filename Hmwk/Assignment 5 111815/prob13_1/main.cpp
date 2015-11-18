/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: November 5, 2015
 * Assignment: Problem 13.1 Date
 * Directions: Design a class called Date. The class should store a date 
 * in three integers: month, day, and year. There should be member functions
 * to print the date in the following forms: 12/25/2014, December 25, 2014,
 * 25 December 2014. Demonstrate the class by writing a complete program 
 * implementing it. Input Validation: Do not accept values for the day greater
 * than 31 or less than 1. Do not accept values for the month greater than
 * 12 or less than 1.
 */

//System Libraries
#include <iostream>

#include "Date.h"
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Variable declarations
    Date *date = new Date();
    date->setDay();
    date->setMonth();
    date->setYear();
    date->printDayFirstForm();
    date->printNumberForm();
    date->printWrittenForm();
    return 0;
}
