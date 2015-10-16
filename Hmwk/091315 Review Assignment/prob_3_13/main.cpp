/*
* File: main.cpp
* Author: Tiffany Pan
* Date: September 13, 2015
* Assignment: Problem 3.13 Currency
* Directions: Write a program that will convert U.S. dollar amounts to Japanese yen and to euros,
* storing the conversion factors in the constants YEN_PER_DOLLAR and EUROS_PER_DOLLAR. To get the 
* most up-to-date exchange rates, search the Internet using the term "currency exchange rate". If 
* you cannot find the most recent exchange rates, use the following: 1 Dollar = 98.93 Yen;
* 1 Dollar = 0.74 Euros. Format your currency amounts in fixed-point notation, with two decimal 
* places of precision, and be sure the decimal point is always displayed.
*/

//System Libraries
#include <iostream>
#include <iomanip> //for setprecision()
using namespace std;

//User Libraries

//Global Constants
float YEN_PER_DOLLAR = 98.93;
float EUROS_PER_DOLLAR = 0.74;

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
	//Variable declarations
	float yen, euros, dollar; //amount of moeny with respective currency values

	//prompt user to enter a US dollar amount
	cout << "Please eneter US dollar amount\n";
	cin >> dollar; 

	//formula to convert US dollars into Yen
	yen = dollar*YEN_PER_DOLLAR;
	//formula to convert US dollars into Euros
	euros = dollar*EUROS_PER_DOLLAR;

	//format currency amounts to have two decimal places
	cout << fixed << setprecision(2) << showpoint;
	cout << dollar << " dollars is " << yen << " yen and " << euros << " euros." << endl;

	system("pause");
	return 0;
}
