/* 
 * File:   DayOfYear.cpp
 * Author: Tiffany
 * 
 * Created on November 23, 2015, 8:33 PM
 */

#include "DayOfYear.h"
#include <iostream>
#include <stdlib.h>

const int DayOfYear::monthDays[] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
const string DayOfYear::monthName[] = { "January", "February", "March", "April", "May", 
                                      "June", "July", "August", "September", "October", "November", "December" };
DayOfYear::DayOfYear(string m, int d){
    month = m;
    day = d;
    for (int i=0; i<12; i++){
        if (m==monthName[0]){
            numDays = 0;
            break;
        }            
        if (m==monthName[i])
            numDays = monthDays[i-1];
    }
    if (d<1 || d>31)
        exit(0);
    numDays += d;    
}
DayOfYear::DayOfYear(){
    month = "January";
    day = 1;
    numDays =1;
}

DayOfYear::~DayOfYear() {
}

void DayOfYear::setNumDays(int d)
{
    numDays = d;
}

int DayOfYear::getNumDays()
{
    return numDays;
}

void DayOfYear::print()
{   
    int m = 0;
    while (monthDays[m] < numDays)
        m = (m + 1) % 12;
    if (numDays < 32)
        cout << monthName[m] << " " << numDays << endl; 
    else 
        cout << monthName[m] << " " << numDays - monthDays[m - 1] << endl;
}

DayOfYear& DayOfYear::operator ++(){
    ++numDays;
    if (numDays>365)
        numDays = 1;
    return *this;
}

DayOfYear DayOfYear::operator ++(int){
    DayOfYear temp;
    temp.numDays++;
    if (temp.numDays>365)
        temp.numDays = 1;
    return temp;
}

DayOfYear& DayOfYear::operator --(){
    --numDays;
    if (numDays==0)
        numDays = 365;
    return *this;
}

DayOfYear DayOfYear::operator --(int){
    DayOfYear temp;
    temp.numDays--;
    if (temp.numDays==0)
        temp.numDays = 365;
    return temp;
}
