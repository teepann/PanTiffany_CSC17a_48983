/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: December 10, 2015
 * Project 2: 2048
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries
#include "Game.h"

int Game::winValue = 2048;

//Execution begins here
int main(int argc, char** argv) {
    //Variable declarations
    Game *game = new Game(); //a Game object
    char choice;
    
    //loop for game
    while (1)
    {
	game->displayGrid();
	//test for computer to play the game itself
	//char keys[] = "wasd";
	//exec.control = keys[rand() % 4 + 0];
	//get input
	cin >> choice;
	game->control = tolower(choice);
	game->logic();
	game->checkGameOver();
    };

    return 0;
}
