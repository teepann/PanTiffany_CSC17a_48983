/* 
 * File:   DayOfYear.cpp
 * Author: Tiffany
 * 
 * Created on November 23, 2015, 8:33 PM
 */

#include "DayOfYear.h"
#include <string>
#include <iostream>

using namespace std;

const int DayOfYear::monthDays[] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
const string DayOfYear::monthName[] = { "January", "February", "March", "April", "May", 
                                      "June", "July", "August", "September", "October", "November", "December" };
DayOfYear::DayOfYear(){
    do {
        cout << "Please enter a date: ";
        cin >> day;
    } while (day<1 && day >365);
}

DayOfYear::DayOfYear(const DayOfYear& orig) {
}

DayOfYear::~DayOfYear() {
}

void DayOfYear::setDay(int d)
{
    day = d;
}

int DayOfYear::getDay()
{
    return day;
}

void DayOfYear::print()
{   
    int month = 0;
    while (monthDays[month] < day)
        month = (month + 1) % 12;
    if (day < 32)
        cout << monthName[month] << " " << day << endl; 
    else 
        cout << monthName[month] << " " << day - monthDays[month - 1] << endl;
}
