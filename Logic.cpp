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
    temp_board = new Board(size, p);
    std::set<int>::iterator it;
    /*canMove.insert(2);
    canMove.insert(3);
    canMove.insert(3);
    canMove.insert(4);
    for (it=canMove.begin(); it!=canMove.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
     */
}

Logic::~Logic() {
    delete (temp_board);
}

void Logic::calculateAll(const char &player) {
    for (int row = 0; row < board->getSize(); row++) {
        for (int col = 0; col < board->getSize(); col++) {
            if (board->getValue(row, col) == player) {
                calculate(row, col, player);
            }
        }
    }
}

void Logic::endTurn() {
    temp_board->clear();
    canMove.clear();
}
