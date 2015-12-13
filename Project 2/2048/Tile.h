/* 
 * File:   Tile.h
 * Author: Tiffany
 * Final Project 2048
 * Created on December 11, 2015, 7:36 PM
 */

#ifndef TILE_H
#define	TILE_H

class Tile {
public:
    Tile();
    Tile(const Tile& orig);
    virtual ~Tile();
    int getValue();
    void setValue(int);
    bool isEmpty();
    virtual void updateTile() {};
    int randomNum(int);
    Tile operator+=(const Tile&);
    bool operator==(const Tile&);
    Tile operator=(const Tile&);
    void newTile();
    
protected:
    int value;    
};

#endif	/* TILE_H */

