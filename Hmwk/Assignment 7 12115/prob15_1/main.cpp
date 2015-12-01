/* 
 * File:   main.cpp
 * Author: Tiffany
 * HW: 15.1 Employee and ProductionWorker Classes
 * Created on December 1, 2015, 11:47 AM
 */

#include <cstdlib>
#include <iostream>
#include "ProductionWorker.h"
#include "Employee.h"

using namespace std;

int main(int argc, char** argv) {
    ProductionWorker test;
    test.setName("Bill");
    test.setNumber(1234);
    test.setDate("12/1/2015");
    test.setShift(2);
    test.setRate(12.56);
    cout << test.getDate();
    return 0;
}

