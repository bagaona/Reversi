//
// Created by or on 01/11/17.
//

#ifndef REVERSI_CELL_H
#define REVERSI_CELL_H


#include "Coordinate.h"

class Cell
{
public:

  //  Cell();

    Cell(int x, int y, char s);
    char getSign() const ;
    void setSign(char newSign);
    bool isEmpty() const;
    bool isOpposite(char signPlayer) const ;
    void flip(char s);

private:
    Coordinate coordinate;
    char sign;


};


#endif //EX2_CELL_H
