/* 
 * File:   NumDays.h
 * Author: Tiffany
 *
 * Created on November 22, 2015, 6:10 PM
 */

#ifndef NUMDAYS_H
#define	NUMDAYS_H

class NumDays {
public:
    NumDays();
    NumDays(int);
    NumDays(const NumDays& orig);
    virtual ~NumDays();
    int getNumHours();
    void setNumHours(int);
    float getNumDays();
    void setNumDays(float);
    
    NumDays operator+(const NumDays& n);
    NumDays operator-(const NumDays& n);
    NumDays& operator++(); //prefix
    NumDays& operator--();
    NumDays operator++(int); //postfix
    NumDays operator--(int);
private:
    int numHours;
    float numDays;
};

#endif	/* NUMDAYS_H */

