//
// Created by or on 02/11/17.
//

#include "Coordinate.h"
#include <iostream>
/**
 * contructor.
 * @param x1 - x value
 * @param y1 - y value
 */
Coordinate::Coordinate(int x1, int y1) : x(x1), y(y1) {
}
/**
 * @return the x value of Coordinate.
 */
int Coordinate::getX() const{
    return x;
}
/**
 * @return the y value of Coordinate.
 */
int Coordinate::getY() const{
    return y;
}
