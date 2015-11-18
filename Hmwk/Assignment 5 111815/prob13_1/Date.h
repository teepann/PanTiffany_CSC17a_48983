/* 
 * File:   Date.h
 * Author: Tiffany
 *
 * Created on November 5, 2015, 11:52 AM
 */

#ifndef DATE_H
#define	DATE_H

#include <string>
#include <iostream>
using namespace std;

class Date {
public:
    Date();
    Date(int, int, int);
    Date(const Date& orig);
    virtual ~Date();
    
    //setters and getters
    void setMonth();
    int getMonth() { return month; }
    void setDay();
    int getDay() { return day; }
    void setYear();
    int getYear() { return year; }
    
    void printNumberForm(); //12/25/2015
    void printWrittenForm(); //December 25, 2015
    void printDayFirstForm(); //25 December 2015
    
private:
    static const string monthName[];
    int month;
    int day;
    int year;
};

#endif	/* DATE_H */

