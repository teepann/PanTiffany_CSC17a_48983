/* 
 * File:   prob_9_2.cpp
 * Author: Tiffany Pan
 * Created on September 22, 2015, 12:53 PM
 * Purpose: "Test Scores #1"
 * Homework: Complete this assignment
 */

//System Libraries
#include <iostream> //input/output stream library
#include <cstdlib> //C Standard Library
 
using namespace std; //utilize standard name-space directly 
 
//User Libraries
//Global Constants
//Function Prototypes
 void sort(float *array, int size);
 float averageScore (float *array, int size);
 float *input(int size);
/*
 * This program dynamically allocates an array large enough to hold
 * a user-defined number of test scores. Once all the scores are entered,
 * the array should be passed to a function that sorts them in ascending
 * order. Another function should be called that calculates the average
 * score. The program displays the sorted list of scores and averages 
 * with appropriate headings. pointer notations are used rather than
 * array notation whenever possible
 * input validation: do not accept negative numbers for test scores
 */
int main(int argc, char** argv) {
    
    int size;
    cout<<"Enter the number of scores you will input"<<endl; //prompt users for number of integers in data set
    cin>> size;
    float *scores = input(int size);
    
    sort(scores, size); //sorts the scores in ascending order
    float avgScore= averageScore(scores, size); //returns the average score
    
    cout<<"Scores in ascending order: "; //print out scores in ascending order
    for (int i=0; i<size; i++){
        cout<<scores[i]<<" ";
    }
    cout<<"\nAverage Score: "<<avgScore<<endl; //print out average 
    
    return 0;
}

float *input(int size){
    float num;    
    float *scores = new float[size];
    cout<<"Enter in test scores"<<endl; //input integer data set
    int index=0;
    while(index<size) { //as user is inputting integers, they are stored into scores[]
        cin>>num;
        if(num>0){ //checks if number entered is positive
            scores[index]=num;
            index++;
        }
        else //prompt use to enter positive number if they input negative
            cout<<"Please enter a positive score"<<endl;
    }
    return scores;
}
//function definition of calculating average score
float averageScore(float *array, int size){
    float totalSum=0;
    for(int i = 0; i< size; i++){ 
        totalSum += array[i]; //add the sum of each score in the array
    }
    return totalSum/size; 
}

//function definition of sort- selection sort
void sort(float *array, int size)
{
    int startScan, minIndex;
    float minValue;
    for (startScan =0; startScan < (size -1); startScan++){
        minIndex = startScan; 
        minValue = array[startScan];
        for(int index= startScan + 1; index < size; index++){
            if (array[index] < minValue){
                minValue = array[index];
                minIndex = index;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan]=minValue;
    }
}

