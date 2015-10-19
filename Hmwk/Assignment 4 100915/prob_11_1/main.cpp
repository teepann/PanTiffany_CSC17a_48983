/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: October 1, 2015
 * Assignment: Problem 11.1 Movie Data
 * Directions: Write a program that uses a structure named MovieData to store 
 * the following information about a movie:
 * Title
 * Director
 * Year Released
 * Running Time (in minutes)
 * The program should create two MovieData variables, store values in their members,
 * and pass each one, in turn, to a function that displays the information about the movie
 * in a clearly formatted manner.
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//User Libraries
//structure of MovieData with its members
struct MovieData {
    string title; //title of movie
    string director; //name of director
    int year; //year released
    int runTime; //total run time in minutes    
};
//Global Constants

//Function Prototypes
void showMovie(MovieData *);
void inputData(MovieData *);

//Execution begins here
int main(int argc, char** argv) {
    //Variable declarations
    //create two MovieData pointers
    MovieData *movie1 = new MovieData;
    MovieData *movie2 = new MovieData;
    //input movie data
    inputData(movie1);
    inputData(movie2);
    //display movie data
    showMovie(movie1);
    showMovie(movie2);
    
    return 0;
}

/* 
 * Definition of function showMovie
 * parameter: pointer to MovieData
 * displays a movie on the console in a formatted output
 */
void showMovie(MovieData *movieData){
    cout << endl << "-------------------------\n";
    cout << "Movie Title: " << movieData->title << endl;
    cout << "Director: " << movieData->director << endl;
    cout << "Year Released: " << movieData->year << endl;
    cout << "Running Time: " << movieData->runTime << endl;
    cout << "-------------------------" << endl;
}

/* 
 * Definition of function inputData
 * parameter: pointer to MovieData
 * asks user for data about movie
 */
void inputData(MovieData *movieData){
    cout << "What is the title of the movie 1?";
    cin >> movieData->title;
    cout << "What is the director's name?";
    cin >> movieData->director;
    cout << "What year was the movie released?";
    cin >> movieData->year;
    cout << "How long is the movie?";
    cin >> movieData->runTime;
}
