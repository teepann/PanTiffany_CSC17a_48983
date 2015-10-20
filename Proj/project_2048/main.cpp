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

int pressEnter;
int randomIndex(int);
class Game;
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
        exec.logicFlow(&exec);
        exec.gameEndCheck(&exec);
    }
    return 0;
}

/* 
 * Definition of function.
 *
 */
void GameAI::keyPress()
{
    system("stty raw");
    cin >> control;
    system("stty cooked");
}

/* 
 * Definition of function.
 *
 */
void GameAI::logicFlow(Game *execute)
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
            sleep(1000*160);
            
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
            if (execute->blockMoves())
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
void GameAI::gameEndCheck(Game *screen)
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
void GameAI::startGrid()
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
    
    i = randomIndex(4);
    j = randomIndex(4);
    
    grid[i][j] = 2;
}

/* 
 * Definition of function.
 *
 */
void Game::displayGrid()
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
void GameAI::backupGrid()
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
void GameAI::fillSpace()
{
    switch(control)
    {
        case 'w':
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (!grid[i][j])
                    {
                        for (int k = j + 1; k < 4; k++)
                        {
                            if (grid[k][i])
                            {
                                grid[j][i] = grid [k][i];
                                grid[k][i] = 0;
                                break;
                            }
                        }
                    }
                }
            }
            break;
        case 's': 
            for (int i = 0; i < 4; i++)
            {
                for (int j = 3; j >= 0; j--)
                {
                    if (!grid[j][i])
                    {
                        for (int k = j - 1; k>=0; k--)
                        {
                            if (grid[k][i])
                            {
                                grid[j][i] = grid[k][i];
                                grid[k][i] = 0;
                                break;
                            }
                        }
                    }
                }
            }
        case 'a': 
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (!grid[i][j])
                    {
                        for (int k = j + 1; k < 4; k++)
                        {
                            if (grid[i][k])
                            {
                                grid[i][j] = grid [i][k];
                                grid[i][k] = 0;
                                break;
                            }
                        }
                    }
                }
            }
        case 'd': 
            for (int i = 0; i < 4; i++)
            {
                for (int j = 3; j >= 0; j--)
                {
                    if (!grid[i][j])
                    {
                        for (int k = j - 1; k>=0; k--)
                        {
                            if (grid[i][k])
                            {
                                grid[i][j] = grid[i][k];
                                grid[i][k] = 0;
                                break;
                            }
                        }
                    }
                }
            }
    }
}

/* 
 * Definition of function.
 *
 */
void GameAI::updateGrid()
{
    plus = 0;
    destroy = 1;
    switch(control)
    {
        case 'w': 
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (grid[j][i] && grid [j][i] == grid [j+1][i])
                    {
                        destroy = 0;
                        grid[j][i] += grid[j+1][i];
                        grid[j+1][i] = 0;
                        plus += (((log2(grid[j][i]))-1)*grid[j][i]);
                        score += (((log2(grid[j][i]))-1)*grid[j][i]); 
                    }
                }
            }
            break;
        case 's': 
            for (int i = 0; i < 4; i++)
            {
                for (int j = 3; j > 0; j--)
                {
                    if (grid[j][i] && grid [j][i] == grid [j-1][i])
                    {
                        destroy = 0;
                        grid[j][i] += grid[j-1][i];
                        grid[j-1][i] = 0;
                        plus += (((log2(grid[j][i]))-1)*grid[j][i]);
                        score += (((log2(grid[j][i]))-1)*grid[j][i]); 
                    }
                }
            }
            break;
        case 'a':
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (grid[i][j] && grid [i][j] == grid [i][j+1])
                    {
                        destroy = 0;
                        grid[i][j] += grid[i][j+1];
                        grid[i][j+1] = 0;
                        plus += (((log2(grid[i][j]))-1)*grid[i][j]);
                        score += (((log2(grid[i][j]))-1)*grid[i][j]); 
                    }
                }
            }
            break;
        case 'd':
            for (int i = 0; i < 4; i++)
            {
                for (int j = 3; j > 0; j--)
                {
                    if (grid[i][j] && grid[i][j] == grid [i][j-1])
                    {
                        destroy = 0;
                        grid[i][j] += grid[i][j-1];
                        grid[i][j-1] = 0;
                        plus += (((log2(grid[i][j]))-1)*grid[i][j]);
                        score += (((log2(grid[i][j]))-1)*grid[i][j]); 
                    }
                }
            }
            break;
    }
}

/* 
 * Definition of function.
 *
 */
void GameAI::spawn()
{
    int i, j, k;
    do {
        i = randomIndex(4);
        j = randomIndex(4);
        k = randomIndex(10);
    } while (grid[i][j]);   
    
    if (k < 2)
    {
        grid[i][j] = 4;
    }
    else 
    {
        grid[i][j] = 2;
    }
}

/* 
 * Definition of function.
 *
 */
void GameAI::findGreatestTile()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (grid[i][j] > max)
            {
                max = grid[i][j];
            }
        }
    }
}

/* 
 * Definition of function.
 *
 */
int GameAI::full()
{
    int k = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(!grid[i][j])
            {
                k = 0;
            }
        }
    }
    return k;
}

/* 
 * Definition of function.
 *
 */
void Game::displayHelpScreen()
{
    system("clear");
    cout << endl << "  ::[  THE 2048 PUZZLE  ]::\t\t\t\tDeveloped by SCM [-_-]";
    char text[] = "> The game starts with 1 or 2 randomly placed number s in a 4x4 grid (16 cells).> Use the ";//???
    for (int i = 0; text[i]; i++)
    {
        if (text[i] == '>')
        {
            sleep(1000*500);
            cout << "\n\n\n";
        }
        cout << text[i];
    }    
}

/* 
 * Definition of function.
 *
 */
void Game::displayWinScreen()
{
    system("clear");
    cout << endl << endl;
    cout << "\n\t\t\t  :: [  YOU MADE "<<win<<"!  ] ::"
            << "\n\n\t\t\t  :: [ YOU WON THE GAME ] ::"
            <<"\n\n\n\n\t\t\t TILE\t     SCORE\t    NAME";
    printf("\n\n\t\t\t %4d\t    %6d\t    ",max,score);
    cin >> name;
    
    cout << "\n\n\t\t> The maximum possible tile is 65,536 ! So go on :)";
}

/* 
 * Definition of function.
 *
 */
void Game::displayLoserScreen()
{
    system("clear");
    
    cout << "\n\n\n\t\t\t  :: [ G A M E  O V E R ] ::"
         << "\n\n\n\n\t\t\t TILE\t     SCORE\t    NAME";
    printf("\n\n\t\t\t %4d\t    %6d\t    ",max,score);
    cin >> name;
    
    cout << "\n\n\t\t> The maximum possible score is 3,932,156 ! So close :p";
}

/* 
 * Definition of function.
 *
 */
char Game::displayTryAgainScreen(int lose)
{
    if (lose)
    {
        cout << "\n\n\n\t    > Would you like to try again "<<name<<" (y/n) ? :: ";
    }
    else
    {
        cout << "\n\n\n\t    > Would you like to continue playing "<<name<<" (y/n) ? :: ";
    }
    
    system("stty raw");
    cin >> option;
    system("stty cooked");
    
    return option;
}

/* 
 * Definition of function.
 *
 */
void GameAI::undo()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            grid[i][j] = bgrid[i][j];
        }
    }
}

/* 
 * Definition of function.
 *
 */
int GameAI::blockMoves()
{
    int k = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (bgrid[i][j] != grid[i][j])
            {
                k = 1;
                break;
            }
        }
    }
    return k;
}
