/* 
 * File:   TestScores.cpp
 * Author: Tiffany Pan
 * 
 * Created on November 10, 2015, 11:42 AM
 */

#include "TestScores.h"

TestScores::TestScores(int t1, int t2, int t3) {
    test1 = t1;
    test2 = t2;
    test3 = t3;
}

TestScores::TestScores(const TestScores& orig) {
}

TestScores::~TestScores() {
}

/*Setters*/
void TestScores::setT1(int t1){
    test1 = t1;
}

void TestScores::setT2(int t2){
    test2 = t2;
}

void TestScores::setT3(int t3){
    test3 = t3;
}

/*Getters*/
int TestScores::getT1(){
    return test1;
}

int TestScores::getT2(){
    return test2;
}

int TestScores::getT3(){
    return test3;
}

/* 
 * Definition of function findAvgScore
 * Takes the average of the three test scores
 * returns a float
 */
float TestScores::findAvgScore(){
    return (float)(test1 + test2 + test3)/3;
}


