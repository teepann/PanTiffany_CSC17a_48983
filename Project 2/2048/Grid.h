/* 
 * File:   Grid.h
 * Author: Tiffany
 * Final Project 2048
 * Created on December 5, 2015, 1:26 PM
 */

#ifndef GRID_H
#define	GRID_H
#include "Tile.h"
#include <iostream>
using namespace std;

class Grid : public Tile {
public:
    Grid();
    Grid(const Grid& orig);
    virtual ~Grid();
        
    bool tileDestroyed; //is tile destroyed
    char control; //input by user
    
    Tile grid[4][4]; //grid that is a 4x4 matrix
    Tile bGrid[4][4]; //backup grid

    void initializeGrid();
    void updateGrid();
    void fillSpace();
    void spawn();
    void findGreatestTile();
    void updateTile();
    
    bool full();
    bool blockMoved();
    
    void setMaxTile(int);
    int getMaxTile();    
    void setScoreRound(int);
    int getScoreRound();
    void setScore(int);
    int getScore();
    
protected:
    int maxTile; //maximum tile  
    int scoreRound; //score of the current round
    int score; //running total of score
};

#endif	/* GRID_H */

