/* 
 * File:   NumDays.cpp
 * Author: Tiffany
 * 
 * Created on November 22, 2015, 6:10 PM
 */

#include "NumDays.h"
#include "stdlib.h"

NumDays::NumDays(){
    numHours = 0;
    numDays = 0.0;
}
NumDays::NumDays(int hours) {
    numHours = hours;
    numDays = hours/8.0;
}

NumDays::NumDays(const NumDays& orig) {
}

NumDays::~NumDays() {
}

int NumDays::getNumHours(){
    return numHours;
}

void NumDays::setNumHours(int hours){
    numHours = hours;
    setNumDays(hours/8.0);
}

float NumDays::getNumDays(){
    return numDays;
}

void NumDays::setNumDays(float days){
    numDays = days;
}

/* + Addition operator. When two NumDays objects are added together, the overloaded
 * + operator should return the sum of the two objects’ hours members.
 */
NumDays NumDays::operator+(const NumDays& n)
{
    NumDays temp;
    temp.numHours = numHours + n.numHours;
    temp.numDays = temp.numHours/8.0;
    return temp; 
}

/* − Subtraction operator. When one NumDays object is subtracted from another,
 * the overloaded − operator should return the difference of the two objects’ hours members.
 */
NumDays NumDays::operator-(const NumDays& n)
{
    NumDays temp;
    temp.numHours = abs(numHours - n.numHours);
    temp.numDays = temp.numHours/8.0;
    return temp;
}

/*++ Prefix and postfix increment operators. These operators should increment the
number of hours stored in the object. When incremented, the number of days
should be automatically recalculated.
 */
NumDays& NumDays::operator++() //prefix
{
    ++numHours;
    numDays = numHours/8.0;
    return *this;
}

NumDays NumDays::operator++(int) //postfix
{
    NumDays temp(numHours);
    numHours++;
    temp.setNumDays(numHours/8.0);
    return temp;
}
/*−− Prefix and postfix decrement operators. These operators should decrement the
number of hours stored in the object. When decremented, the number of days
should be automatically recalculated.
 */
NumDays& NumDays::operator--(){ //prefix
    --numHours;
    numDays = numHours/8.0;
    return *this;
}

NumDays NumDays::operator--(int){ //postfix
    NumDays temp(numHours);
    numHours--;
    temp.setNumDays(numHours/8.0);
    return temp;
}