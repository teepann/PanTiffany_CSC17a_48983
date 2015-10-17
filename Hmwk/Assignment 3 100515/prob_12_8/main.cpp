/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: October 1, 2015
 * Assignment: Problem 12.8
 * Directions: write a function named arrayToFile. The function should accept 3 
 * arguments: the name of a file, a pointer to an int array,
 * the size of the array. the function should open the specified
 * file in binary mode, write the contents of the array to the file,
 * and then close the file.
 * write another function named file ToArray. This function should accept
 * 3 arguments: the name of a file, a pointer to an int array, the size of array.
 * the function should open the specified file in binary mode, read its contents
 * into the array, and then close the file.
 * write a complete program that demonstrates these functions by using the 
 * arrayToFile function to write an array to a file, and then using the 
 * fileToArray function to read the data from the same file.
 * After the data are read from the file into the array, display
 * the array's contents on the screen.
 */

//System Libraries
#include <iostream>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void arrayToFile (const char*, int*, const int);
void fileToArray (const char*, int*, const int);

//Execution begins here
int main(int argc, char** argv) {
   //Variable declarations
    const char* FILE_NAME = "file.dat";
    const int SIZE = 10;    
    int ary[SIZE] = {23, 67, 12, 89, 23, 12, 78, 90, 22, 88};
    int *result;
    
    //read array to file
    arrayToFile(FILE_NAME, ary, SIZE);
    //file contents into array
    fileToArray(FILE_NAME, ary, SIZE);
    
    //print out array
    for(int i = 0; i< SIZE; i++){
        cout << result[i] << " ";
    }
   return 0;
}

/* 
 * Definition of function arrayToFile
 * opens the given file in binary mode,
 * write the contents of array to the file and closes it
 * parameter: name of a file, pointer to int array, and size of array
 */
void arrayToFile (const char* fileName, int* ary, const int size){
    fstream aryToFile(fileName, ios::out | ios::binary);
    if(aryToFile){
        aryToFile.write(reinterpret_cast<char*>(ary), size*sizeof(int));
        aryToFile.close();
    }
    else
        cerr< "File I/O error!";
}

/* 
 * Definition of function fileToArray
 * opens the given file in binary mode,
 * reads contents into array and closes it
 * parameter: name of a file, pointer to int array, and size of array
 */
void fileToArray (const char* fileName, int* ary, const int size){
    fstream fileToAry (fileName, ios::in|ios::binary);
    
    if(fileToAry) {
        fileToAry.read(reinterpret_cast<char*>(ary), size*sizeof(int));
        fileToAry.close();
    }
    else
        cerr <<"File IO error!";
}