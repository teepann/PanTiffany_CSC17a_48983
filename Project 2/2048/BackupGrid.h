/* 
 * File:   BackupGrid.h
 * Author: Tiffany
 * Final Project 2048
 * Created on December 12, 2015, 3:41 PM
 */

#ifndef BACKUPGRID_H
#define	BACKUPGRID_H
#include "Tile.h"
#include "Grid.h"

class BackupGrid : public Tile {
public:
    BackupGrid();
    BackupGrid(const BackupGrid& orig);
    virtual ~BackupGrid();
    void updateTile();
    
    Tile bgrid[4][4];

    void initializeGrid();
    void spawn();
    void findGreatestTile();
    
    void setMaxTile(int);
    int getMaxTile();    
    void setScoreRound(int);
    int getScoreRound();
    void setScore(int);
    int getScore();
    
private:
    int bmaxTile; //maximum tile  
    int bscoreRound; //score of the current round
    int bscore; //running total of score
};

#endif	/* BACKUPGRID_H */

