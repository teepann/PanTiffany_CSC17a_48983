/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: November  5, 2015
 * Assignment: Problem 13.4 Personal Information Class
 * Directions: Design a class that holds the following personal data: name, address,
 * age, and phone number. Write appropriate accessor and mutator functions.
 * Demonstrate the class by writing a program that creates 3 instances of it. 
 * One instance should hold your info, and the other 2 should hold your friends'
 * or family members' info.
 */

//System Libraries
#include <iostream>

#include "PersonalInfo.h"
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    PersonalInfo *person1 = new PersonalInfo();
    PersonalInfo *person2 = new PersonalInfo();
    PersonalInfo *person3 = new PersonalInfo();
    
    person1->setName("Doidle");
    person1->setAddress("1600 Pennsylvania Avenue, Washington DC");
    person1->setAge(25);
    person1->setPhone("(123)456-7890");
    
    person2->setName("Doyle");
    person2->setAddress("350 Fifth Avenue New York, NY 10118");
    person2->setAge(35);
    person2->setPhone("(123)456-7890");
    
    person3->setName("Dora");
    person3->setAddress("4059 Mt Lee Dr. Hollywood, CA 90068");
    person3->setAge(45);
    person3->setPhone("(123)456-7890");
    
    return 0;
}
