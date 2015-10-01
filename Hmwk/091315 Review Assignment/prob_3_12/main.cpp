/* 
 * File:   prob_3_12.cpp
 * Author: Tiffany Pan
 * Created on September 8, 2015, 3:44 PM
 * Purpose: convert Celsius temperatures to Fahrenheit
 * Homework: Complete problem 3.12
 */

//System Libraries
#include <iostream> //input/output stream Library
using namespace std; //utilize standard name-space directly

//User Libraries

//Global Constants

//Function Prototypes 

/*
 * Celsius to Fahrenheit
 */
int main(int argc, char** argv) {
    float celsius;
    float fahrenheit;
    cout<<"Enter temperature in Celsius\n";
    cin>>celsius;
    //formula that converts celsius to fahrenheit is F = 9/5C+32
    fahrenheit= (9.0/5.0)*celsius+32.0; 
    cout<<celsius<<" Celsius in Fahrenheit is "<< fahrenheit<<endl;
    return 0;
}

