/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: November 10, 2015
 * Assignment: Problem 13.7 MilTime Class
 * Directions: Create MilTime class that inherits from Time.h
 */

//System Libraries
#include <iostream>
#include "MilTime.h"
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Variable declarations
    int m, s;
    cout << "Please enter a time in military format: ";
    cin >> m;
    cout << "Please enter a the seconds: ";
    cin >> s;
    MilTime test;
    test.setTime(m, s);
    test.getStandHr();
    return 0;
}
