/* 
 * File:   BackupGrid.cpp
 * Author: Tiffany
 * Final Project 2048
 * Created on December 12, 2015, 3:41 PM
 */

#include "BackupGrid.h"

BackupGrid::BackupGrid() {
    bmaxTile = 0;
    bscoreRound = 0;
    bscore = 0;
}

//copy constructor
BackupGrid::BackupGrid(const BackupGrid& orig) {
    bmaxTile = orig.bmaxTile;
    bscoreRound = orig.bscoreRound;
    bscore = orig.bscore;
}

BackupGrid::~BackupGrid() {
}

/*updates the current tile to a new value*/
void BackupGrid::updateTile()
{
    setValue(getValue()*2);
}

void BackupGrid::setMaxTile(int m)
{
    bmaxTile = m;
}

int BackupGrid::getMaxTile()
{
    return bmaxTile;
}

void BackupGrid::setScoreRound(int s)
{
    bscoreRound = s;
}

int BackupGrid::getScoreRound()
{
    return bscoreRound;
}

void BackupGrid::setScore(int s)
{
    bscore = s;
}

int BackupGrid::getScore()
{
    return bscore;
}

/*definition of function initializeGrid
 * resets score and maxTile and each element of grid to 0
 * spawns 2 more tiles
 */
void BackupGrid::initializeGrid()
{
    int i, j;

    bscoreRound = 0;
    bscore = 0;
    bmaxTile = 0;

    for (i = 0; i<4; i++)
        for (j = 0; j<4; j++)
            bgrid[i][j].setValue(0);

    spawn();
    spawn();
}

/* Definition of class function spawn
 * spawns a new tile of value 2 or 4 at an arbitrary location on the grid
 * that is not currently occupied by a number that is nonzero
 */
void BackupGrid::spawn()
{
    int i, j;

    do {
        i = randomNum(4);
        j = randomNum(4);
    } while (bgrid[i][j].getValue());

    bgrid[i][j].newTile();
}
    
/* Definition of function findGreatestTile
 * loops through grid to find maxTile
 */
void BackupGrid::findGreatestTile()
{
    for (int i = 0; i<4; i++)
        for (int j = 0; j<4; j++)
            if (bgrid[i][j].getValue()>bmaxTile)
                bmaxTile = bgrid[i][j].getValue();
}

