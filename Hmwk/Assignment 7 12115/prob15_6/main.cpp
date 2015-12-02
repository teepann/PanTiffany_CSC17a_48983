/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: November 10, 2015
 * Assignment: Problem 15.6 Essay Class
 * Directions: Design Essay class derived from GradedActivity. 
 * Essay class should determine grade a student receives based on
 * grammar, spelling, correct length, content.
 */

//System Libraries
#include <iostream>
#include "Essay.h"
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Variable declarations
    Essay test;
    test.determineScore();
    cout << test.getLetterGrade();
    return 0;
}
