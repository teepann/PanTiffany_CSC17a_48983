/*
* File: main.cpp
* Author: Tiffany Pan
* Date: September 13, 2015
* Assignment: Problem 7.6 Rain or Shine
* Directions: An amateur meteorologist wants to keep track of weather conditions during 
* the past year’s three-month summer season and has designated each day as either rainy 
* (‘R’), cloudy (‘C’), or sunny (‘S’). Write a program that stores this information 
* in a 3 × 30 array of characters, where the row indicates the month (0 = June, 1 = July, 
* 2 = August) and the column indicates the day of the month. Note that data are not being 
* collected for the 31st of any month. The program should begin by reading the weather 
* data in from a file. Then it should create a report that displays, for each month and 
* for the whole three-month period, how many days were rainy, how many were cloudy, and 
* how many were sunny. It should also report which of the three months had the largest 
* number of rainy days. Data for the program can be found in the  RainOrShine.txt file.
*/

//System Libraries
#include <iostream>
#include <fstream> //for reading files
#include <string>
using namespace std;

//User Libraries

//Global Constants
const int NUM_MONTHS = 3;
const int NUM_DAYS = 30;
const string name[NUM_MONTHS] = { "June", "July", "August" };

//Function Prototypes
void readFile(char[][NUM_DAYS]);

//Execution begins here
int main(int argc, char** argv) {
	//Variable declarations
	char forecast[NUM_MONTHS][NUM_DAYS]; //3x30 array of character
	int rainy, cloudy, sunny,   //number of "" days during a certain month
		rainyTotal = 0, cloudyTotal = 0, sunnyTotal = 0,  //number "" days during the 3 months
		mostRainyMonth, amountOfRain = -1; //index of rainiest month and number of rainy days

	//call function to read in weather data
	readFile(forecast);

	//print report by totaling the number of rainy, cloudy, and sunny days
	for (int month = 0; month<NUM_MONTHS; month++) {
		rainy = 0; cloudy = 0; sunny = 0;
		for (int day = 0; day<NUM_DAYS; day++) {
			if (forecast[month][day] == 'R')
				rainy++;
			else if (forecast[month][day] == 'C')
				cloudy++;
			else
				sunny++;
		}
		//add monthly totals to grand totals
		rainyTotal += rainy;
		cloudyTotal += cloudy;
		sunnyTotal += sunny;

		//check for rainiest month
		if (rainy > amountOfRain) {
			amountOfRain = rainy;
			mostRainyMonth = month;
		}

		//display the month's results
		cout << name[month] << " " << rainy << " rainy days, " << cloudy << " cloudy days, " << sunny << " sunny days " << endl;
	}
	//display summary data
	cout << "Totals: " << rainyTotal << " total days of rain, " << cloudyTotal << " total cloudy days, " << sunnyTotal << " total sunny days" << endl;
	cout << "Month with most rainy days: " << name[mostRainyMonth] << endl;

	system("pause");
	return 0;
}

/*
* Definition of function readFile
* Reads data from RainOrShine.txt into forecast
*/
void readFile(char forecast[][NUM_DAYS])
{
	ifstream weatherData;
	//open RainOrShine.txt and import into forecast
	weatherData.open("RainOrShine.txt");
	for (int month = 0; month<NUM_MONTHS; month++){
		for (int day = 0; day<NUM_DAYS; day++)
			weatherData >> forecast[month][day];
	}
	weatherData.close();
}
