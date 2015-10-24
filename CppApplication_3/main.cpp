/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: October 1, 2015
 * Midterm Project 2048
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

struct Tile {
    int value; //value of tile
};
struct Grid {
    Tile grid[4][4];    
};
struct Player {
    string name;
    int totalScore;
    int ranking; //for high scores list
};
struct Game {
    Grid grid;
    int score; //running total of score
};

//Function Prototypes
void displayGrid(Grid*);
void makeMove(Grid*);
void checkEndOfGame(Grid*);
void updateGrid(Grid*);
void spawn();
void refreshGrid();
void enterInfo(); 

//Execution begins here
int main(int argc, char** argv) {
    //Variable declarations
    
    Game game;
    
    play(&game);
     
    return 0;
}

/* 
 * Definition of function.
 *
 */
void play(Game* game)
{
    Grid grid = {{0}};
    Grid bGrid; //backup grid
    
    //loop for game
    while (1) 
    {
        //show grid output
        displayGrid(&grid, &game);
        //input character
        makeMove(&grid); 
        //check for game over
        if (checkEndOfGame(&grid))
            break;
        //update grid
        updateGrid(&grid);
        //spawn a new tile
        spawn();
        //refresh grid
        refreshGrid();
    }
    //User enters name, name and score are stored in file
    enterInfo();
}

void displayGrid(Grid *grid, Game *game) 
{
    system("clear");
    cout << "\n :: [  THE 2048 PUZZLE  ]:: \t\t\t\tDeveloped by Tiffany\n\n\t";
    if (plus)
    {
        cout << "+" << plus << "!";
    }
    else
    {
        cout << "   ";
    }
    
    cout<<"\t\t\t\t\t\tSCORE::"<<game->score<<" \n\n\n\n";
    
    for(int i = 0; i < 4; i++)
    {
        cout << "\t\t    |";
        for (int j = 0; j < 4; j++)
        {
            if (grid[i][j])
            {
                printf("%4d    |",grid[i][j]);
            }
            else
            {
                printf("%4c    |",' ');
            }            
        }
        cout << endl << endl;
    }
    cout << "\n\n Controls (+ :: o)\t\t\t\tu - undo\tr - restart\n\n\tW\t\t     ^\t\t\th - help\tq - quit\n\t\t\t\t\t\t\t\t"
            << " \n   A    S    D\t\t<    v    >\t\t\t     ."
            << " \n\t\t\t\t                             ";
}

void makeMove(Grid* grid)
{
    
}
void checkEndOfGame(Grid*);
void updateGrid(Grid*);
void spawn();
void refreshGrid();
void enterInfo(); 