/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: November 10, 2015
 * Assignment: Problem 13.8 Circle Class
 * Directions: Write a program that demonstrates the Circle class by asking the user for the circle’s
radius, creating a Circle object, and then reporting the circle’s area, diameter, and
circumference.
 */

//System Libraries
#include <iostream>
#include "Circle.h"
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    cout << "Enter the radius: ";
    float radius;
    cin >> radius;
    Circle *test = new Circle(radius);
    cout << "Area: " << test->getArea() << endl;
    cout << "Diameter: " << test->getDiameter() << endl;
    cout << "Circumference: " << test->getCircumference() << endl;
    return 0;
}
