/* 
 * File:   Game.h
 * Author: Tiffany
 * Final Project 2048
 * Created on December 5, 2015, 1:26 PM
 */

#ifndef GAME_H
#define	GAME_H
#include "Grid.h"
#include "Player.h"
#include <iostream>
#include <vector>

using namespace std;

class Game : public Grid, public Player {
public:
    Game();
    Game(const Game& orig);
    virtual ~Game();
    
    void displayGrid();
    void displayHelpScreen();
    void displayWinScreen();
    void displayLoserScreen();
    char displayTryAgainScreen(int);
    void savePlayerInfo();
    void logic();
    void checkGameOver();
    
    void backupGrid();
    void undo();
    void setWinValue(int);
    int getWinValue();
    
    bool response; //response to quit by user
    char option; //option input by user
    
private:
    Player player; //player object
    vector<Player> list; //list of players
    static int winValue; //value of tile to win
};

#endif	/* GAME_H */

