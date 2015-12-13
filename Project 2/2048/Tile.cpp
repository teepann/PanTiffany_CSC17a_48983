/* 
 * File:   Tile.cpp
 * Author: Tiffany
 * Final Project 2048
 * Created on December 11, 2015, 7:36 PM
 */

#include "Tile.h"
#include <time.h>
#include <stdlib.h>

Tile::Tile() {
}

Tile::Tile(const Tile& orig) {
    value = orig.value;
}

Tile::~Tile() {
}

void Tile::setValue(int num)
{
    value = num;
}

int Tile::getValue()
{
    return value;
}

bool Tile::isEmpty()
{
    if (value == 0)
        return true;
    else 
        return false;
}

/* Definition of function randomNum
 * generates random number between 0 and the number passed through param
 * @param: int
 * @return: int
 */
int Tile::randomNum(int x)
{
    srand(time(NULL));
    int index;
    index = rand() % x;
    return index;
}

Tile Tile::operator+=(const Tile& t)
{
    value += t.value;
    return *this;
}

Tile Tile::operator= (const Tile& t)
{
    value = t.value;
    return *this;
}

bool Tile::operator==(const Tile& t)
{
    if (value == t.value)
        return true;
    else
        return false;
}

/*function newTile creates a random
 *tile of value 2 or 4
 */
void Tile::newTile()
{
    int k = randomNum(10);
    if (k<2)
        setValue(4);
    else
        setValue(2);
}