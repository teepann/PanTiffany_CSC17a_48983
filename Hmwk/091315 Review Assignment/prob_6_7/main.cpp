/* 
 * File:   prob_6_7.cpp
 * Author: Tiffany Pan
 * Created on September 8, 2015, 3:44 PM
 * Purpose: Convert Fahrenheit to Celsius
 * Homework: Complete problem 6.7
 */

//System Libraries
#include <iostream> //input/output stream Library
#include <iomanip> //format Library
using namespace std; //utilize standard name-space directly

//User Libraries

//Global Constants

//Function Prototypes 
float celsius(float fahrenheit);
/*
 * Celsius Temperature Table  
 */
int main(int argc, char** argv) {
    //loop that displays a table of the Fahrenheit temperatures 0 through 20 and their Celsius equivalents
    for(int i=0;i<21;i++)
    {
        cout<<i<<" Celsius is "<<celsius(i)<<" Fahrenheit"<<endl;
        cout<<fixed<<setprecision(2)<<showpoint;
    }
    return 0;
}

//function that accepts a Fahrenheit temperature as an argument
float celsius(float fahrenheit)
{
    float c;
    //formula for converting a temperature from Fahrenheit to Celsius is C=5/9(F-32)
    c=(5.0/9.0)*(fahrenheit-32.0);
    return c;
}

