/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: October 1, 2015
 * Assignment: Problem 9.2 "Test Scores #1" 
 * Directions: This program dynamically allocates an array large enough to hold
 * a user-defined number of test scores. Once all the scores are entered,
 * the array should be passed to a function that sorts them in ascending
 * order. Another function should be called that calculates the average
 * score. The program displays the sorted list of scores and averages
 * with appropriate headings. pointer notations are used rather than
 * array notation whenever possible
 * input validation: do not accept negative numbers for test scores
 */

//System Libraries
#include <iostream>
#include <algorithm> //for sort function
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
float getAverage(int *, int);

//Execution begins here
int main(int argc, char** argv) {
    //Variable declarations    
    int *testScores; //dynamic array of all test scores
    int numScores; //number of individual scores; also the size of array
    
    //prompt user for number of scores
    cout << "Please enter the number of scores you will input: " << endl;
    //as user enters number of scores, input validation is checked for negative number
    do { cin >> numScores;
        if (numScores < 0)
            cout << "Please enter a positive score: " << endl;
    } while (numScores > 0);
    
    //Inputs individual scores
    testScores = new int[numScores]; //initialized array
    //prompts user to enter each score
    cout << "Please enter test score: \n";
    for (int i = 0; i < numScores; i++) {
        cout << "Test #" << i + 1 << ": ";
        int score;
        cin >> score;
        //input validation: score must be positive
        while (score < 0){
            cout << "Please enter a positive score: " << endl;
            cin >> score;
        }
        //score input is stored into array
        *(testScores+i) = score;
    }
    
    //sort test scores in ascending order
    sort(testScores, testScores + numScores);
    
    //Display sorted array
    cout << "The sorted list of scores: \n";
    for (int i = 0; i < numScores; i++){
        cout << *(testScores + i) << " ";
    }
    
    //Display average
    cout << "\nThe average Score is: " << getAverage(testScores, numScores);
    
    return 0;
}

/* 
 * Definition of function getAverage.
 * parameters: array pointer and size of array
 * returns average of array elements
 */
float getAverage(int *array, int size){
	float totalSum = 0.0;
	for (int i = 0; i< size; i++){
		totalSum += *(array + i); //add the sum of each score in the array
	}
	return totalSum /(size);
}

