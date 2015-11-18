/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: October 30, 2015
 * Assignment: Midterm
 */

//System Libraries
#include <iostream>
#include <math.h>
using namespace std;

//Customer structure
struct Customer {
    int accNum=0;
    int deposit = 0;
    int checks = 0;
    int depTot = 0;
    int checkTot = 0;
    int Total = 0;

};
//employee struct
struct Employee
{
    string name;
    int hours=0; 
    float rate=0;
    float iTot= 0; //individual total
};

//statsResult structure
struct statsResult
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};
//Prime structure
struct Prime {
    unsigned int prime;
    unsigned int power; 
};
//Primes structure
struct Primes{
    Prime *prime;
    unsigned int nPrimes; 
};


//Function Prototypes
void decrypt(int num);

statsResult *avgMedMode(int *,int); 
void printStat(statsResult*);
void sort(int *array, int size);

Primes *factor(int); //inputs integer, returns all prime factors
void prntPrm(Primes *); //output all prime factors

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

//Execution begins here
int main(int argc, char** argv) {
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
    } while(inN>=1&&inN<=7);
    return 0;
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

//customer account balance
void problem1(){
    const int size = 40;
    cout<<"In problem # 1"<<endl<<endl;
    
    char answer;
    Customer *ptr,c;
    ptr = &c;	
    int test=0;
        
    cout << "Please enter your five digit account number: ";
    cin >> ptr->accNum;
			
    while (ptr->accNum < 10000 || ptr->accNum >99999)
    {
        cout << "Error, please enter a valid FIVE digit account number: ";
        cin >> ptr->accNum;
    }		
    do
    {
        cout << "Please enter the amount(s) for your deposits: $";
        cin >> ptr->deposit; // continue converting the rest to pointers 
        while (ptr->deposit < 0)
        {
            cout << "Error, you cant deposit a negative amount of money." << endl;
            cout << "Please enter the amount for your deposits: $" << endl;
            cin >> ptr->deposit;
        }

        ptr->depTot += ptr->deposit;

        cout << "Are you done depositing? Type (Y) or (N)" << endl;
        cin >> answer;
		
    }while(!(answer == 'y'|| answer == 'Y'));

    do
    {
        cout << "Please enter the amount(s) for your checks: $";
        cin >> ptr->checks;

        while (ptr->checks < 0)
        {
            cout << "Error, you cant checks a negative amount of money." << endl;
            cout << "Please enter the amount for your checks: $" << endl;
            cin >> ptr->checks;
        }

        ptr->checkTot += ptr->checks;

        cout << "Are you done with your checks? Type (Y) or (N)" << endl;
        cin >> answer;
    } while (!(answer == 'y' || answer == 'Y'));
    
    cout << "Total for checks is : $" << ptr->checkTot << endl;

    cout << "Total for deposits is : $" << ptr->depTot << endl;

    ptr->Total = ptr->depTot - ptr->checkTot;

    if (ptr->depTot < ptr->checkTot)
    {		
        cout << "A $15 fee will be added to your balance for overspending." << endl;

        cout << "Balance before the $15 fee is : " << ptr->Total << " " << endl <<endl;
        ptr->Total = ptr->Total - 15; // $15 fee for overdrawing money; 
        cout << "Your new balance is : " << ptr->Total << "  " << endl << endl;
    }
    else
    {
        cout << "Your total balance is : $" << ptr->Total << endl << endl;
    }
}

//gross pay
void problem2(){
    cout<<"In problem # 2"<<endl<<endl;
    const int size = 40;
    int empNum = 0;

    float grossPay=0;
    Employee emp[size];
        
    cout << "Please enter the total number of employees: ";
    cin >> empNum;
	
    for (int i = 0; i < empNum; i++)
    {
        cin.ignore();
	cout << "Please enter the name of Employee #" << i +1 << " : " ;		
	getline(cin, emp[i].name);		

	cout << "Please enter the hours you worked: ";
	cin >> emp[i].hours;

	while (emp[i].hours < 0)
        {
            cout << "Error, Please enter a valid number of hours"<< endl;
            cin >> emp[i].hours;
        }

        cout << "Please enter your rate of pay: ";
	cin >> emp[i].rate;

        while (emp[i].hours <= 0)
	{
            cout << "Error, Please enter a valid rate of pay" << endl;
            cin >> emp[i].hours;
        }

	if (emp[i].hours < 40) //straight
        {
            emp[i].iTot = (emp[i].hours) *emp[i].rate;
      	}
            if (emp[i].hours > 40 && emp[i].hours < 50) //doubles the time
	{
            emp[i].iTot = (2 * emp[i].hours) * emp[i].rate;
	}
	if (emp[i].hours > 50) // triple time above 50 hours
	{
            emp[i].iTot = (3 * emp[i].hours) * emp[i].rate;
        }		
        
	grossPay += emp[i].iTot;
	cout << endl;		
    }
    
    cout << "The Gross Pay for the company is :" << grossPay << endl << endl;
}

//mode, median, mean
void problem3(){
    cout<<"In problem # 3"<<endl<<endl;
    
    /*TEST HERE!*/
    int size=21;
    int numbers[size];
    for(int i=0; i<size; i++){
        numbers[i]=i%5;
    }
    //prints out the array of ints
    for (int i = 0; i < size; i++)
        cout << numbers[i] << " ";
    
    statsResult *x=avgMedMode(numbers,size);
    printStat(x);
    delete []x->mode;
    delete x;
}

statsResult *avgMedMode(int* numbers,int size)
{
    statsResult *stats = new statsResult();
    int maxFreq = 0; 
    int numModes = 0;
    int freq = 1;
    int currentElement;
    stats->mode = new int[size];
    sort(numbers,size);
    
    //find the maximum frequency:
    for(int i = 0; i< size; i++){
        currentElement= numbers[i]; //set currentElement to the ith element in numbers
        int j=i+1; //check if the next element in numbers is the same as currentElement
        while (numbers[j]== currentElement){ //if it is, then continue checking and add a count to the frequency
            freq++;
            j++;
        }
        i= j-1;//skip the next elements that are the same values
        if(freq> 1 && freq> maxFreq){ //set max frequency
            maxFreq= freq;
        }
        freq= 1;//reset freq to 1
    }
    stats->maxFreq = maxFreq;
    
    //find number of modes:
    for(int i = 0; i<size; i++){
        currentElement= numbers[i];
        int j=i+1;
        while(numbers[j]==currentElement){
            freq++;
            j++;
        }
        i= j-1;
        if(freq>1 && freq==maxFreq){  //if frequency of currentElement is same as the maxFreq
            numModes++; 
        }
        freq=1;//reset frequency counter to 1
    }
    stats->nModes = numModes;
    
    int index=0;
    for (int i = 0; i< size; i++)
    {
        currentElement = numbers[i];
        int j = i+1;
        while(numbers[j]==currentElement){
            freq++;
            j++;
        }
        i= j-1;
        if(freq>1 && freq==maxFreq){  //if frequency of currentElement is same as the maxFreq            
            stats->mode[index]=numbers[i]; //add that currentElement to modeArray                  
            index++;
        }
        freq=1;//reset frequency counter to 1
    }
    
    //find mean
    float sum = 0.0;
    for(int i = 0; i< size; i++){
        //sum of all numbers in the array
        sum+=numbers[i];
    }
    stats->avg = sum/size; //returns average 
    
    //find median
    if (size%2==0) //if there's an even number of elements
        //return average of the middle two numbers
        stats->median = (float)(numbers[size/2] + numbers[size/2 + 1])/2;
    else  //if there's an odd number of elements
        //return the middle number
        stats->median = numbers[size/2 + 1];  
}

void printStat(statsResult* stats)
{
    if(stats->nModes == 0){ //if numModes =0, there is no mode
        cout<<"This data set has no modes\n";
    }
    else { 
        cout<<"There are "<< stats->nModes <<" mode(s)."<<endl; //print out number of modes
        cout<<"Each mode appears "<<stats->maxFreq<<" times."<<endl; //print out the max frequency
        cout<<"The mode(s) are: "; //print out the modes
        for(int i = 0; i<stats->nModes; i++){
            cout<<stats->mode[i]<<" ";
        }
        cout<<endl;
        cout<<"The mean is: "<<stats->avg<<endl;
        cout<<"The median is: "<<stats->median<<endl;
    }
}

//function definition of sort- selection sort
void sort(int *array, int size)
{
    int startScan, minIndex, minValue;
    for (startScan =0; startScan < (size -1); startScan++){
        minIndex = startScan; 
        minValue = array[startScan];
        for(int index= startScan + 1; index < size; index++){
            if (array[index] < minValue){
                minValue = array[index];
                minIndex = index;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan]=minValue;
    }
    
}
/* 
 * Definition of function
 * 4 digit integer, only number 0-7,
 * input dialog: 4 digit int
 * encryption: add 5 to each digit
 * mod by 8
 * swap 1st with 2nd, 3rd with 4th
 * print out int
 * decrypt it
 */
void problem4(){
    cout<<"In problem # 4"<<endl<<endl;
    int encryptedNum;
    int digit;
    int temp;
    int original;
    bool isEncryptable=true; //4 digits and uses only 0-7
    do {
        isEncryptable = true;
        cout << "Please enter a four digit number that uses digits between 0 and 7 inclusive" << endl;
        cin >> original;        
        temp = original;
        for (int i = 1; i <= 4; i++){
            digit = temp % 10;
            if (digit >= 8){
                isEncryptable = false;
                break;
            }            
            if ((i == 4 && temp >= 10) ||(i < 4 && temp < 10))
                isEncryptable = false;
            temp /= 10;
        }
    } while (!isEncryptable);
       
    temp = original;
    int placeValue = 0;
    while(placeValue < 5){
            digit = temp % 10;
            digit += 5;
            digit %= 8;
            if (placeValue == 0)
                encryptedNum += digit*pow(10,1);
            else if (placeValue == 1)
                encryptedNum += digit-4;
            else if (placeValue ==2)
                encryptedNum += digit*pow(10,3);
             else if (placeValue ==3)
                encryptedNum += digit*pow(10,2);
            temp /= 10;
            placeValue++;
        }
    cout << original << " is encrypted into: " << encryptedNum << endl;
    decrypt (encryptedNum);
}

void decrypt(int num){
    int encryptedNum = num;
    int decryptedNum;
    int digit;
    int placeValue = 0;
    while(encryptedNum > 0){
            digit = encryptedNum % 10;
            digit -= 5;
            if (digit < 0)
                digit += 8;
            if (placeValue == 0)
                decryptedNum += digit*pow(10,1);
            else if (placeValue == 1)
                decryptedNum += digit*pow(10,0);
            else if (placeValue == 2)
                decryptedNum += digit*pow(10,3);
             else if (placeValue == 3)
                decryptedNum += digit*pow(10,2);
            encryptedNum /= 10;
            placeValue++;
        }
    cout << encryptedNum << " is decrypted into: " << decryptedNum << endl;
}

//test factorials of different data types
void problem5(){
    cout<<"In problem # 5"<<endl<<endl;
    
    cout << "Factorial Testing " << endl;
    cout << "Signed Data Types: " << endl;
    cout << "SHORT:" << endl;
    cout << "The largest for an int: 16 " << endl;	
    cout << "The largest for a float: 34 " << endl;
    cout << "The largest for a double: 170 " << endl;
    cout << "The largest for a long: 16" << endl;
    cout << "The largest for a short: 7 " << endl;
    cout << "UNSIGNED: " << endl;	
    cout << "The largest for an int: 32 " << endl;	
    cout << "The largest for a short: 8 " << endl;
    cout << "Others remained the same." << endl;
}

//converting 
void problem6(){
    cout<<"In problem # 6"<<endl<<endl;
    cout << "2.125 in binary: 10.001, oct: 2.1, hex: 2.2" << endl;
    cout << "0.06640625 in binary: .00010001, oct: .072, hex: .11" << endl;
    cout << "-2.125 in float representation: 44000002" << endl;
    cout << "0.06640625 in float representation: 4400000D" << endl;
    cout << "46666601 in decimal: 1.09999991" << endl;
    cout << "46666602 in decimal: 2.19999981" << endl;
    cout << "B9999AFE in decimal: -0.58750045 " << endl; 
 }

//prime factorization
void problem7(){
    cout<<"In problem # 7"<<endl<<endl;
    int number;
    do {
        cout << "enter a number between 2 and 10000 inclusive: ";
        cin >> number;
    } while(number<2 || number>10000);
    
    Primes *x=factor(number);
    x = factor(number);
    cout << number << " = ";
    prntPrm(x);
    delete []x->prime;
    delete x;
}

void prntPrm(Primes *test){
    for (int i = 0; i< test->nPrimes; i++)
    {
        cout << test->prime[i].prime << "^" << test->prime[i].power;
        if (i<test->nPrimes-1)
            cout<< "*";        
    }
}

Primes *factor(int number){
    Primes *test = new Primes();
    test->prime = new Prime[100];
     
    int index = 0;
    int power = 0;
    if (number%2 == 0){        
            test->prime[index].prime = 2;              
            do {           
                number /=2;
                power++;
            }  while (number%2 == 0);
            test->prime[index].power = power;  
            index++;
        }   
    
    for (int i = 3; i <= sqrt(number); i = i + 2){
        power = 0;
        if (number%i == 0){
            test->prime[index].prime = i; 
            do {           
                number /=i;
                power++;
            }  while (number%i == 0);
            test->prime[index].power = power;
            index++;
        }
    }    
    index--;
    if (number > 2){
        index++;
        test->prime[index].prime = number;
        test->prime[index].power = 1;
    } 
    
    test->nPrimes = index + 1;
    return test;
}

void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}
