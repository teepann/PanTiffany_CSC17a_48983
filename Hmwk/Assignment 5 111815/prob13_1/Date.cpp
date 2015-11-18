/* 
 * File:   Date.cpp
 * Author: Tiffany
 * 
 * Created on November 5, 2015, 11:52 AM
 */

#include "Date.h"
#include <iostream>

const string Date::monthName[12]= {"January", "February", "March", "April",
    "May", "June", "July", "August", "September", "October", "November", "December"};

Date::Date() {
    month = 1;
    day = 1;
    year = 2000;
}

Date::Date(int m, int d, int y){
    month = m;
    day = d;
    year = y;
}

Date::Date(const Date& orig) {
}

Date::~Date() {
}

void Date::setDay(){
    do {
        cout << "Enter day between 1 and 31: " << endl;
        cin >> day;
    } while (day < 1 || day > 31);        
}

void Date::setMonth(){
    do {
        cout << "Enter month between 1 and 12: " << endl;
        cin >> month;
    } while (month < 1 || month > 12);     
}

void Date::setYear(){
    cout << "Enter year: " << endl;
    cin >> year;
}

void Date::printNumberForm(){
    cout << month << "/" << day << "/" << year << endl;
}

void Date::printWrittenForm(){
    cout << monthName[month-1] << " " << day << ", " << year << endl;
}

void Date::printDayFirstForm(){
    cout << day << " " << monthName[month-1] << " " << year << endl;
}

