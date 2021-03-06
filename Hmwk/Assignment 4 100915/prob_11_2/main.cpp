/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: October 1, 2015
 * Assignment: Problem 11.2 Movie Profit
 * Directions: Modify the Movie Data program written for Programming Challenge 1 
 * to include two additional members that hold the movie’s production costs and 
 * first-year revenues. Modify the function that displays the movie data to 
 * display the title, director, release year, running time, and first year’s profit or loss.
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries
//structure of MovieData with its members
struct MovieData {
    string title; //title of movie
    string director; //name of director
    int year; //year released
    int runTime; //total run time in minutes    
    float cost; //movie production cost
    float revenue; //first-year revenue
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
    //input movie data by user
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
    cout << fixed << showpoint << setprecision(2);
    if (movieData->cost < movieData->revenue) {
        cout << "The first year's profit is: " << movieData->revenue - movieData->cost << endl;
    } else {
        cout << "The first year's loss is: " << movieData->cost - movieData->revenue << endl;
    }
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
    cout << "How much was the production cost?";
    cin >> movieData->cost;
    cout << "How much was the first year revenue?";
    cin >> movieData->revenue;
}
