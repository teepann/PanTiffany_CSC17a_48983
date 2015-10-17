/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: October 1, 2015
 * Assignment: Problem 12.11
 * Directions: write a program that uses a structure to store the following data
 * on a company division: 
 * Division Name: East, West, North, South
 * Quarter: 1, 2, 3, or 4
 * Quarterly Sales
 * the user should be asked for the 4 quarters' sales figures for the East,
 * West, North, and South divisions. the data for each division should be
 * written to a file
 * input validation: no negative sales figures.
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Division Names struct
typedef struct DIVISION {
    const static int NUM_DIVISION = 4;
    const static char* NAMES[NUM_DIVISION];
    char divName[5];
} Division;
const char* Division::NAMES[] = {"East", "West", "North", "South"};

//Quarter struct
typedef struct QUARTER {
    const static int NUM_QUARTER = 4;
    const static int QUARTERS[NUM_QUARTER];
    int quarter;
} Quarter;
const int Quarter::QUARTERS[] = {1, 2, 3, 4};

//Sales Data Structure
typedef struct SALESDATA{
    Division div;
    Quarter quart;
    float quartSale;
} SalesData;

//Execution begins here
int main(int argc, char** argv) {
   //Variable declarations
    const string FILE_NAME = "Sales.dat";

    fstream salesFile(FILE_NAME.c_str(), ios::out | ios::binary);

    SalesData currentSales;

    if (salesFile) {

        for (int i = 0; i < Division::NUM_DIVISION; i++) {

            strcpy(currentSales.div.divName, Division::NAMES[i]);

            for (int j = 0; j < Quarter::NUM_QUARTER; j++) {

                currentSales.quart.quarter = Quarter::QUARTERS[j];

                cout << "Please enter the quarterly sales for division "
                        << currentSales.div.divName
                        << " in quarter " << currentSales.quart.quarter << ": ";
                cin >> currentSales.quartSale;

                if (currentSales.quartSale < 0) {
                    currentSales.quartSale = 0;
                }

                salesFile.write(reinterpret_cast<char*> (&currentSales), sizeof (currentSales));

            }
        }

        salesFile.close();
    } else {
        cerr << "File I/O error!";
    }

    /*Testing*/
    fstream testFile(FILE_NAME.c_str(), ios::in | ios::binary);

    SalesData test;

    if (testFile) {

        while (testFile.read(reinterpret_cast<char*> (&test), sizeof (test))) {
            cout << test.div.divName << " "
                    << test.quart.quarter << " "
                    << test.quartSale << endl;
        }

        testFile.close();
    }
   return 0;
}

/* 
 * Definition of function.
 *
 */
