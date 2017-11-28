//
// Created by or on 01/11/17.
//

#ifndef REVERSI_CELL_H
#define REVERSI_CELL_H


#include "Coordinate.h"
enum Value {Black = 'X', White = 'O', Empty = ' '};

class Cell
{
public:
    //Constructor
    Cell(int x, int y, Value s);
    //Returns the sign of the Cell
    Value getSign() const ;
    //Set the sign of the Cell
    void setSign(Value newSign);
    //Return if the cell is empty
    bool isEmpty() const;

private:
    Coordinate coordinate;
    Value sign;
};


#endif //EX2_CELL_H
