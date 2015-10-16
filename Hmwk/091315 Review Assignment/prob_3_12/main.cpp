/*
* File: main.cpp
* Author: Tiffany Pan
* Date: September 13, 2015
* Assignment: Problem 3.12 Celsius to Fahrenheit
* Directions: Write a program that converts Clsius temperatures to Fahrenheit temperatures. 
* The formula is F = 9/5C + 32
* F is the Fahrenheit temperature, and C is the Celsius temperature
*/

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
	//Variable declarations
	float celsius;
	float fahrenheit;

	//prompt user for a celcius temperature
	cout << "Enter temperature in Celsius\n";
	cin >> celsius;

	//convert celsius to fahrenheit with the given formula
	fahrenheit = (9.0 / 5) * celsius + 32.0;

	//return converted temperature in celsius
	cout << celsius << " degrees Celsius is " << fahrenheit << " degrees Fahrenheit." << endl;

	system("Pause");
	return 0;
}
