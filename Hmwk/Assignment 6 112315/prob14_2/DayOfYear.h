/* 
 * File:   DayOfYear.h
 * Author: Tiffany
 *
 * Created on November 23, 2015, 8:33 PM
 */

#ifndef DAYOFYEAR_H
#define	DAYOFYEAR_H

#include <string>

class DayOfYear
{
public:
    DayOfYear();
    DayOfYear(const DayOfYear& orig);
    virtual ~DayOfYear();
    void setDay(int);
    int getDay();
    void print();
    static const std::string monthName[];
    static const int monthDays[];
private:
    int day;
};

#endif	/* DAYOFYEAR_H */

