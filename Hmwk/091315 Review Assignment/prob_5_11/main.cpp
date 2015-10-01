/* 
 * prob_5_11.cpp 
 * Author: Tiffany Pan
 * Created on September 8, 2015, 3:44 PM
 * Purpose: predict size of a population given initial number, avg daily increase, and number of days
 * Homework: Complete problem 5.11
 */

//System Libraries
#include <iostream> //input/output stream Library
#include <iomanip> //format Library
using namespace std; //utilize standard name-space directly

//User Libraries

//Global Constants

//Function Prototypes 

/*
 * Population increase
 */
int main(int argc, char** argv) {
    int numOrganisms, numDays, population;
    float avgInc;
    
    //ask user for starting number of organisms
    do{cout<<"How many organisms to start?"<<endl;
    cin>>numOrganisms;
    }while(numOrganisms<2);
    population=numOrganisms;
    //ask user for average daily population increase in percentage non negative
    do{cout<<"Average daily population increase percentage?"<<endl;
    cin>>avgInc;
    }while(avgInc<0);
    //ask user for number of days they will multiply that is greater than 1
    do{cout<<"How many days will they multiply?"<<endl;
    cin>>numDays;
    }while(numDays<1);
    
    //loop that displays the day and the size of the population for each day
    for(int i=0;i<=numDays;i++)
    {
        cout<<"Day "<<i<<": "<<population<<endl;
        population+=population*avgInc/100;
    }
    return 0;
}

