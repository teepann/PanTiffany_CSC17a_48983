/* 
 * File:   MilTime.h
 * Author: Tiffany
 *
 * Created on December 1, 2015, 11:17 PM
 */

#ifndef MILTIME_H
#define	MILTIME_H
#include "Time.h"
#include <string>
using namespace std;

class MilTime : public Time {
public:
    MilTime();
    MilTime(const MilTime& orig);
    virtual ~MilTime();
    void setTime(int, int);
    void getStandHr();
    int getHour() { return milHours; }
    void setHour(int h) { milHours = h; }
    int getMilSeconds() { return milSeconds; }
    void setMilSeconds(int s) { milSeconds = s; }
private:
    int milHours;
    int milSeconds;
};

#endif	/* MILTIME_H */

