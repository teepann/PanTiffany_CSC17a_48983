/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: October 1, 2015
 * Assignment: Problem 10.4 Average number of letters
 * Directions: Modify the program you wrote for Problem 3 (Word Counter), so it 
 * also displays the average number of letters in each word.
 */

//System Libraries
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int getAverage(const char*);

//Execution begins here
int main(int argc, char** argv) {
   //Variable declarations
    string data;
    
    //prompts user to enter a string
    cout << "Please enter a string of words: \n";
    getline(cin, data);
    
    //outputs the average number of letters in each word
    cout << "The average number of letters in each word for the string \"" 
            << data << "\" is: " << getAverage(data.c_str());
   return 0;
}

/* 
 * Definition of function getAverage.
 * Parameter: pointer to C-string
 * returns average number of letters in each word
 */
int getAverage(const char* str){
    //variable declarations
    int sum = 0;
    int counter = 0;
    char* word;
    word = strtok(const_cast<char*>(str), " ");
    
    //sum the string length of each word and skipping over white space
    while (word != NULL){
        sum += strlen(word);
        counter++;
        word = strtok(NULL, " ");
    }
    return sum/counter; //returns the average
}