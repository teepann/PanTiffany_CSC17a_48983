/*
 * File: main.cpp
 * Author: Tiffany Pan
 * Date: October 15, 2015
 * Project: 2048
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

//int pressEnter;
//int randomIndex(int);

//GameAI structure
struct GameAI {
    int response;
    int destroy;
    char control;
    
    int max;
    int win;
    int plus;
    int score;
    int grid[4][4];
    int bgrid[4][4];
    
    GameAI(): score(0), plus(0),win(2048), max(0),response(0),destroy(1) {}
    void logicFlow(Game*);
    void gameEndCheck(Game*);
    void keyPress();
    void startGrid();
    void updateGrid();
    void fillSpace();
    void spawn();
    void findGreatestTile();
    void backupGrid();
    void undo();
    
    int full();
    int blockMoves();    
};

//Game structure
struct Game : GameAI {
    char option;
    string name;
    
    void displayGrid();
    void displayHelpScreen();
    void displayWinScreen();
    void displayLoserScreen();
    char displayTryAgainScreen(int);
};
//Function Prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    Game exec;
    srand(time(NULL));
    exec.startGrid();
    
    while(1)
    {
        exec.displayGrid();
        exec.keyPress();
        exec.logicFlow();
        exec.gameEndCheck(&exec);
    }
    return 0;
}

/* 
 * Definition of function.
 *
 */
void keyPress()
{
    system("stty raw");
    cin >> control;
    system("stty cooked");
}

/* 
 * Definition of function.
 *
 */
void logicFlow(Game *execute)
{
    switch(control)
    {
        case 'w':
        case 'a':
        case 's':
        case 'd':
            execute->backupGrid();
            execute->fillSpace();
            execute->updateGrid();
            execute->fillSpace();
            execute->findGreatestTile();
            execute->displayGrid();
            usleep(1000*160);
            
            if(execute->full() && destroy)
            {
                response = -1;
                break;
            }
            else if (execute->blockMoves())
            {
                execute->spawn();
                break;
            }
            else
            {
                response = 0;
                break;
            }
        case 'u':
            if (execute.blockMoves())
            {
                score -= plus;
            }
            execute->undo();
            break;
        case 'r':
            execute->startGrid();
            score = 0;
            plus = 0;
            break;
        case 'q':
            response = -1;
            break;
        case'h':
            execute->displayHelpScreen();
            pressEnter = getchar();
            execute->displayGrid();
            break;
    }
}

/* 
 * Definition of function.
 *
 */
void gameEndCheck(Game *screen)
{
    if (max == win)
    {
        screen->displayWinScreen();
        
        if(screen->displayTryAgainScreen(0) == 'n')
        {
            response = -1;
        }
        else
            win*=2;
    }
    else if (response == -1)
    {
        screen->displayLoserScreen();
        
        if(screen->displayTryAgainScreen(1) == 'y')
        {
            screen->startGrid();
            response = 0;
        }
    }
    
    if (response == -1)
    {
        cout << "\n\n\t\t > Thank you for playing. "
                << "\n\n\n\t\t\t\t\t\t DEVELOPED BY \n\n";
        pressEnter = getchar();
        exit(0);
    }
}

/* 
 * Definition of function.
 *
 */
void startGrid()
{
    int i, j;
    plus = 0;
    score = 0;
    max = 0;
    
    for (i= 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            grid[i][j]=0;
        }
    }
    i = randomIndex(4);
    j = randomIndex(4);
    
    grid[i][j] = 2;
    
//    i = randomIndex(4);
//    j = randomIndex(4);
//    
//    grid[i][j] = 2;
}

/* 
 * Definition of function.
 *
 */
void displayGrid()
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
    
    cout<<"\t\t\t\t\t\tSCORE::"<<score<<" \n\n\n\n";
    
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

/* 
 * Definition of function.
 *
 */
int randomIndex(int x)
{
    int index;
    index = rand()%x + 0;
    return index;
}

/* 
 * Definition of function.
 *
 */
void backupGrid()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            bgrid[i][j] = grid[i][j];
        }
    }
}

/* 
 * Definition of function.
 *
 */
void fillSpace()
{
    switch(control)
    {
        case 'w':
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    //line 262
                }
            }
    }
}
/* 
 * Definition of function.
 *
 */
/* 
 * Definition of function.
 *
 */
/* 
 * Definition of function.
 *
 */