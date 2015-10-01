/* 
 * File:   prob_4_10.cpp
 * Author: Tiffany Pan
 * Created on September 8, 2015, 3:44 PM
 * Purpose: determine days in a given month and whether the year is a leap or not
 * Homework: Complete problem 4.10
 */

//System Libraries
#include <iostream> //input/output stream Library
#include <cstdlib> //Random Library
#include <iomanip> //format Library

using namespace std; //utilize standard name-space directly

//User Libraries

//Global Constants

//Function Prototypes 

/*
 * Days in a month
 */
int main(int argc, char** argv) {
    int month, year;
    bool leap=false;
    //user must enter month in the range of 1 through 12
    do{
    cout<<"Please enter month in integer form between 1 and 12"<<endl;
    cin>>month;    
    }while(!(month>=1 && month<=12));
    //user enters year
    cout<<"Please enter the year\n";
    cin>>year;
    //if year is divisible by 100 and 400, or divisible by 4, then it is a leap year.
    if ((year%100==0&&year%400==0)|| year%4==0)
        leap=true;
    //number corresponds to month 
    if (month==1||month==3||month==5||month==7||month==8||month==10||month==12)
        cout<<"31 days"<<endl;
    else if (month==4||month==6||month==9||month==11)
        cout<<"30 days"<<endl;
    else if (month==2)
    {
        if(leap)
            cout<<"29 days"<<endl;
        else
            cout<<"28 days"<<endl;
    }    
    return 0;
}

