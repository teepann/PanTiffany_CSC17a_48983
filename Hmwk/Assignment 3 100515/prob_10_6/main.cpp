/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: October 1, 2015
 * Assignment: Problem 10.6 Vowels and Consonants
 * Directions: Write a function that accepts a pointer to a C-string as its 
 * argument. The function should count the number of vowels appearing in the 
 * string and return that number. Write another function that accepts a pointer 
 * to a C-string as its argument. This function should count the number of 
 * consonants appearing in the string and return that number.
 * Demonstrate these two functions in a program that performs the following steps:
 * 1. The user is asked to enter a string.
 * 2. The program displays the following menu:
 * A) Count the number of vowels in the string
 * B) Count the number of consonants in the string
 * C) Count both the vowels and consonants in the string
 * D) Enter another string
 * E) Exit the program
 * 3. The program performs the operation selected by the user and repeats until 
 * the user selects E to exit the program.
 */

//System Libraries
#include <iostream>
#include <cctype>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <stdio.h>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int vowelCount(const char*);
int consonantCount(const char*);
void cleanCBuffer();

//Execution begins here
int main(int argc, char** argv) {
   //Variable declarations
    string str;
    char option;
    
    //prompt user to enter a string
    cout << "Please enter a string: ";
    getline(cin, str);
    
    do {
        cout << " A) Count the number of vowels in the string\n"
                " B) Count the number of consonants in the string\n"
                " C) Count both the vowels and consonants in the string\n"
                " D) Enter another string\n"
                " E) Exit the program\n";
        option = toupper(cin.get());
        //clean the buffer to get a new input in next loop
        cin.ignore();
        cin.clear();
        
        if (option = 'A')
            cout << "The number of vowels: " << vowelCount(str.c_str()) << endl;
        else if (option == 'B')
            cout << "The number of consonants: " << consonantCount(str.c_str()) << endl;
        else if (option == 'C') {
            cout << "The number of vowels: " << vowelCount(str.c_str()) << endl;
            cout << "The number of consonants: " << consonantCount(str.c_str()) << endl;
        }
        else if (option == 'D'){
            cout << "PLease enter a another string: ";
            getline(cin, str);
        }
    } while (option != 'E');

   return 0;
}

/* 
 * Definition of function vowelCount.
 * parameter: a pointer to C-string
 * returns: number of vowels in the string
 */
int vowelCount(const char* string){
    //all the vowels
    static const char vowels[] = "aeiouAEIOU";
    //number of vowels
    int numVowels = 0;
    
    //loop through each char in string
    for (int i = 0; i < strlen(string); i++){
        //increase counter if char is a vowel
        if (strchr(vowels, string[i]) != NULL){
            numVowels++;
        }
    }
    return numVowels;
}

/* 
 * Definition of function consonant count
 * parameter: a pointer to a C-string
 * returns: number of vowels in the string
 */
int consonantCount(const char* string){
    //all the vowels
    static const char vowels[] = "aeiouAEIOU";
    //number of consonants
    int numConsonants = 0;
    
    //loop through each char in string
    for (int i = 0; i < strlen(string); i++){
        //increase counter if char is an alpha not in vowel collection
        if (isalpha(string[i]) && (strchr(vowels, string[i]) == NULL)){
            numConsonants++;
        }
    }
    return numConsonants;
}
