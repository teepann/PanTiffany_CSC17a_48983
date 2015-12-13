/* 
 * File:   Player.h
 * Author: Tiffany
 * Final Project 2048
 * Created on December 5, 2015, 1:26 PM
 */

#ifndef PLAYER_H
#define	PLAYER_H

using namespace std;

class Player {
public:
    Player();
    Player(const Player& orig);
    virtual ~Player();
    void setName(char*);
    void setScore(int);
    char* getName();
    int getScore();
    
private:
    char* name;
    int pscore;
};

#endif	/* PLAYER_H */

