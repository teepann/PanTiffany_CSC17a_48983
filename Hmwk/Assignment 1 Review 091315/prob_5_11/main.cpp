/*
* File: main.cpp
* Author: Tiffany Pan
* Date: September 13, 2015
* Assignment: Problem 5.11 Population
* Directions: Write a program that will predict the size of a population of organisms. 
* The program should ask the user for the starting number of organisms, their average 
* daily popula-tion increase (as a percentage), and the number of days they will multiply. 
* A loop should display the size of the population for each day.
* Input Validation: Do not accept a number less than 2 for the starting size of the 
* population. Do not accept a negative number for average daily population increase. 
* Do not accept a number less than 1 for the number of days they will multiply.
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
	int numOrganisms, numDays, population; 
	float avgInc; //average increase as percentage

	//prompt user for initial population
	//does not accept a number less than 2
	do{
		cout << "How many organisms to start?" << endl;
		cin >> numOrganisms;
	} while (numOrganisms<2);
	population = numOrganisms;

	//prompt user for average daily population increase in percentage
	//checks that it is non negative value
	do{
		cout << "Average daily population increase percentage?" << endl;
		cin >> avgInc;
	} while (avgInc<0);

	//prompts user for number of days they will multiply that is greater than 1
	do{
		cout << "How many days will they multiply?" << endl;
		cin >> numDays;
	} while (numDays<1);

	//loop that displays the day and the size of the population for each day
	for (int i = 0; i <= numDays; i++)
	{
		cout << "Day " << i << ": " << population << endl;
		population += population*avgInc / 100;
	}

	system("pause");
	return 0;
}
