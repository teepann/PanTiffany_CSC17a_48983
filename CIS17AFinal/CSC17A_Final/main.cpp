/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: December 10, 2015
 * CSC 17A Final
 */

//Library includes
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();

//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        case 7:    problem7();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=7);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type 7 for problem 7"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
    int inN;
    cin>>inN;
    return inN;
}

/* 
 * Definition of function.
 *
 */
void problem1(){
    cout<<"In problem # 1"<<endl<<endl;
}

/* 
 * Definition of function.
 *
 */
void problem2(){
    cout<<"In problem # 2"<<endl<<endl;
}

/* 
 * Definition of function.
 *
 */
void problem3(){
    cout<<"In problem # 3"<<endl<<endl;
}

/* 
 * Definition of function.
 *
 */
void problem4(){
    cout<<"In problem # 4"<<endl<<endl;
}

/* 
 * Definition of function.
 *
 */
void problem5(){
    cout<<"In problem # 5"<<endl<<endl;
}

/* 
 * Definition of function.
 *
 */
void problem6(){
    cout<<"In problem # 6"<<endl<<endl;
}

/* 
 * Definition of function.
 *
 */
void problem7(){
    cout<<"In problem # 6"<<endl<<endl;
}

void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}


