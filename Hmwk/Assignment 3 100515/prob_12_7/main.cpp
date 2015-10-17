/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: October 1, 2015
 * Assignment: Problem 12.7
 * Directions: write a program that asks the user for 2 file names. the first file will be
 * opened for input and the second file will be opened for output.(first file
 * contains sentences that end with a period.) the program will read the 
 * contents of the first file and change all the letters to lowercase except 
 * the first letter of each sentence, which will be made uppercase. the revised
 * contents should be stored in the 2nd.
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
string changeCase(string);

//Execution begins here
int main(int argc, char** argv) {
   //Variable declarations
    //delimiter of a sentence
    const char DELIMITER = '.';
    //string delimiter of a sentence
    const string SDELIMITER = ".";
    //input file name
    string ifileName;
    //output file name
    string ofileName;
    //input file
    ifstream ifile;
    //output file
    ofstream ofile;
    //sentence from file
    string sentence;
    
    cout<< "Please enter file name: ";
    getline(cin, ifileName);
    
    cout << "Please enter an output file name: ";
    getline(cin, ofileName);
    
    ifile.open(ifileName.c_str(), ios::in);
    ofile.open(ofileName.c_str(), ios::out);
    
    if(ifile && ofile){
        while(getline(ifile, sentence, DELIMITER)){
            sentence.append(SDELIMITER);
            ofile << changeCase(sentence);
        }
        ifile.close();
        ofile.close();
        
    } else 
        cerr << "File IO error!";
   return 0;
}

/* 
 * Definition of function changeCase
 * changes all the letters to lowercase except the first letter of each sentence
 * parameter: string
 * returns the correct sentence
 */
string changeCase(string str){
    int i = 0;
    
    while((i < str.length()) && !isalpha(str[i])){
        i++;
    }
    str[i] = toupper(str[i]);
    
    //lowercase for rest of sentence
    for (i = i + 1; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}