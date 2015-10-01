/* 
 * File:   prob_7_6.cpp
 * Author: Tiffany Pan
 * Created on September 8, 2015, 3:44 PM
 * Purpose: Rainy, cloudy, or sunny days of June, July, and August
 * Homework: Complete problem 7.6
 */

//System Libraries
#include <iostream> //input/output stream Library
#include <iomanip> //format Library
#include <fstream> //input/output file library
#include <string>
using namespace std; //utilize standard name-space directly

//User Libraries

//Global Constants
   const int NUM_MONTHS = 3;
   const int NUM_DAYS = 30;
   const string name[NUM_MONTHS] = {"June","July","August"};
//Function Prototypes 
   void readFile(char[][NUM_DAYS]);
/*
 * Store weather conditions in a 3x30 array of characters
 * Begin by reading the weather data in from RainOrShine.txt
 * Create a report that displays, for each month and for the the whole 3 months, how many R,C, and S's
 * Also report which of the three months had largest number of rainy days
 * R=rainy; C=cloudy; S=sunny
 * 0=June; 1=July; 2=August
 */
int main(int argc, char** argv) {
    char forecast[NUM_MONTHS][NUM_DAYS];
    int rainy, cloudy, sunny,   //number of "" days during a certain month
        rainyTotal=0, cloudyTotal=0, sunnyTotal=0,  //number "" days during the 3 months
        mostRainyMonth, amountOfRain = -1; //index of rainiest month and number of rainy days
    
    //call function to read in weather data
    readFile(forecast);
    
    //print report by totaling the number of rainy, cloudy, and sunny days
    for(int month=0; month<NUM_MONTHS; month++) {
        rainy=0; cloudy=0; sunny=0;
        for(int day=0; day<NUM_DAYS; day++) {
            if(forecast[month][day] == 'R')
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
        if(rainy>mostRainyMonth) {
            amountOfRain = rainy;
            amountOfRain = month;
        }
        //display the month's results
        cout<< name[month] << " " << rainy << " rainy days, " << cloudy << " cloudy days, " << sunny << " sunny days "<<endl;
    }
    //display summary data
    cout << "Totals: " << rainyTotal << " total days of rain, " << cloudyTotal << " total cloudy days, " << sunnyTotal <<" total sunny days" <<endl;
    cout << "Month with most rainy days: " <<name[mostRainyMonth]<<endl;
    
    return 0;
}

void readFile(char forecast[][NUM_DAYS])
{
    ifstream weatherData;
    //open RainOrShine.txt and import into forecast
    weatherData.open("RainOrShine.txt");
    for(int month=0; month<NUM_MONTHS; month++){
        for (int day=0; day<NUM_DAYS; day++)
            weatherData >> forecast[month][day];
    }
    weatherData.close();
}
   