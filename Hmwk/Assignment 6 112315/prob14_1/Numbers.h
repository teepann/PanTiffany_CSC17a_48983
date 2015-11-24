/* 
 * File:   Numbers.h
 * Author: Tiffany
 *
 * Created on November 23, 2015, 11:41 PM
 */

#ifndef NUMBERS_H
#define	NUMBERS_H
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

class Numbers {
public:
    Numbers();
    Numbers(const Numbers& orig);
    virtual ~Numbers();
    void setNum(int);
    int getNum();
    int calcVal();// determines what numbers to choose from
    void printRes(int); // determines hundred v thousand
 
private:
    unsigned int number;
};

#endif	/* NUMBERS_H */

