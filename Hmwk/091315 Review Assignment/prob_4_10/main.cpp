/*
* File: main.cpp
* Author: Tiffany Pan
* Date: September 8, 2015
* Assignment: Problem 4.10 Days in a Month
* Directions: Write a program that asks the user to enter the month (letting the user enter an integer
* in the range of 1 through 12) and the year. The program should then display the number of days in that
* month. Use the following criteria to identify leap years:
* 1. Determine whether the year is divisible by 100. If it is, then it is a leap year IFF it is divisible
* by 400. For example, 2000 is a leap year but 2100 is not.
* 2. If the year is not divisible by 100, then it is a leap year IFF it is divisible by 4. For Example,
* 2009 is a leap year, but 2009 is not.
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
	int month, year;
	bool isLeap = false;

	//prompt user to enter month in the range of 1-12
	do{
		cout << "Please enter month in integer form between 1 and 12" << endl;
		cin >> month;
	} while (!(month >= 1 && month <= 12));

	//prompt user to enter year
	cout << "Please enter the year\n";
	cin >> year;

	//if year is divisible by 100 && 400, or divisible by 4, it is leap year
	if ((year % 100 == 0 && year % 400 == 0) || year % 4 == 0)
		isLeap = true;

	//output number of days in the given month
	//number corresponds to month 
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		cout << "31 days" << endl;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		cout << "30 days" << endl;
	else if (month == 2) {
		if (isLeap)
			cout << "29 days" << endl;
		else
			cout << "28 days" << endl;
	}
	system("pause");
	return 0;
}
