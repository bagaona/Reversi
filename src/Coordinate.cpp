//
// Created by or on 02/11/17.
//

#include "../include/Coordinate.h"
#include <iostream>
/**
 * contructor.
 * @param x1 - x value
 * @param y1 - y value
 */
Coordinate::Coordinate(int x1, int y1) : row(x1), col(y1) {
}
/**
 * @return the x value of Coordinate.
 */
int Coordinate::getRow() const{
    return row;
}
/**
 * @return the y value of Coordinate.
 */
int Coordinate::getCol() const{
    return col;
}
