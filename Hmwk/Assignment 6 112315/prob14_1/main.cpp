/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: November 5, 2015
 * Assignment: Problem 14.1 Numbers Class
 * Directions: Design a class Numbers that can be used to translate the whole dollar
 * amounts in the range 0-9999 into an English description of the number. For example,
 * the number 713 would be translated into the string seven hundred thirteen. The class
 * should have a single integer member variable: int number;
 * and a static array of string objects that specify how to translate key dollar amounts
 * into the desired format. ie, you might use static strings such as:
 * string lessThan20[20] = {"zero", "one",..., "nineteen"};
 * string hundred = "hundred";
 * string thousand = "thousand";
 * The class should have a constructor that accepts a nonnegative integer and uses it to
initialize the Numbers object. It should have a member function print() that prints
the English description of the Numbers object. Demonstrate the class by writing a main
program that asks the user to enter a number in the proper range and then prints out
its English description.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Numbers.h"

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    Numbers n;
    int number = 0;
    int length = 0;
    do {
        cout << "Please a number from 0 to 9999: ";
	cin >> number;
	n.setNum(number);
    } while (number < 0 || number > 9999);
    length = n.calcVal();

    cout << "The number: " << n.getNum() << endl;;
    n.printRes(length);
    cout << endl;

    return 0;
}