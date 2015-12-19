/* 
 * File:   BackupGrid.cpp
 * Author: Tiffany
 * Final Project 2048
 * Created on December 12, 2015, 3:41 PM
 */

#include "BackupGrid.h"

template <class T>
BackupGrid<T>::BackupGrid() {
    bmaxTile = 0;
    bscoreRound = 0;
    bscore = 0;
}

//copy constructor
template <class T>
BackupGrid<T>::BackupGrid(const BackupGrid& orig) {
    bmaxTile = orig.bmaxTile;
    bscoreRound = orig.bscoreRound;
    bscore = orig.bscore;
}

template <class T>
BackupGrid<T>::~BackupGrid() {
}

/*updates the current tile to a new value*/
template <class T>
void BackupGrid<T>::updateTile()
{
    setValue(getValue()*2);
}

template <class T>
void BackupGrid<T>::setMaxTile(T m)
{
    bmaxTile = m;
}

template <class T>
T BackupGrid<T>::getMaxTile()
{
    return bmaxTile;
}

template <class T>
void BackupGrid<T>::setScoreRound(int s)
{
    bscoreRound = s;
}

template <class T>
int BackupGrid<T>::getScoreRound()
{
    return bscoreRound;
}

template <class T>
void BackupGrid<T>::setScore(int s)
{
    bscore = s;
}

template <class T>
int BackupGrid<T>::getScore()
{
    return bscore;
}

/*definition of function initializeGrid
 * resets score and maxTile and each element of grid to 0
 * spawns 2 more tiles
 */
template <class T>
void BackupGrid<T>::initializeGrid()
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
template <class T>
void BackupGrid<T>::spawn()
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
template <class T>
void BackupGrid<T>::findGreatestTile()
{
    for (int i = 0; i<4; i++)
        for (int j = 0; j<4; j++)
            if (bgrid[i][j].getValue()>bmaxTile)
                bmaxTile = bgrid[i][j].getValue();
}


