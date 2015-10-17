/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on September 10, 2015, 11:16 AM
 */

#include <iostream>
#include <string>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    const in NUM_NAMES = 20;
    return 0;
}
int linearSearch(int list[], int numElems, int value)
{
    int count=0; // used to keep count of comparison
    
    int index=0; // Used as a subscript to search array
    int position=-1; // To record position of search value
    bool found=false; // Flag to indicate if value was found
    
    while (index<numElems&&!found)
    {
        if (list[index] == value) // If the value is found
        {
            found = true; // Set the flag 
            position = index; // Record the value's subscript
        }
        index++; // Go to the next element
        count++;
    }
    return position; // Return the position, or -1
}
int binarySearch(int array[], int size, int value)
{
    int count=0; // used to keep count of comparison
    
    int first = 0,             // First array element
        last = size - 1,       // Last array element
        middle,                // Mid point of search    
        position = -1;         // Position of search value
    bool found = false;        // Flag
    while (!found && first <= last)
    {
        middle = (first + last) / 2;     // Calculate mid point      
        if (array[middle] == value)      // If value is found at mid      
        {         
            found = true;
            position = middle;      
        }      
        else if (array[middle] > value)  // If value is in lower half         
            last = middle - 1;      
        else         
            first = middle + 1;           // If value is in upper half
        count++;
    }
    return position;

}

