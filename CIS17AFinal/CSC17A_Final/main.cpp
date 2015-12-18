/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: December 10, 2015
 * CSC 17A Final
 */

//Library includes
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Prob1Random.h"
#include "Prob2Sort.h"
#include "Prob3Table.h"
#include "Prob3TableInherited.h"
#include "Employee.h"
#include "SavingsAccount.h"

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
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
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
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
    int inN;
    cin>>inN;
    return inN;
}

/* 
 * Problem 1
 * Create a class that returns a random number from the following set,
 * {16,34,57,79,127}.  Loop 100,000 times with this 
 * procedure and print the frequency of each of the 
 * 5 numbers obtained.
 */
void problem1(){
    cout<<"In problem # 1"<<endl<<endl;
    char n=5;
    char rndseq[]={16,34,57,79,127};
    int ntimes=100000;
    Prob1Random a(n,rndseq);
    for(int i=1;i<=ntimes;i++){
        a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++){
        cout<<int(y[i])<<" occurred "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}

/* 
 * Problem 2
 * Sort a single column array and/or sort a 2 dimensional array 
 * of characters given any column.  
 */
void problem2(){
    cout<<"The start of Problem 2, the sorting problem"<<endl;
	Prob2Sort<char> rc;
	bool ascending=true;
	ifstream infile;
	infile.open("Problem2.txt",ios::in);
	char *ch2=new char[10*16];
	char *ch2p=ch2;
	while(infile.get(*ch2)){cout<<*ch2;ch2++;}
	infile.close();
	cout<<endl;
	cout<<"Sorting on which column"<<endl;
	int column;
	cin>>column;
	char *zc=rc.sortArray(ch2p,10,16,column,ascending);
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<16;j++)
		{
			cout<<zc[i*16+j];
		}
	}
	delete []zc;
	cout<<endl;
}

/* 
 * Problem 3
 * Spreadsheet stuff
 */
void problem3(){
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
    const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<naugT[i*cols+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++)
    {
        for(int j=0;j<=cols;j++)
        {
            cout<<augT[i*(cols+1)+j]<<" ";
        }
        cout<<endl;
    }
}

/* 
 * problem 4
 * Savings account class
 */
void problem4(){
    cout<<"In problem # 4"<<endl<<endl;
    SavingsAccount mine(-300);

    for(int i=1;i<=10;i++)
    {
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.Total((float)(0.10),7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.TotalRecursive((float)(0.10),7)
        <<" Recursive Calculation "<<endl;
}

/* 
 * Problem 5
 * Employee class
 */
void problem5(){
     Employee Mark("Mark","Boss",215.50);
   Mark.setHoursWorked(-3);
   Mark.toString();
   Mark.CalculatePay(Mark.setHourlyRate(20.0),
                     Mark.setHoursWorked(25));
   Mark.toString();
   Mark.CalculatePay(Mark.setHourlyRate(40.0),
                     Mark.setHoursWorked(25));
   Mark.toString();
   Mark.CalculatePay(Mark.setHourlyRate(60.0),
                     Mark.setHoursWorked(25));
   Mark.toString();
   Employee Mary("Mary","VP",50.0);
   Mary.toString();
   Mary.CalculatePay(Mary.setHourlyRate(50.0),
                     Mary.setHoursWorked(40));
   Mary.toString();
   Mary.CalculatePay(Mary.setHourlyRate(50.0),
                     Mary.setHoursWorked(50));
   Mary.toString();
   Mary.CalculatePay(Mary.setHourlyRate(50.0),
                     Mary.setHoursWorked(60));
   Mary.toString();
}

/* 
 * Problem 6
 * Conversions
 * Given the following base 10 decimals
a)0.125
b)0.3
c)89.3
Convert to binary, octal and hex, then 
Convert to Hex float with first 24 bits representing the
signed fraction and the last 8 bits representing the
exponent.
 */
void problem6(){
    cout<<"In problem # 6"<<endl<<endl;
    cout <<"a) 0.125" <<endl
            <<"Binary: " <<0.001 <<endl
            <<"Octal: " <<0.1 <<endl
            <<"Hex: " << 0.2 <<endl <<endl;
    
    cout <<"b) 0.3" <<endl
            <<"Binary: " <<"0.01001" <<endl
            <<"Octal: " <<"0.2314" <<endl
            <<"Hex: " <<"0.4CC" <<endl <<endl;
    
    cout <<"c) 89.3" <<endl
            <<"Binary: " <<"1011001.01001" <<endl
            <<"Octal: " <<"131.2314" <<endl
            <<"Hex: " <<"59.4CC" <<endl <<endl;
}

void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}


