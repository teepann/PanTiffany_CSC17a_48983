/* 
 * File:   ShiftSupervisor.h
 * Author: Tiffany
 *
 * Created on December 1, 2015, 5:24 PM
 */

#ifndef SHIFTSUPERVISOR_H
#define	SHIFTSUPERVISOR_H

#include "Employee.h"

class ShiftSupervisor : public Employee {
public:
    ShiftSupervisor();
    ShiftSupervisor(const ShiftSupervisor& orig);
    virtual ~ShiftSupervisor();
    void setSalary(float);
    void setBonus(float);
    float getSalary();
    float getBonus();
    
private:
    float salary;
    float bonus;
};

#endif	/* SHIFTSUPERVISOR_H */

