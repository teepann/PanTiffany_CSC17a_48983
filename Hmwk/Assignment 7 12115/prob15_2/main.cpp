/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: November 10, 2015
 * Assignment: Problem 15.2
 * Directions:
 */

//System Libraries
#include <iostream>
using namespace std;
#include "ProductionWorker.h"
#include "ShiftSupervisor.h"

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    ProductionWorker pwork;
	
    pwork.setName("Tiff");
    pwork.setNumber(123);
    pwork.setDate("12/1/2015");
    pwork.setShift(2);
    pwork.setRate(12.34);
    cout << pwork.getName() << " " << pwork.getNumber() << " " << pwork.getDate() << endl;
    ShiftSupervisor super;
    super.setSalary(50000);
    super.setBonus(1000);
    cout << super.getSalary() + super.getBonus() << endl;

    return 0;
}
