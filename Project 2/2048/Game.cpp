/* 
 * File:   Game.cpp
 * Author: Tiffany
 * Final Project 2048
 * Created on December 5, 2015, 1:26 PM
 */

#include "Game.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>

Game::Game() {
    response = true;
    tileDestroyed = false;
    initializeGrid();
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}

/* Definition for function logic
 * goes through one loop of the game
 * depending on user input
 */
void Game::logic()
{
    switch (control)
    {		
	case 'w':
	case 'a':
	case 's':
	case 'd':
            //if user inputs any of the four directions (w,a,s,d)
            //make a backupgrid, update grid, check for maxTile, display grid
            backupGrid();
            fillSpace();
            updateGrid();
            fillSpace();
            findGreatestTile();
            displayGrid();
            player.setScore(score);
            //check if full
            if (full() && tileDestroyed)
            {
                response = false;
                break;
            }
            else if (blockMoved())
            {
                spawn();
                break;
            }
            else
            {
                response = true;
                break;
            }
            
	//undo
	case 'u': 
            if (blockMoved())
                score -= scoreRound;
            //player.setScore(score);
            undo();
            break;
	//restart
	case 'r':
            initializeGrid();
            score = 0;
            scoreRound = 0;
            break;
	//quit
	case 'q':
            response = false;
            break;
	//help
	case 'h':
            displayHelpScreen();
            cout << "Press a letter and enter to continue";
            char cont;
            cin >> cont;
            displayGrid();
            break;
	}
    
}

/* definition of function checkGameOver
 * checks if maxTile has reached a multiple of 2048
 * if the user quit
 * or if the grid is full 
 */
void Game::checkGameOver()
{
    if (maxTile == getWinValue())
    {
        displayWinScreen();

        if (displayTryAgainScreen(0) == 'n')
            response = false;
        else
            setWinValue(getWinValue()*2);
    }

    else if (response == false)
    {
        displayLoserScreen();

        if (displayTryAgainScreen(1) == 'y')
        {
            initializeGrid();
            response = true;
        }
    }

    if (response == false)
    {
        cout << "\n\n\t\t            > Thank you for playing. ";
        exit(0);
    }
}

/* definition of class Game function displayGrid
 * displays the formatted output screen of grid
 */
void Game::displayGrid()
{
    cout << "\n  ::[  THE 2048 PUZZLE  ]::\n\n\t";

    if (scoreRound)
        cout << "+" << scoreRound << "!";
    else
        cout << "   ";

    cout << "\t\t\t\t\t\tSCORE::" << score << " \n\n\n\n";

    for (int i = 0; i<4; i++)
    {
        cout << "\t\t     |";

        for (int j = 0; j<4; j++)
        {
            if (!grid[i][j].isEmpty())
                printf("%4d    |", grid[i][j].getValue());
            else
                printf("%4c    |", ' ');
        }
        cout << endl << endl;
    }

    cout << "\n\n Controls (+ :: o)\t\t\t\tu - undo\tr - restart\n\n\tW\t\t     ^"
            << "\t\t\th - help\tq - quit\n\t\t\t\t\t\t\t\t"
            << " \n   A    S    D\t\t<    v    >\t\t\t     ."
            << " \n\t\t\t\t                             ";
}

/* Definition of Game class function displayHelpScreen
 * opens directions.txt and reads the strings from it
 */
void Game::displayHelpScreen()
{
    string str;
    ifstream openFile;
    
    openFile.exceptions(ios::failbit);
    try {
        openFile.open("directions.txt", ios::in);
    } catch (ios_base::failure &fail){
        cout << "Failure to open directions file";        
    }
    // disable exceptions again as we use the boolean conversion interface 
    openFile.exceptions(ios::goodbit);

    while (openFile >> str)
    {
        cout << str << " ";
    }

    cout << endl << endl;
    openFile.close();
}

/* definition of Game class function displayWinScreen
 * displays formatted output to screen
 */
void Game::displayWinScreen()
{
    cout << endl << endl;
    cout << "\n\t\t\t  :: [  YOU MADE " << getWinValue() << "!  ] ::"
            << "\n\n\t\t\t  :: [ YOU WON THE GAME ] ::"
            << "\n\n\n\n\t\t\t TILE\t     SCORE\t    NAME";
    printf("\n\n\t\t\t %4d\t    %6d\t    ", maxTile, score);
    char* n;
    cin >> n;
    player.setName(n);
    savePlayerInfo();

    cout << "\n\n\t\t> The maximum possible tile is 65,536 ! So go on :)";
}

/* definition of Game class function displayLoserScreen
* displays formatted output to screen
*/
void Game::displayLoserScreen()
{
    cout << "\n\n\n\t\t\t  :: [ G A M E  O V E R ] ::"
            << "\n\n\n\n\t\t\t TILE\t     SCORE\t    NAME";
    printf("\n\n\t\t\t %4d\t    %6d\t    ", maxTile, score);
    char* n;
    cin >> n;
    player.setName(n);
    savePlayerInfo();

    cout << "\n\n\t\t> The maximum possible score is 3,932,156 ! So close :p";
}

/* definition of Game class function displayTryAgainScreen
* displays formatted output to screen
* prompts user if they want to play again
*/
char Game::displayTryAgainScreen(int lose)
{
    if (lose)
        cout << "\n\n\n\t    > Would you like to try again " << player.getName() << " (y/n) ? :: ";
    else
        cout << "\n\n\n\t    > Would you like to continue playing " << player.getName() << " (y/n) ? :: ";

    cin >> option;

    return option;
}

/* definition for Game class function savePlayerInfo
 * writes to file the player's information
 */
void Game::savePlayerInfo()
{
    ofstream file;
    file.open("players.txt", ios::app);
    file << player.getName() << " " << player.getScore() << endl;
    file.close();
}

/* Definition of Grid class function backupGrid
 * creates a backup grid based on current grid
 */
void Game::backupGrid()
{
    for (int i = 0; i<4; i++)
        for (int j = 0; j<4; j++)
            bGrid[i][j] = grid[i][j];
}

/* definition of Grid class function undo
* sets current grid to backup grid
*/
void Game::undo()
{
    for (int i = 0; i<4; i++)
        for (int j = 0; j<4; j++)
            grid[i][j] = bGrid[i][j];
}

void Game::setWinValue(int w)
{
    winValue = w;
}

int Game::getWinValue()
{
    return winValue;
}