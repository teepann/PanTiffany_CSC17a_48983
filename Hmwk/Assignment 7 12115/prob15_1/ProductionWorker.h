/* 
 * File:   ProductionWorker.h
 * Author: Tiffany
 *
 * Created on December 1, 2015, 12:00 PM
 */

#ifndef PRODUCTIONWORKER_H
#define	PRODUCTIONWORKER_H
#include "Employee.h"

class ProductionWorker: public Employee {
public:
    ProductionWorker();
    ProductionWorker(int, float);
    ProductionWorker(const ProductionWorker& orig);
    virtual ~ProductionWorker();
    void setShift(int);
    void setRate(float);
    int getShift();
    float getRate();
private:
    int shift;
    float rate;
};

#endif	/* PRODUCTIONWORKER_H */

