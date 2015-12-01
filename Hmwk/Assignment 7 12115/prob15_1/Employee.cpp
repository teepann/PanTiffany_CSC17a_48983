/* 
 * File:   Employee.cpp
 * Author: Tiffany
 * 
 * Created on December 1, 2015, 11:48 AM
 */

#include "Employee.h"

Employee::Employee() {
    name = "Bob";
    number = 123;
    date = "1/1/2000";
}
Employee::Employee(string n, int num, string d){
    name = n;
    number = num;
    date = d;
}
Employee::Employee(const Employee& orig) {
}

Employee::~Employee() {
}

void Employee::setName(string n){
    name = n;
}
void Employee::setNumber(int num){
    number = num;
}
void Employee::setDate(string d){
    date = d;
}
string Employee::getName(){
    return name;
}
int Employee::getNumber(){
    return number;
}
string Employee::getDate(){
    return date;
}