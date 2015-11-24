/* 
 * File:   DayOfYear.h
 * Author: Tiffany
 *
 * Created on November 23, 2015, 8:33 PM
 */

#ifndef DAYOFYEAR_H
#define	DAYOFYEAR_H

#include <string>
using namespace std;

class DayOfYear
{
public:
    DayOfYear();
    DayOfYear(string, int);
    virtual ~DayOfYear();
    void setNumDays(int);
    int getNumDays();
    void print();
    static const string monthName[];
    static const int monthDays[];
    
    DayOfYear& operator++(); //prefix
    DayOfYear& operator--();
    DayOfYear operator++(int); //postfix
    DayOfYear operator--(int);
private:
    int day;
    string month;
    int numDays;
};

#endif	/* DAYOFYEAR_H */

