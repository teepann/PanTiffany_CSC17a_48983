/* 
 * File:   Player.cpp
 * Author: Tiffany
 * Final Project 2048
 * Created on December 5, 2015, 1:26 PM
 */

#include "Player.h"

Player::Player() {
    name = "player";
    pscore = 0;
}

Player::Player(const Player& orig) {
    //copy constructor
    name = orig.name;
    pscore = orig.pscore;
}

Player::~Player() {
}

char* Player::getName()
{
    return name;
}

void Player::setName(char* n)
{
    name = n;
}

void Player::setScore(int s)
{
    pscore = s;
}

int Player::getScore()
{
    return pscore;
}
