/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: October 1, 2015
 * Assignment: Problem 11.7 Customer Accounts
 * Directions: Write a program that uses a structure to store the following data 
 * about a customer account: Name, 
 * Address, 
 * City, State, and ZIP
 * Telephone Number
 * Account Balance
 * Date of Last Payment
 * The program should use an array of at least 10 structures. It should let the 
 * user enter data into the array, change the contents of any element, and 
 * display all the data stored in the array. The program should have a 
 * menu-driven user interface. Input Validation: When the data for a new account 
 * is entered, be sure the user enters data for all the fields. No negative 
 * account balances should be entered.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Customer structure
struct Address {
    int number; //number
    string city; //city
    string state; //state
    int zip; //ZIP
};
struct Date {
    int month; //month
    int day; //day of month
    int year; //year
};
struct Customer{
    string name; //name of customer
    Address address; //customer's address   
    int phone; //phone number
    float balance; //account balance
    Date date;
};
//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
   //Variable declarations
    const int NUM_CUSTOMERS = 10; //Number of customers
    Customer customers[NUM_CUSTOMERS]; //array of structures
    char option;
    //menu
    do {
        cout << "Please select one of the following options: "
                "A. Add a new customer"
                "B. Edit a customer's information"
                "C. "
    } while (option != 'E');
   return 0;
}

/* 
 * Definition of function.
 *
 */
