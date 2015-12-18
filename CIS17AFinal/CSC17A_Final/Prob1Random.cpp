/* 
 * File:   Prob1Random.cpp
 * Author: Tiffany
 * 
 * Created on December 16, 2015, 10:18 PM
 */

#include "Prob1Random.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

Prob1Random::Prob1Random(const char n, const char* s) {
    nset = n;
    set = new char[n];
    for (int i = 0; i<n; i++){
        set[i]=s[i];
    }
    freq = new int[n];
    for (int i = 0; i<n; i++)
        freq[i]=0;
    numRand = 0;
    srand (time(NULL));
}

Prob1Random::~Prob1Random() {
}

void Prob1Random::randFromSet()
{    
    int index = rand()% 5;
    freq[index]++;
    numRand++;
}

int* Prob1Random::getFreq() const
{
    return freq;
}

char* Prob1Random::getSet() const
{
    return set;
}

int Prob1Random::getNumRand() const
{
    return numRand;
}



