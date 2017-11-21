//
// Created by amir on 07/11/17.
//

#ifndef REVERSI_PRINTER_H
#define REVERSI_PRINTER_H

#include <iostream>
#include <set>
#include "Coordinate.h"
#include "Board.h"

using namespace std;

class Printer {
public:
    virtual void printBoard(Board *& board) const = 0;
    virtual void massage(const string &s) const = 0;
    virtual void cantMove() const = 0;
    virtual void noMoreMoves() const = 0;
    virtual void availableMoves(set<Coordinate> legalMoves) const = 0;
    virtual void yourTurn(const char &player) const = 0;
    virtual void winner(const char &p1, const char &p2, const int &score1,
                        const int &score2) const = 0;
};


#endif //REVERSI_PRINTER_H
