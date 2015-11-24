/* 
 * File:   Numbers.cpp
 * Author: Tiffany
 * 
 * Created on November 23, 2015, 11:41 PM
 */

#include "Numbers.h"

Numbers::Numbers() {
    number = 0;
}

Numbers::Numbers(const Numbers& orig) {
}

Numbers::~Numbers() {
}

void Numbers::setNum(int n)
{
    number = n;
}

int Numbers::getNum()
{
    return number;
}

int Numbers::calcVal()
{
    string result;
    ostringstream convert;
    convert << number;
    result = convert.str();
    return(result.length());	
}

void Numbers::printRes(int l)
{
    string lessThan20[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
		"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty" };
    string to100[] = { "not", "not", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
    if (number == 0)
    {
    	cout << "Zero" << endl;
    }
    if (number > 999)
    {
    	cout << lessThan20[(number / 1000)-1] << " thousand ";
    }
    if (number > 99)
    {
        cout << lessThan20 [(number % 1000 / 100)-1] << " hundred "; 
    }
    if ((number % 100 ) > 20)
    {
    	cout << to100[(number % 100 / 10)] << " " << lessThan20[(number % 10)-1];
    }
    else if (number % 100 / 10 < 20)
    {
        cout << lessThan20[(number % 100)-1];
    }
}
