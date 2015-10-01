/* 
 * File:   prob_9_6.cpp
 * Author: Tiffany Pan
 * Created on September 22, 2015, 12:53 PM
 * Purpose: "Case Study Modification #1"
 * Homework: Complete this assignment
 */

//System Libraries
#include <iostream> //input/output stream library
 
using namespace std; //utilize standard name-space directly 
 
//User Libraries
//Global Constants
//Function Prototypes
 void arrSelectSort(int *[], int);
 void showArray(const int[], int);
 void showArrPtr(int *[], int);
 
/*
 * Modify program 9-19 so it can be used with any set of donations. the program
 * should dynamically allocate the donations array ask the user to input its values
 * 
 * program 9-19 shows the donations made to the US by the employees of CK Graphics,
 * Inc. It displays the donations in order from lowest to highest and in the 
 * original order they were received.
 */
int main(int argc, char** argv) {
    
    int NUM_DONATIONS; //number of donations
    cout<<"Enter the number of donations you will input"<<endl; //prompt users for number of integers in data set
    cin>> NUM_DONATIONS;
    int donations[NUM_DONATIONS]; //An array containing the donation amounts.
    int *arrPtr[NUM_DONATIONS]; //An array of pointers to int
    cout<<"Enter in donation values"<<endl; //input integer data set
    for (int i= 0; i< NUM_DONATIONS; i++){ //as user is inputting integers, they are stored into numbers[]
        cin>>donations[i];
    }
    
    //Each element of arrPtr is a pointer to int, make each element point
    //to an element in the donations array.
    for(int count=0; count<NUM_DONATIONS; count++)
        arrPtr[count] = &donations[count];
    
    //Sort the elements of the array of points
    arrSelectSort(arrPtr, NUM_DONATIONS);
    
    //Display the donations using the array of pointers. This will
    //display them in sorted order.
    cout<< "The donations, sorted in ascending order are: \n";
    showArrPtr(arrPtr, NUM_DONATIONS);
    
    //Display the donations in their original order. 
    cout<< "The donations, in their original order are: \n";
    showArray(donations, NUM_DONATIONS);
    
    return 0;
}

//Definition of function arrSelectSort.
//This function performs an ascending order selection sort on arr,
//which is an array of pointers. Each element of the array points to an
//element of a second array. After the sort, arr will point to the elements
//of the second array in ascending order.
void arrSelectSort(int *arr[], int size)
{
    int startScan, minIndex;
    int *minElem;
    
    for(startScan = 0; startScan<(size-1); startScan++)
    {
        minIndex= startScan;
        minElem= arr[startScan];
        for(int index= startScan + 1; index< size; index++)
        {
            if(*(arr[index])< *minElem)
            {
                minElem= arr[index];
                minIndex= index;
            }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minElem;
    }
}

//Definition of function showArray.
//This function displays the contents of arr. size is the number of elements.
void showArray(const int arr[], int size)
{
    for(int count = 0; count < size; count++)
        cout<<arr[count]<<" ";
    cout<<endl;
}

//Definition of function showArrPtr.
//This function displays the contents of the array points to by arr.
//size is the number of elements
void showArrptr(int *arr[], int size)
{
    for (int count = 0; count < size; count++)
        cout<< *(arr[count]) << " ";
    cout<<endl;
}
