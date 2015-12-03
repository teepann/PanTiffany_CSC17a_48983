/* 
 * File:   ShiftSupervisor.cpp
 * Author: Tiffany
 * 
 * Created on December 2, 2015, 5:24 PM
 */

#include "ShiftSupervisor.h"

ShiftSupervisor::ShiftSupervisor() {
    salary = 0.0;
    bonus = 0.0;
}

ShiftSupervisor::ShiftSupervisor(const ShiftSupervisor& orig) {
}

ShiftSupervisor::~ShiftSupervisor() {
}

void ShiftSupervisor::setSalary(float s)
{
    salary = s;

}
void ShiftSupervisor::setBonus(float b)
{
    bonus = b;
}

float ShiftSupervisor::getSalary()
{
    return salary;
}
float ShiftSupervisor::getBonus()
{
    return bonus;
}




