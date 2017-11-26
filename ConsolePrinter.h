//
// Created by amir on 07/11/17.
//

#ifndef REVERSI_CONSOLEPRINTER_H
#define REVERSI_CONSOLEPRINTER_H


#include "Printer.h"

class ConsolePrinter : public Printer {
public:
    virtual void printBoard(Board *& board) const;
    virtual void cantMove() const;
    virtual void massage(const string &s) const;
    virtual void noMoreMoves() const;
    virtual void availableMoves(set<Coordinate> legalMoves) const;
    virtual void yourTurn(const char &player) const;
    virtual void winner(const char &p1, const char &p2, const int &score1,
                        const int &score2) const;
    virtual void playingMove(Coordinate &c);
};


#endif //REVERSI_CONSOLEPRINTER_H
