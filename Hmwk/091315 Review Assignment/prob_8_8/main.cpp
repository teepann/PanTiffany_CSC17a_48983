/*
* File: main.cpp
* Author: Tiffany Pan
* Date: September 13, 2015
* Assignment: Problem 8.8 Search Benchmarks
* Directions: Write a program that has an array of at least 20 integers. It should 
* call a function that uses the linear search algorithm to locate one of the values. 
* The function should keep a count of the number of comparisons it makes until it 
* finds the value. The program then should call a function that uses the binary search 
* algorithm to locate the same value. It should also keep count of the number of comparisons 
* it makes. Display these values on the screen.
*/

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
	//Variable declarations
	const int NUM_NAMES = 20;

	system("pause");
	return 0;
}

/*
* Definition of function linearSearch.
*
*/ 
int linearSearch(int list[], int numElems, int value)
{
	int count = 0; // used to keep count of comparison

	int index = 0; // Used as a subscript to search array
	int position = -1; // To record position of search value
	bool found = false; // Flag to indicate if value was found

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

/*
* Definition of function binarySearch.
*
*/
int binarySearch(int array[], int size, int value)
{
	int count = 0; // used to keep count of comparison

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
