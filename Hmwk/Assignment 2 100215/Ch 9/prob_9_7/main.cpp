/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: October 1, 2015
 * Assignment: Problem 9.7 Case Modification #2
 * Directions: Modify Program 9-19(the United Cause case study program) so the arrptr array is
 * sorted in descending order instead of ascending order. 
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void arrSelectSort(int *[], int);
void showArray(const int [], int);
void showArrPtr(int *[], int);

//Execution begins here
int main(int argc, char** argv) {
    //Variable declarations
    const int NUM_DONATIONS = 15; //number of donations
    // An array containing the donation amounts.
    int donations[NUM_DONATIONS] = {5, 100, 5, 25, 10,
                                    5, 25, 5, 5, 100,
                                    10, 15, 10, 5, 10};
    // An array of pointers to int.
    int *arrPtr[NUM_DONATIONS] = {NULL, NULL, NULL, NULL, NULL,
                                  NULL, NULL, NULL, NULL, NULL,
                                  NULL, NULL, NULL, NULL, NULL};
    
        // Each element of arrPtr is a pointer to int. Make each
    // element point to an element in the donations array.
    for (int count = 0; count < NUM_DONATIONS; count++)
        arrPtr[count] = &donations[count];

    // Sort the elements of the array of pointers.
    arrSelectSort(arrPtr, NUM_DONATIONS);

    // Display the donations using the array of pointers. This
    // will display them in sorted order.
    cout << "The donations, sorted in descending order are: \n";
    showArrPtr(arrPtr, NUM_DONATIONS);

    // Display the donations in their original order.
    cout << "The donations, in their original order are: \n";
    showArray(donations, NUM_DONATIONS);
    return 0;
}
/* 
 * Definition of function arrSelectSort.
 * This function performs an ascending order selection sort
 * on arr, which is an array of pointers. Each element of 
 * the array points to an element of a 2nd array. After the
 * sort, arr will point to the elements of the 2nd array in 
 * ascending order.
 */
void arrSelectSort(int *arr[], int size) {
    int startScan, maxIndex;
    int *maxElem;

    for (startScan = 0; startScan < (size - 1); startScan++) {
        maxIndex = startScan;
        maxElem = arr[startScan];
        for (int index = startScan + 1; index < size; index++) {
            if (*(arr[index]) > *maxElem) { //Switching max value instead of min one
                maxElem = arr[index];
                maxIndex = index;
            }
        }
        arr[maxIndex] = arr[startScan];
        arr[startScan] = maxElem;
    }
}


/* 
 * Definition of function showArray.
 * This function displays the contents of arr.
 * size is the number of elements
 */
void showArray(const int arr[], int size)
{
    for(int count = 0; count < size; count++)
        cout<<arr[count]<<" ";
    cout<<endl;
}

/* 
 * Definition of function showArrptr.
 * This function displays the contents of the array points to
 * by arr. size is the number of elements.
 */
void showArrptr(int *arr[], int size)
{
    for (int count = 0; count < size; count++)
        cout<< *(arr[count]) << " ";
    cout<<endl;
}
