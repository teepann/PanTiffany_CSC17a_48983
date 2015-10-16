/*
* File: main.cpp
* Author: Tiffany Pan
* Date: September 13, 2015
* Assignment: Problem 6.7 Celsius Temperature Table
* Directions: The formula for converting a temperature from Fahrenheit to Celsius is C = 5/9(F-32)
* where  F is the Fahrenheit temperature and  C is the Celsius temperature. Write a func-tion named  
* celsius that accepts a Fahrenheit temperature as an argument. The func-tion should return the 
* temperature, converted to Celsius. Demonstrate the function by calling it in a loop that displays 
* a table of the Fahrenheit temperatures 0 through 20 and their Celsius equivalents.
*/

//System Libraries
#include <iostream>
#include <iomanip> //formatting
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
float toCelsius(float fahrenheit);

//Execution begins here
int main(int argc, char** argv) {
	//loop that displays a table of the Fahrenheit temperatures 0 through 20 and their Celsius equivalents
	for (int i = 0; i<21; i++) {
		cout << fixed << setprecision(2) << showpoint;
		cout << i << " Celsius is " << toCelsius(i) << " Fahrenheit" << endl;		
	}
	system("pause");
	return 0;
}

/*
* Definition of function toCelsius
* convert a temperature from Fahrenheit to Celsius based on given formula
*/
float toCelsius(float f)
{
	float c;
	c = (5.0 / 9)*(f - 32.0);
	return c;
}
