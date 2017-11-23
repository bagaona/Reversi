//
// Created by amir on 25/10/17.
//

#include "NormalLogic.h"
#include <iostream>
#include <stdio.h>

using namespace std;
NormalLogic::NormalLogic(Board*& b, Printer*& p): Logic(b, p) {

}
NormalLogic::~NormalLogic() {
}

bool NormalLogic::shouldStop(const char &current, const char &player,
                             const char &other, bool &sawOther, bool &need_update) const{
    if (current == other) {
        sawOther = true;
        return false;
    }
    if (current == ' ') {
        if (sawOther) {
            need_update = true;
        }
    }
    //In case of ' ' or player's char
    return true;
}
void NormalLogic::calculate(Coordinate &c, const char &player, Board*& curBoard) {
    int row = c.getRow();
    int col = c.getCol();


    char current;
    char other = curBoard->getOpponent(player);
    //cout << other;
   // cout << endl << endl<< endl<< endl;
   // printer->printBoard(curBoard);
   // cout << endl << endl<< endl<< endl;

    bool sawOther = false;
    bool need_update = false;
    //Down
    int i;
    for (i = row + 1; i < size; i ++) {
        current = curBoard->getValue(i, col);
        if (shouldStop(current, player, other, sawOther, need_update)) {
            break;
        }
    }
    if (need_update) {
        canMove.insert(Coordinate(i, col));
    }


    //Right
    sawOther = need_update = false;

    for (i = col + 1; i < size; i ++) {
        current = curBoard->getValue(row, i);
        if (shouldStop(current, player, other, sawOther, need_update)) {
            break;
        }
    }
    if (need_update) {
        canMove.insert(Coordinate(row, i));
    }

    //Left
    sawOther = need_update = false;

    for (i = col - 1; i >= 0; i--) {
        current = curBoard->getValue(row, i);
        if (shouldStop(current, player, other, sawOther, need_update)) {
            break;
        }
    }
    if (need_update) {
        canMove.insert(Coordinate(row, i));
    }

    //Up
    sawOther = need_update = false;

    for (i = row - 1; i  >= 0; i --) {
        current = curBoard->getValue(i, col);
        if (shouldStop(current, player, other, sawOther, need_update)) {
            break;
        }
    }
    if (need_update) {
        canMove.insert(Coordinate(i, col));
    }

    //Down-right
    int temp_row = row + 1;
    sawOther = need_update = false;

    for (i = col + 1; i < size && temp_row < size; i++, temp_row++) {
        current = curBoard->getValue(temp_row, i);
        if (shouldStop(current, player, other, sawOther, need_update)) {
            break;
        }
    }
    if (need_update) {
        canMove.insert(Coordinate(temp_row, i));
    }

    //Up-right
    temp_row = row - 1;
    sawOther = need_update = false;

    for (i = col + 1; i < size && temp_row >= 0; i++, temp_row--) {
        current = curBoard->getValue(temp_row, i);
        if (shouldStop(current, player, other, sawOther, need_update)) {
            break;
        }
    }
    if (need_update) {
        canMove.insert(Coordinate(temp_row, i));
    }
    //Up-left
    temp_row = row - 1;
    sawOther = need_update = false;

    for (i = col - 1; i >= 0 && temp_row >= 0; i--, temp_row--) {
        current = curBoard->getValue(temp_row, i);
        if (shouldStop(current, player, other, sawOther, need_update)) {
            break;
        }
    }
    if (need_update) {
        canMove.insert(Coordinate(temp_row, i));
    }

    //Down-left
    temp_row = row + 1;
    sawOther = need_update = false;

    for (i = col - 1; i >= 0 && temp_row < size; i--, temp_row++) {
        current = curBoard->getValue(temp_row, i);
        if (shouldStop(current, player, other, sawOther, need_update)) {
            break;
        }
    }
    if (need_update) {
        canMove.insert(Coordinate(temp_row, i));
    }
}

set<Coordinate> NormalLogic::availableMoves(const char token, Board *&board1){
    calculateAll(token, board1);
    return canMove;
}
bool NormalLogic::isLegal(Coordinate &c) const{
    int row = c.getRow();
    int col = c.getCol();
    if ((row >= size) || (row < 0) || (col >= size) || (col < 0)) {
        return false;
    }

    Coordinate coordinate(row, col);

    //Check if it is not a move from the avaliable moves
    const bool is_in = canMove.find(coordinate) != canMove.end();
    if (!is_in) {
        return false;
    }
    return true;
}

bool NormalLogic::flipHelper(const char &current, const char &player, bool &hasSame) const{
    if((current != player) && (current != ' ')) {
        return false;
    }
    if (current == player) {
        hasSame = true;
    }
    return true;
}

void NormalLogic::flip(Coordinate &c, const char &player, Board* b) {

    int row = c.getRow();
    int col = c.getCol();

    bool hasSame = false;
    char current;
    int i, j, k;

    //Right
    for (i = col + 1; i < size; i++) {
        current = b->getValue(row, i);
        if (flipHelper(current, player, hasSame)) {
            break;
        }
    }
    if (hasSame) {
        for (int j = col + 1; j <= i; j++) {
            b->update(row, j, player);
        }
    }

    //Left
    hasSame = false;
    for (i = col - 1; i >= 0; i--) {
        current = b->getValue(row, i);
        if (flipHelper(current, player, hasSame)) {
            break;
        }
    }
    if (hasSame) {
        for (int j = col - 1; j >= i; j--) {
            b->update(row, j, player);
        }
    }
    //Down
    hasSame = false;
    for (i = row + 1; i < size; i++) {
        current = b->getValue(i, col);
        if (flipHelper(current, player, hasSame)) {
            break;
        }
    }
    if (hasSame) {
        for (int j = row + 1; j <= i; j++) {
            b->update(j, col, player);
        }
    }

    //Up
    hasSame = false;
    for (i = row - 1; i >= 0; i--) {
        current = b->getValue(i, col);
        if (flipHelper(current, player, hasSame)) {
            break;
        }
    }
    if (hasSame) {
        for (int j = row - 1; j >= i; j--) {
            b->update(j, col, player);
        }
    }

    //Down-Right
    int temp_row;
    hasSame = false;
    for (i = col + 1, temp_row = row + 1; i < size && temp_row < size; i++, temp_row++) {
        current = b->getValue(temp_row, i);
        if (flipHelper(current, player, hasSame)) {
            break;
        }
    }
    if (hasSame) {
        for (j = col + 1, k = row + 1; j <= i, k <= temp_row; j++, k++) {
            b->update(k, j, player);
        }
    }

    //Up-Right
    hasSame = false;
    for (i = col + 1, temp_row = row - 1; i < size && temp_row >= 0; i++, temp_row--) {
        current = b->getValue(temp_row, i);
        if (flipHelper(current, player, hasSame)) {
            break;
        }
    }
    if (hasSame) {
        for (j = col + 1, k = row - 1; j <= i, k >= temp_row; j++, k--) {
            b->update(k, j, player);
        }
    }

    //Up-Left
    hasSame = false;
    for (i = col - 1, temp_row = row - 1; i >= 0 && temp_row >= 0; i--, temp_row--) {
        current = b->getValue(temp_row, i);
        if (flipHelper(current, player, hasSame)) {
            break;
        }
    }
    if (hasSame) {
        for (j = col - 1, k = row - 1; j >= i, k >= temp_row; j--, k--) {
            b->update(k, j, player);
        }
    }

    //Down-Left
    hasSame = false;
    for (i = col - 1, temp_row = row + 1; i >= 0 && temp_row < size; i--, temp_row++) {
        current = b->getValue(temp_row, i);
        if (flipHelper(current, player, hasSame)) {
            break;
        }
    }
    if (hasSame) {
        for (j = col - 1, k = row + 1; j >= i, k <= temp_row; j--, k++) {
            b->update(k, j, player);
        }
    }
}

void NormalLogic::setAvailableMoves(set<Coordinate> &availableMoves) {
    canMove = availableMoves;
}

/*
int NormalLogic::getScore(Board*& board) {
    int score1 = 0;
    int score2 = 0;

    for (int x = 0;x < board->getSize();x++) {
        for(int y = 0;y < board->getSize();y++) {
            if (board->getValue(x, y) == p1) {
                score1++;
            } else if (board->getValue(x, y) == p2) {
                score2++;
            }
        }
    }
}
*/