/* 
 * File:   MilTime.cpp
 * Author: Tiffany
 * 
 * Created on December 1, 2015, 11:17 PM
 */

#include "MilTime.h"
#include <iostream>
using namespace std; 

MilTime::MilTime() {
    milHours = 0;
    milSeconds = 0;
}

MilTime::MilTime(const MilTime& orig) {
}

MilTime::~MilTime() {
}

void MilTime::setTime(int mh, int ms) {
    milHours = mh;
    milSeconds = ms;
    hour = mh % 100;
    min = mh / 100;
    sec = ms;
}

void MilTime::getStandHr() {
    
    cout << (milHours/100)%12 << ":" << milHours % 100 << ":" << milSeconds;
}


