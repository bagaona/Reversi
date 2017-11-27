//
// Created by or on 01/11/17.
//

#include "../include/Cell.h"

/**
 * constructor.
 * @param x - x value
 * @param y - y value
 * @param s - sign of cell
 */
Cell::Cell(int x, int y, char s) : coordinate(x,y), sign(s)
{}
/*
Cell::Cell() {
}
*/

/**
 * check if cell id empty.
 * @return true if yes; false otherwise
 */
bool Cell::isEmpty() const {
    return sign == ' ';
    }
/**
 * @return the x value of cell.
 */
//int Cell::getX() const {
//    return coordinate.getX();
//}
///**
// * @return the y value of cell
// */
//int Cell::getY() const {
//    return coordinate.getY();
//}
/**
 * @return the sign (symbol) of specific cell.
 */
char Cell::getSign() const {
    return sign;
}
/**
 * set new sign in cell.
 * @param newSign - new sign.
 */
void Cell::setSign(char newSign) {
    sign = newSign;
}
/**
 * check if the sign of player isn't the same sign in the cell
 * @param s - sign Player.
 * @return true if it is different.
 */
bool Cell::isOpposite(char signPlayer) const {
    return sign != signPlayer && !isEmpty();
}
/**
 * flip the sign from 'x' to 'o' and from 'o' to 'x'.
 * @param s
 */
void Cell::flip(char s) {
    if ((s == 'O' && sign == 'X') || (s == 'X' && sign == 'O')) {
        this->setSign(s);
    }
}




