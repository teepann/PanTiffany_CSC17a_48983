/* 
 * File:   TestScores.h
 * Author: Tiffany
 *
 * Created on November 10, 2015, 11:42 AM
 */

#ifndef TESTSCORES_H
#define	TESTSCORES_H

class TestScores {
public:
    TestScores(int, int, int);
    TestScores(const TestScores& orig);
    virtual ~TestScores();
    void setT1(int);
    void setT2(int);
    void setT3(int);
    int getT1();
    int getT2();
    int getT3();
    float findAvgScore();
private:
    int test1;
    int test2;
    int test3;
};

#endif	/* TESTSCORES_H */

