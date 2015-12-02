/* 
 * File:   Essay.cpp
 * Author: Tiffany
 * 
 * Created on December 1, 2015, 8:19 PM
 */

#include "Essay.h"
#include <iostream>
using namespace std;

Essay::Essay() {
}

Essay::Essay(const Essay& orig) {
}

Essay::~Essay() {
}

void Essay::determineScore()
{
    int counter;
    cout << "Please enter points for grammar (up to 30): ";
    cin >> counter;
    score = counter;
    cout << "Please enter points for spelling (up to 20): ";
    cin >> counter;
    score += counter;
    cout << "Please enter points for correct length (up to 20): ";
    cin >> counter;
    score += counter;
    cout << "Please enter points for content (up to 30): ";
    cin >> counter;
    score += counter;
}

