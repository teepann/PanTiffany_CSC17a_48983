/* 
 * File:   Employee.h
 * Author: Tiffany
 *
 * Created on December 1, 2015, 11:48 AM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H
#include <string>
using namespace std;

class Employee {
public:
    Employee();
    Employee(string, int, string);
    Employee(const Employee& orig);
    virtual ~Employee();
    void setName(string);
    void setNumber(int);
    void setDate(string);
    string getName();
    int getNumber();
    string getDate();
private:
protected:
    string name;
    int number;
    string date;
};

#endif	/* EMPLOYEE_H */

