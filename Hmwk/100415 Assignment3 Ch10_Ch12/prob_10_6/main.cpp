/* 
 * File:   prob_10_6.cpp
 * Author: Tiffany Pan
 * Created on September 30, 2015, 12:53 PM
 * Purpose: "vowels and consonants"
 * Homework: Complete this assignment
 */

//System Libraries
#include <iostream> //input/output stream library
using namespace std; //utilize standard name-space directly 
 
//User Libraries
//Global Constants
//Function Prototypes
int countVowels(char *str);
int countCons(char* str);
void process(char, char[]);
/*
 * the function accepts a pointer to a c-string as its argument
 * the function should count the number of vowels appearing in the string and 
 * return that number.
 * another function accepts a pointer to a c-string as it argument. 
 * this function should count the number of consonants appearing in the string
 * and return that number
 * demonstrate these 2 functions and performing these steps;
 * 1. the user is asked to enter a string
 * 2. the program displays the following menu;
 * A) Count the number of vowels in the string
 * B) Count the number of consonants in the string
 * C) Count both the vowels and consonants in the string
 * D) Enter another string
 * E) Exit the program
 * 3. The program performs the operation selected by the user and repeats until
 * the user selects E to exit the program.
 */
int main(int argc, char** argv) {
    const int SIZE = 81; //max size of the array
    char userString[SIZE]; 
    char choice; //to hold the menu selection
    char *strPtr = userString; //declares and intializes the pointer
    
    //get the string from the user
    cout << "Please enter a string no more than 80 characters: \n";
    cin.getline(userString, SIZE);
    
    //display the menu and get a choice on repeat until exit
    do {
        cout << "\n\nA. Count the number of vowels in the string \n";
        cout << "B. Count the number of consonants in the string \n";
        cout << "C. Count both the number of vowels and consonants in the string \n";
        cout << "D. Enter another string \n";
        cout << "E. Exit the program \n\n";
        cout << "Please make your selection: ";
        cin >> choice;
        process(choice, userString);
    } while (choice!='E'||choice!='e');
    
    return 0;
}

void process(char choice, char userString){
    if(tolower(choice =='a')){
        countVowels(userString);
        cout<<"This string contains " << countVowels(userString);
        cout<<" vowels. \n";
    }
    else if (tolower(choice =='b')){
        countCons(userString);
        count<<"This string contains " << countCons(userString);
        cout<<" consonants. \n";
    }
    else if (tolower(choice == 'c')){
        cout<<" ";
        
    }
    else if (tolower(choice == 'd')){
        cout<<" ";
    }
    else {
        cout<<"Please make a valid selection"<<endl;
    } 
}

//countVowels: the parameter str is a pointer that points to a string.
//the char vowels[] is an array of vowels that the function searches
//for in the string. the function returns the number of times
//the characters in the array appear in the string
int countVowels(char* str){
    int times = 0; //to hold the number of times vowels appear
    char vowels[11]= {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    char *vowelsPtr = vowels;
    
    //step through the string and count the number of vowels
    while(*str != '\0'){
        for(int count = 0; count <11; count++){
            if(*str == vowelsPtr[count])
                times++;
        }
        str++;
    }
    return times;
}

//countCons: The parameter str is a pointer that points to a string. the 
//char consonants[] is an array of consonants that the function searches
//for in the string. the function returns the number of times
//the characters in the array appear in the string
int countCons(char *str){
    int times = 0; //to hold the number of consonants
    char consonants[43]= {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm',
                           'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y',
                           'z', 'B', 'C', 'D', 'F', 'G', 'H','J', 'K', 'L',
                           'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X',
                           'Y', 'Z'};
    char *consPtr = consonants;
    
    //step through the string and count the number of consonants
    while(*str != '\0'){
        for(int count = 0; count < 43; count++){
            if(*str == consPtr[count])
                times++;        
        }
        str++;
    }
    return times;
}
