/* 
 * File:   Grid.cpp
 * Author: Tiffany
 * Final Project 2048
 * Created on December 5, 2015, 1:26 PM
 */

#include "Grid.h"
#include <math.h>
#include <stdlib.h>

Grid::Grid() {    
    maxTile = 0;
    scoreRound = 0;
    score = 0;
}

//copy constructor
Grid::Grid(const Grid& orig) {
    maxTile = orig.maxTile;
    scoreRound = orig.scoreRound;
    score = orig.score;
}

Grid::~Grid() {
}


/*definition of Grid class function initializeGrid
 * resets score and maxTile and each element of grid to 0
 * spawns 2 more tiles
 */
void Grid::initializeGrid()
{
    int i, j;

    scoreRound = 0;
    score = 0;
    maxTile = 0;

    for (i = 0; i<4; i++)
        for (j = 0; j<4; j++)
            grid[i][j].setValue(0);

    spawn();
    spawn();
}



/* Definition of Grid class function fillSpace
 * depending on direction grid tiles move, 0 will fill spaces
 */
void Grid::fillSpace()
{
    switch (control){
	case 'w':
            for (int i = 0; i<4; i++)
                for (int j = 0; j<4; j++)
                {
                    if (grid[j][i].isEmpty())
                    {
                        for (int k = j + 1; k<4; k++)
                            if (!grid[k][i].isEmpty())
                            {
                                grid[j][i] = grid[k][i];
                                grid[k][i].setValue(0);
                                break;
                            }
                    }
                }
            break;

    case 's':
        for (int i = 0; i<4; i++)
            for (int j = 3; j >= 0; j--)
            {
                if (grid[j][i].isEmpty())
                {
                    for (int k = j - 1; k >= 0; k--)
                        if (!grid[k][i].isEmpty())
                        {
                            grid[j][i] = grid[k][i];
                            grid[k][i].setValue(0);
                            break;
                        }
                }
            }
            break;
	case 'a':
            for (int i = 0; i<4; i++)
                for (int j = 0; j<4; j++)
                {
                    if (grid[i][j].isEmpty())
                    {
                        for (int k = j + 1; k<4; k++)
                            if (!grid[i][k].isEmpty())
                            {
                                grid[i][j] = grid[i][k];
                                grid[i][k].setValue(0);
                                break;
                            }
                    }
                }
            break;
	case 'd':
            for (int i = 0; i<4; i++)
                for (int j = 3; j >= 0; j--)
                {
                    if (grid[i][j].isEmpty())
                    {
                        for (int k = j - 1; k >= 0; k--)
                            if (!grid[i][k].isEmpty())
                            {
                                grid[i][j] = grid[i][k];
                                grid[i][k].setValue(0);
                                break;
                            }
                    }
                }
            break;
    }
}

/* Definition of Grid class function updateGrid
 * resets the current score of the round to 0
 * for each move, grid will combine with adjacent equal tile
 * and sets tileDestroyed to true if tile was combined
 * score is recorded
 */
void Grid::updateGrid()
{
    scoreRound = 0;
    tileDestroyed = false;

    switch (control)
    {
        case 'w':
            for (int i = 0; i<4; i++)
                for (int j = 0; j<3; j++)
                {
                    if (!grid[j][i].isEmpty() && grid[j][i] == grid[j + 1][i])
                    {
                        tileDestroyed = true;
                        grid[j][i] += grid[j + 1][i];
                        grid[j + 1][i].setValue(0);
                        scoreRound += (((log2(grid[j][i].getValue())) - 1)*grid[j][i].getValue());
                        score += scoreRound; 
                    }
                }
            break;

    case 's':
        for (int i = 0; i<4; i++)
            for (int j = 3; j>0; j--)
            {
                if (!grid[j][i].isEmpty() && grid[j][i] == grid[j - 1][i])
                {
                    tileDestroyed = true;
                    grid[j][i] += grid[j - 1][i];
                    grid[j - 1][i].setValue(0);
                    scoreRound += (((log2(grid[j][i].getValue())) - 1)*grid[j][i].getValue());
                    score += scoreRound;
                }
            }
        break;

    case 'a':
        for (int i = 0; i<4; i++)
            for (int j = 0; j<3; j++)
            {
                if (!grid[i][j].isEmpty() && grid[i][j] == grid[i][j + 1])
                {
                    tileDestroyed = true;
                    grid[i][j] += grid[i][j + 1];
                    grid[i][j + 1].setValue(0);
                    scoreRound += ((log2(grid[i][j].getValue())) - 1)*grid[i][j].getValue();
                    score += scoreRound;
                }
            }
        break;

    case 'd':
        for (int i = 0; i<4; i++)
            for (int j = 3; j>0; j--)
            {
                if (!grid[i][j].isEmpty() && grid[i][j] == grid[i][j - 1])
                {
                    tileDestroyed = true;
                    grid[i][j] += grid[i][j - 1];
                    grid[i][j - 1].setValue(0);
                    scoreRound += ((log2(grid[i][j].getValue())) - 1)*grid[i][j].getValue();
                    score += scoreRound;
                }
            }
        break;
    }
}

/* Definition of Grid class function spawn
 * spawns a new tile of value 2 or 4 at an arbitrary location on the grid
 * that is not currently occupied by a number that is nonzero
 */
void Grid::spawn()
{
    int i, j;

    do {
        i = randomNum(4);
        j = randomNum(4);
    } while (grid[i][j].getValue());

    grid[i][j].newTile();
}

/* Definition of Grid function findGreatestTile
 * loops through grid to find maxTile
 */
void Grid::findGreatestTile()
{
    for (int i = 0; i<4; i++)
        for (int j = 0; j<4; j++)
            if (grid[i][j].getValue()>maxTile)
                maxTile = grid[i][j].getValue();
}

/* Definition of Grid class function full
 * loops through grid to check if each element is a nonzero
 * returns true if so, false if not
 * @return bool
 */
bool Grid::full()
{
    bool k = false;

    for (int i = 0; i<4; i++)
        for (int j = 0; j<4; j++)
        {
            if (!grid[i][j].isEmpty())
                k = 0;
        }
    return k;
}

/* definition for Grid class function blockMoved
 * loops through the grid to check if backup grid is same as current grid
 * returns true if false true if so
 *@return bool
 */
bool Grid::blockMoved()
{
    bool k = 0;

    for (int i = 0; i<4; i++)
        for (int j = 0; j<4; j++)
            if (!(bGrid[i][j] == grid[i][j]))
            {
                k = 1;
                break;
            }
    return k;
}

void Grid::setMaxTile(int m)
{
    maxTile = m;
}

int Grid::getMaxTile()
{
    return maxTile;
}

void Grid::setScoreRound(int s)
{
    scoreRound = s;
}

int Grid::getScoreRound()
{
    return scoreRound;
}

void Grid::setScore(int s)
{
    score = s;
}

int Grid::getScore()
{
    return score;
}

//overwrite virtual function updateTile
void Grid::updateTile()
{
    setValue(getValue()*2);
}

