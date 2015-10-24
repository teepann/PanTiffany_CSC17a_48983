/* 
 * File:   mode.cpp
 * Author: Tiffany Pan
 * Created on September 15, 2015, 12:53 PM
 * Purpose: determine the mode, median, mean in a given array of integers
 */
//System Libraries
#include <iostream> //input/output stream library
#include <cstdlib> //C Standard Library
using namespace std; //utilize standard name-space directly 

//User Libraries
//Global Constants
//Function Prototypes
void sort(int array[], int size);
int* mode(int [], int);
float mean(int [], int);
float median(int[], int);

/*
 * Mode array may have nothing, 1 mode, or many
 */
int main(int argc, char** argv) {
    
    int size=24;
    int numbers[size];
    for(int i=0; i<size; i++){
        numbers[i]=i%5;
    }
//    int size;
//    cout<<"Enter the number of integers you will input"<<endl; //prompt users for number of integers in data set
//    cin>> size;
//    int numbers[size];
//    cout<<"Enter in your integer values"<<endl; //input integer data set
//    for (int i= 0; i< size; i++){ //as user is inputting integers, they are stored into numbers[]
//        cin>>numbers[i];
//    }
    
    int *modeArray= mode(numbers, size); //create an array of modes
    int numModes= modeArray[0]; //retrieve the number of modes
    int maxFreq= modeArray[1]; //retrieve the max frequency
    
    if(!numModes){ //if numModes =0, there is no mode
        cout<<"This data set has no modes\n";
        return 0;
    }
    else { 
        cout<<"There are "<<numModes<<" mode(s)."<<endl; //print out number of modes
        cout<<"Each mode appears "<<maxFreq<<" times."<<endl; //print out the max frequency
        cout<<"The mode(s) are: "; //print out the modes
        for(int i = 2; i<numModes+2; i++){
            cout<<modeArray[i]<<" ";
        }
        cout<<endl;
        cout<<"The mean is: "<<mean(numbers, size)<<endl;
        cout<<"The median is: "<<median(numbers, size)<<endl;
    }
    return 0;
}
int* mode(int numbers[], int size)
{
    int maxFreq= 0, //max frequency of a number in the data set
        numModes= 0, //how many modes there are in the data set
        freq= 1; //frequency counter for each number in the data set
    int currentElement; //current element of the data set's array in the loop    
    sort(numbers, size); //calls sort function to sort array
    
    //find the maximum frequency:
    for(int i = 0; i< size; i++){
        currentElement= numbers[i]; //set currentElement to the ith element in numbers
        int j=i+1; //check if the next element in numbers is the same as currentElement
        while (numbers[j]== currentElement){ //if it is, then continue checking and add a count to the frequency
            freq++;
            j++;
        }
        i= j-1;//skip the next elements that are the same values
        if(freq> 1 && freq> maxFreq){ //set max frequency
            maxFreq= freq;
        }
        freq= 1;//reset freq to 1
    }
    
    //find number of modes:
    for(int i = 0; i<size; i++){
        currentElement= numbers[i];
        int j=i+1;
        while(numbers[j]==currentElement){
            freq++;
            j++;
        }
        i= j-1;
        if(freq>1 && freq==maxFreq){  //if frequency of currentElement is same as the maxFreq
            numModes++; 
        }
        freq=1;//reset frequency counter to 1
    }
    
    // add modes to modeArray:
    int *modeArray = new int[numModes+2]; //create array of modes
    modeArray[0]=numModes; //set the first element in modeArray as number of modes
    modeArray[1]=maxFreq; //set the second element in modeArrays as the maximum frequency
    int index=1; //create an index counter for the modeArray
    for(int i = 0; i<size; i++){
        currentElement= numbers[i];
        int j=i+1;
        while(numbers[j]==currentElement){
            freq++;
            j++;
        }
        i= j-1;
        if(freq>1 && freq==maxFreq){  //if frequency of currentElement is same as the maxFreq            
            index++;
            modeArray[index]=numbers[i]; //add that currentElement to modeArray            
        }
        freq=1;//reset frequency counter to 1
    } 
    
    return modeArray;
}

float mean(int numbers[], int size){
    float sum = 0.0;
    for(int i = 0; i< size; i++){
        //sum of all numbers in the array
        sum+=numbers[i];
    }
    return sum/size; //returns average 
}

float median(int numbers[], int size){
    if (size%2==0) //if there's an even number of elements
        //return average of the middle two numbers
        return (float)(numbers[size/2] + numbers[size/2 + 1])/2;
    else  //if there's an odd number of elements
        //return the middle number
        return numbers[size/2 + 1];
}
//function definition of sort- selection sort
void sort(int array[], int size)
{
    int startScan, minIndex, minValue;
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