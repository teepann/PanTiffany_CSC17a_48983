/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: October 1, 2015
 * Assignment: Problem 11.3 Corporate Sales Data
 * Directions: Write a program that uses a structure too store the following data on a company division:
 * Division Name (east, west, north, south)
 * first-quarter sales
 * second-quarter sales
 * third-quarter sales
 * fourth-quarter sales
 * total annual sales
 * average quarterly sales
 * the program should use 4 variables of this structure. each variable should 
 * represent one of the following corporate divisions; East, West, North, and 
 * South. the user should be asked for the 4 quarters' sales figures for each 
 * division. Each division's total and average sales should be calculated and stored
 * in the appropriate member of each structure variable. THese figures should
 * then be displayed on the screen.
 * input validation: no negative sales figures
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries

//structure of a company division
const int NUM_QUARTERS = 4;
struct CompanyDivision{
    string division; //division name
    float qSales[NUM_QUARTERS]; //array of 4 quarter sales
    float totalAnnual; //total annual sales
    float averageQSales; //average quarterly sales
};
//Global Constants

//Function Prototypes
void showSales(CompanyDivision *cd);
void input (CompanyDivision* cd);

//Execution begins here
int main(int argc, char** argv) {
   //Variable declarations
    //four company divisions
    CompanyDivision east, west, north, south;
    //set company division names
    east.division = "East";
    west.division = "West";
    north.division = "North";
    //south.division = "South";
    
    //input values for each division
    input(&east);
    input(&west);
    input(&north);
    //input(&south);    
    
    //display total and average sales
    showSales(&east);
    showSales(&west);
    showSales(&north);
    //showSales(&south);
    
   return 0;
}

/* 
 * Definition of function input
 * Parameter: pointer to CompanyDivision
 * prompts user to enter each quarter sales
 * calculates total and average sales
 */
void input (CompanyDivision* cd){
    //displays division name
    cout << "Input sales for division " << cd->division << ":\n";
    
    //asks for each quarter's sales
    //meanwhile also getting a running total of sales
    for(int i = 0; i<NUM_QUARTERS; i++){
        //input validation: no negatives sales!
        do {
            cout << "Enter Quarter " << i + 1 << " sales:" << endl;
            cin >> cd->qSales[i];
            if (cd->qSales[i] < 0)
                cout << "please enter a positive number!";
        }while(cd->qSales[i] < 0);
        //running total of current company division's total sales
        cd->totalAnnual += cd->qSales[i];
    }
    //calculates average of each quarter sales
    cd->averageQSales = cd->totalAnnual/4;
}

/* 
 * Definition of function showSales
 * Parameter: pointer to CompanyDivision
 * outputs total annual sales and average quarterly sales
 */
void showSales(CompanyDivision *cd){
    cout << endl << "-------------------------\n";
    cout << fixed << showpoint << setprecision(2);
    cout << "Company Division: " << cd->division << endl;
    cout << "Total annual sales: $" << cd->totalAnnual << endl;
    cout << "Average quarterly sales: $ " << cd->averageQSales << endl;
    cout << "-------------------------" << endl;
}