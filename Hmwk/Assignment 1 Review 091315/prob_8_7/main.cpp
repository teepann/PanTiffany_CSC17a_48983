/*
* File: main.cpp
* Author: Tiffany Pan
* Date: September 13, 2015
* Assignment: Problem 8.7 Binary String Search
* Directions: Modify the  binarySearch function presented in this chapter so it 
* searches an array of strings instead of an array of  ints. Test the function 
* with a driver program. Use Program   8-8    as a skeleton to complete. (The 
* array must be sorted before the binary search will work.)
*/

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void stringSelectionSort(string array[], int size);
int stringBinarySearch(string array[], int size, string value);

//Execution begins here
int main(int argc, char** argv) {
	//Testing the function
	const int NUM_WORDS = 20;
	string list[NUM_WORDS] = { "hello", "my", "name", "is", "Tiffany",
		"Pan", "and", "I", "am", "taking",
		"computer", "science", "classes", "to",
		"get", "a", "bachelors", "degree", "in", "CS" };

	//Variable declarations
	string word;
	int results;

	//first sort array
	stringSelectionSort(list, NUM_WORDS);

	//prompt user to enter a word in the list
	cout << "Please enter a word in the list: ";
	cin >> word;

	//search for word
	results = stringBinarySearch(list, NUM_WORDS, word);

	//If results contains -1 the name was not found!
	if (results == -1)
		cout << "That word does not exist in the array.\n";
	else {
		//Otherwise results contains the subscript of the word's ID in the array
		cout << "That word is found at index " << results << endl;

	}
	system("pause");
	return 0;
}

/*
* Definition of function stringSelectionSort.
* Takes the parameter of the a array list of strings and size of array
* performs an ascending order selection sort on the array
*/
void stringSelectionSort(string list[], int size)
{
	int startScan, minIndex;
	string minValue;

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = list[startScan];
		for (int index = startScan + 1; index < size; index++)
		{
			if (list[index] < minValue)
			{
				minValue = list[index];
				minIndex = index;
			}
		}
		list[minIndex] = list[startScan];
		list[startScan] = minValue;
	}
}

/*
* Definition of function stringBinarySearch.
* Takes the parameter of the a array list of strings and size of array and a value to be found
* This performs a binary search on the string array it has a max size of elements.
* searches for number stored in the value. if number is found, its array is returned
* otherwise, -1 is returned indicating the value wasn't in the array
*/
int stringBinarySearch(string list[], int size, string value)
{
	int first = 0, last = size - 1, middle, position = -1;  //respective elements of the array      
	bool found = false; // Flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2; // Calculate mid point
		if (list[middle] == value) // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (list[middle] > value) // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1; // If value is in upper half
	}
	return position;
}
