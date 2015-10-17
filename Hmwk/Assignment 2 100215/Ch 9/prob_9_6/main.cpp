/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: October 1, 2015
 * Assignment: Problem 9.6 Case Study Modification #1
 * Directions: Modify Program 9-19 (the United Cause case study program) so it can be used with
 * any set of donations. The program should dynamically allocate the donations array
 * and ask the user to input its values. program 9-19 shows the donations made to the US by the employees of CK Graphics,
 * Inc. It displays the donations in order from lowest to highest and in the 
 * original order they were received.
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
    int numDonations; //number of donations
    int *donations; //dynamic array containing donation amounts
    int **arrPtr; //array of pointers to integer
    
    //prompt user to enter number of donations
    cout << "Please enter the number of donations you will input ";
    cin >> numDonations;
    
    //initialize donations array
    donations = new int[numDonations];
    arrPtr = new int*[numDonations];
    
    //prompt user for individual donation amounts
    cout << "Please enter donation amount: \n";
    for (int i = 0; i < numDonations; i++) {
        cout << "Donation #" << i + 1 << ": ";
        //input validation for donation amount
        int amount;
        do { cin >> amount;
            if (amount < 0)
                cout << "Please enter a positive amount: \n";
        } while (amount < 0);
        *(donations + i) = amount;
    }
    
    //Each element of arrPtr is a pointer to int, make each element point
    //to an element in the donations array.
    for(int count=0; count< numDonations; count++)
        arrPtr[count] = &donations[count];
    
    //Sort the elements of the array of points
    arrSelectSort(arrPtr, numDonations);
    
    //Display the donations using the array of pointers. This will
    //display them in sorted order.
    cout << "The donations, sorted in ascending order are: \n";
    showArrPtr(arrPtr, numDonations);
    
    //Display the donations in their original order. 
    cout << "The donations, in their original order are: \n";
    showArray(donations, numDonations);
    
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
