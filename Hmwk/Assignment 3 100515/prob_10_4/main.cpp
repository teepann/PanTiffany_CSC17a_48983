/* 
 * File:   prob_10_4.cpp
 * Author: Tiffany Pan
 * Created on September 30, 2015, 12:53 PM
 * Purpose: "average number of letters"
 * Homework: Complete this assignment
 */

//System Libraries
#include <iostream> //input/output stream library
#include <string> //string library
#include <iomanip> //input/output manipulation
#include <cctype> //cctype library
#include <cstdlib> //c standard library
using namespace std; //utilize standard name-space directly 
 
//User Libraries
//Global Constants
//Function Prototypes
void wordCount(char [], int&, float&, int&);
float getAvg(int, int, float);

/*
 * modify the program written for problem 3, so that it also displays
 * the average number of letters in each word
 * 
 * problem 3; word counter- a function that accepts a pointer to a c-string as an
 * argument and returns the number of words contained in the string.
 * it asks the user to input a string and then passes it to the function
 */
int main(int argc, char** argv) {
    char cstring[81];
    cout<<"Enter a string, 80 or fewer characters:\n";
    cin.getline(cstring, 81);
    cout<<"\nThe number of words in that string: ";
    index = wordCount(cstring);
    cout<<index<<endl;
    
    return 0;
}

int wordCount(char cstring[]){
    int index = 0;
    int word = 0;
    while(cstring[index]!='\0'){
        if(isspace(cstring[index]))
            index++;
        index++;
    }
    return word;
}