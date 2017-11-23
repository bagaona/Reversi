//
// Created by amir on 02/11/17.
//

#include "Logic.h"
#include <iostream>

using namespace std;
Logic::Logic(Board*& b, Printer*& p) {
    printer = p;
    board = b;
    size = b->getSize();
  //  temp_board = new Board(size, p);
    std::set<int>::iterator it;
    /*canMove.insert(2);
    canMove.insert(3);
    canMove.insert(3);
    canMove.insert(4);
    fdor (it=canMove.begin(); it!=canMove.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
     */
}

Logic::~Logic() {
  //  delete (temp_board);
}

void Logic::calculateAll(const char &player, Board*& board1) {
    for (int row = 0; row < board1->getSize(); row++) {
        for (int col = 0; col < board1->getSize(); col++) {
            if (board1->getValue(row, col) == player) {
                Coordinate coordinate(row,col);
           //     cout << endl << "Found!!!! ROW: " << row +1 << "COL: " << col +1 << endl;
                calculate(coordinate, player, board1);
            }
        }
    }
}

void Logic::endTurn() {
  //  temp_board->clear();
    canMove.clear();
}
