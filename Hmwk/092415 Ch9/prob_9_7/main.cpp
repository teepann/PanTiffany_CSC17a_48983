/* 
 * File:   prob_9_7.cpp
 * Author: Tiffany Pan
 * Created on September 22, 2015, 12:53 PM
 * Purpose: "Case Study Modification #2"
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
 * Modify program 9-19 so the arrptr is sorted in descending order instead of ascending
 * 
 * program 9-19 shows the donations made to the US by the employees of CK Graphics,
 * Inc. It displays the donations in order from lowest to highest and in the 
 * original order they were received.
 */
int main(int argc, char** argv) {
    const int NUM_DONATIONS= 15; //number of donations
    
    //An array containing the donation amounts.
    int donations[NUM_DONATIONS] = { 5, 100, 5, 25, 10,
                                     5, 25, 5, 5, 100,
                                     10, 15, 10, 5, 10 };
    
    //An array of pointers to int.
    int *arrPtr[NUM_DONATIONS] = {nullptr, nullptr, nullptr, nullptr, nullptr,
                                  nullptr, nullptr, nullptr, nullptr, nullptr,
                                  nullptr, nullptr, nullptr, nullptr, nullptr};
    
    //Each element of arrPtr is a pointer to int, make each element point
    //to an element in the donations array.
    for(int count=0; count<NUM_DONATIONS; count++)
        arrPtr[count] = &donations[count];
    
    //Sort the elements of the array of points
    arrSelectSort(arrPtr, NUM_DONATIONS);
    
    //Display the donations using the array of pointers. This will
    //display them in sorted order.
    cout<< "The donations, sorted in descending order are: \n";
    showArrPtr(arrPtr, NUM_DONATIONS);
    
    //Display the donations in their original order. 
    cout<< "The donations, in their original order are: \n";
    showArray(donations, NUM_DONATIONS);
    
    return 0;
}

//Definition of function arrSelectSort.
//This function performs an descending order selection sort on arr,
//which is an array of pointers. Each element of the array points to an
//element of a second array. After the sort, arr will point to the elements
//of the second array in descending order.
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
            if(*(arr[index])> *minElem)
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


