/* 
 * File:   prob_3_13.cpp
 * Author: Tiffany Pan
 * Created on September 8, 2015, 3:44 PM
 * Purpose: convert US dollar amounts to Japanese yen to euros
 * Homework: Complete problem 3.13
 */

//System Libraries
#include <iostream> //input/output stream Library
#include <iomanip> //format Library
using namespace std; //utilize standard name-space directly

//User Libraries

//Global Constants
float YEN_PER_DOLLAR=98.93;
float EUROS_PER_DOLLAR=0.74;

//Function Prototypes 

/*
 * Currency conversion 
 */
int main(int argc, char** argv) {
    float yen, euros, dollar;
    cout<<"Please enter US dollar amount\n";
    cin>>dollar;
    //formula to convert US dollars into Yen and Euros
    yen=dollar*YEN_PER_DOLLAR;
    euros=dollar*EUROS_PER_DOLLAR;
    cout<<dollar<<" dollars is "<<yen<<" yen and "<<euros<<" euros."<<endl;
    //Format your currency amounts in fixed-point notation, with two decimal places of precision, and be sure the decimal point is always displayed
    cout<<fixed<<setprecision(2)<<showpoint;
    return 0;
}

