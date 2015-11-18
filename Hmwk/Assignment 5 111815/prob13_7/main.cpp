/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: November 10, 2015
 * Assignment: Problem 13.7
 * Directions: Design a TestScores class that has member variables to hold three test scores. The
class should have a constructor, accessor, and mutator functions for the test score fields
and a member function that returns the average of the test scores. Demonstrate the 
class by writing a separate program that creates an instance of the class. The program
should ask the user to enter three test scores, which are stored in the TestScores
object. Then the program should display the average of the scores, as reported by the
TestScores object.
 */

//System Libraries
#include <iostream>
#include "TestScores.h"
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    int test1, test2, test3;
    cout << "Score for test 1: ";
    cin >> test1;
    cout << "Score for test 2: ";
    cin >> test2;
    cout << "Score for test 3: ";
    cin >> test3;
    TestScores *test = new TestScores(test1, test2, test3);
    cout << "Average score: " << test->findAvgScore() << endl;
    return 0;
}
