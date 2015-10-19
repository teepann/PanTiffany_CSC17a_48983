/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: October 1, 2015
 * Assignment: Problem 11.10 Search Function for the Speakers’ Bureau Program
 * Directions: Add a function to Programming Challenge 9 that allows the user to 
 * search for a speaker on a particular topic. It should accept a key word as an 
 * argument and then search the array for a structure with that key word in the 
 * Speaking Topic field. All structures that match should be displayed. If no 
 * structure matches, a message saying so should be displayed.
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//User Libraries

//structure of Speaker
struct Speaker{
    string name; //name of speaker
    string phone; //telephone number
    string topic; //speaking topic
    float fee; //fee required
};
//Global Constants

//Function Prototypes
void inputSpeakerData(Speaker *);
void showSpeakerData(Speaker **, const int);
void searchSpeaker(Speaker** , string, const int);

//Execution begins here
int main(int argc, char** argv) {
    //Variable declarations
    const int NUM_SPEAKERS = 10; //number of speakers
    Speaker *speakers[NUM_SPEAKERS]; //array of speakers
    
    int option; //user's choice
    //input data for each speaker
    for (int i = 0; i< NUM_SPEAKERS; i++){
        cout << "\nPlease enter data for speaker #" << i+1 << endl;
        speakers[i] = new Speaker;
        inputSpeakerData(speakers[i]);
    }
    //menu for speakers' bureau
    do{
        cout<< endl;
        cout<< "Speakers' Bureau Menu\n Please choose one of the following options" << endl;
        cout << "1. Show data of all speakers" << endl;
        cout << "2. Edit data" << endl;
        cout << "3. Search speakers by topic." << endl;
        cout << "4. Exit." << endl;
        cin >> option;
        
        switch (option){
            //displays all speakers and their data
            case 1: {
                showSpeakerData(speakers, NUM_SPEAKERS);
                break;
            }
            //edit speaker
            case 2: {
                cout << "Please enter speaker # you want to edit, type -1 to stop.";
                cin >> option;
                cin.ignore();
                cin.clear();
                
                if (option <=0 || option > NUM_SPEAKERS){
                    option = -1;
                } else {
                    cout << "Editing speaker #" << option << endl;
                    inputSpeakerData(speakers[option-1]);
                }
                break;
            }
            case 3: {
                string keyword;
                cout << "Please enter keyword: ";
                cin >> keyword;
                searchSpeaker(speakers, keyword, NUM_SPEAKERS);
            }
            //otherwise, exit
            default: {
                option = -1;
                break;
            }
        }
    } while (option != -1);    
    
    return 0;
}

/* 
 * Definition of function inputSpeakerData
 * parameter: pointer to a Speaker
 * prompts user for speaker data and stores information
 */
void inputSpeakerData(Speaker* speaker) {
    cout << "Please enter speaker's name: ";
    getline(cin, speaker->name);
    
    cout << "Please enter the speaker's telephone number: ";
    getline(cin, speaker->phone);
    
    cout << "Please enter the speaker's speaking topic: ";
    getline(cin, speaker->topic);
    
    //input validation for a positive value
    do {
        cout << "Please enter a required fee (must be positive): ";
        cin >> speaker->fee;        
    } while (speaker->fee < 0);  
}

/* 
 * Definition of function showSpeakerData
 * parameter: pointer to a Speaker and number of speakers
 * displays speaker data for all speakers
 */
void showSpeakerData(Speaker** speaker, const int numSpeakers) {
    for (int i = 0; i < numSpeakers; i++) {
        cout << "------------------------------------\n";
        cout << "Speaker # " << i + 1 << endl;
        cout << "Speaker's name: " << speaker[i]->name << endl;
        cout << "Telephone number: " << speaker[i]->phone << endl;
        cout << "Speaking topic: " << speaker[i]->topic << endl;
        cout << "Required fee: " << speaker[i]->fee << endl;
        cout << "------------------------------------\n";
    }
}

/* 
 * Definition of function searchSpeaker
 * parameter: topic keyword, pointer to speakers, and number of speakers
 * returns speakers that have that keyword as their topic
 */
void searchSpeaker(Speaker** speakers, string keyword, const int numSpeakers){
    for (int i = 0; i< numSpeakers; i++ ){
        if(speakers[i]->topic.compare(keyword) == 0){
            cout << speakers[i]->name << endl;
        }
    }
}