//
// Created by amir on 25/10/17.
//

#include "NormalLogic.h"
#include <iostream>

using namespace std;
NormalLogic::NormalLogic(Board*& b, Printer*& p): Logic(b, p) {

}
NormalLogic::~NormalLogic() {
}

bool NormalLogic::helper(const char &current, const char &player,
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
void NormalLogic::calculate(const int &row, const int &col, const char &player) {
    char other, current;
    if (player == 'O') {
        other = 'X';
    } else {
        other = 'O';
    }

    bool sawOther = false;
    bool need_update = false;
    //Down
    int i;
    for (i = row + 1; i < size; i ++) {
        current = board->getValue(i, col);
        if (helper(current, player, other, sawOther, need_update)) {
            break;
        }
    }
    if (need_update) {
        temp_board->update(i, col, player);
        canMove.insert(Coordinate(i, col));
    }


    //Right
    sawOther = need_update = false;

    for (i = col + 1; i < size; i ++) {
        current = board->getValue(row, i);
        if (helper(current, player, other, sawOther, need_update)) {
            break;
        }
    }
    if (need_update) {
        temp_board->update(row, i, player);
        canMove.insert(Coordinate(i, col));
    }

    //Left
    sawOther = need_update = false;

    for (i = col - 1; i >= 0; i--) {
        current = board->getValue(row, i);
        if (helper(current, player, other, sawOther, need_update)) {
            break;
        }
    }
    if (need_update) {
        temp_board->update(row, i, player);
        canMove.insert(Coordinate(i, col));
    }

    //Up
    sawOther = need_update = false;

    for (i = row - 1; i  >= 0; i --) {
        current = board->getValue(i, col);
        if (helper(current, player, other, sawOther, need_update)) {
            break;
        }
    }d
    if (need_update) {
        temp_board->update(i, col, player);
        canMove.insert(Coordinate(i, col));
    }

    //Down-right
    int temp_row = row + 1;
    sawOther = need_update = false;

    for (i = col + 1; i < size && temp_row < size; i++, temp_row++) {
        current = board->getValue(temp_row, i);
        if (helper(current, player, other, sawOther, need_update)) {
            break;
        }
    }
    if (need_update) {
        temp_board->update(temp_row, i, player);
        canMove.insert(Coordinate(i, col));
    }

    //Up-right
    temp_row = row - 1;
    sawOther = need_update = false;

    for (i = col + 1; i < size && temp_row >= 0; i++, temp_row--) {
        current = board->getValue(temp_row, i);
        if (helper(current, player, other, sawOther, need_update)) {
            break;
        }
    }
    if (need_update) {
        temp_board->update(temp_row, i, player);
        canMove.insert(Coordinate(i, col));
    }
    //Up-left
    temp_row = row - 1;
    sawOther = need_update = false;

    for (i = col - 1; i >= 0 && temp_row >= 0; i--, temp_row--) {
        current = board->getValue(temp_row, i);
        if (helper(current, player, other, sawOther, need_update)) {
            break;
        }
    }
    if (need_update) {
        temp_board->update(temp_row, i, player);
        canMove.insert(Coordinate(i, col));
    }

    //Down-left
    temp_row = row + 1;
    sawOther = need_update = false;

    for (i = col - 1; i >= 0 && temp_row < size; i--, temp_row++) {
        current = board->getValue(temp_row, i);
        if (helper(current, player, other, sawOther, need_update)) {
            break;
        }
    }
    if (need_update) {
        temp_board->update(temp_row, i, player);
        canMove.insert(Coordinate(i, col));
    }
}

bool NormalLogic::legalMoves() const{
    bool first = true;

    for (int row = 0; row < temp_board->getSize(); row++) {
        for (int col = 0; col < temp_board->getSize(); col++) {
            if (temp_board->getValue(row, col) != ' ') {
                if (first) {
                  printer->startTurn(row, col);
                    first = false;
                } else {
                    printer->anotherPlace(row, col);
                }
            }
        }
    }
    printer->massage("\n");
    if (first) { //if no tokens were seen
       printer->cantMove();
        char temp;
        cin >> temp;
        return false;
    }
    return true;
}
bool NormalLogic::isLegal(const int &row, const int &col) const{
    if ((row >= size) || (row < 0) || (col >= size) || (col < 0)) {
        return false;
    }
    if (temp_board->getValue(row, col) == ' ') {
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

void NormalLogic::flip(const int &row, const int &col, const char &player) {

    bool hasSame = false;
    char current;
    int i, j, k;

    //Right
    for (i = col + 1; i < size; i++) {
        current = board->getValue(row, i);
        if (flipHelper(current, player, hasSame)) {
            break;
        }
    }
    if (hasSame) {
        for (int j = col + 1; j <= i; j++) {
            board->update(row, j, player);
        }
    }

    //Left
    hasSame = false;
    for (i = col - 1; i >= 0; i--) {
        current = board->getValue(row, i);
        if (flipHelper(current, player, hasSame)) {
            break;
        }
    }
    if (hasSame) {
        for (int j = col - 1; j >= i; j--) {
            board->update(row, j, player);
        }
    }
    //Down
    hasSame = false;
    for (i = row + 1; i < size; i++) {
        current = board->getValue(i, col);
        if (flipHelper(current, player, hasSame)) {
            break;
        }
    }
    if (hasSame) {
        for (int j = row + 1; j <= i; j++) {
            board->update(j, col, player);
        }
    }

    //Up
    hasSame = false;
    for (i = row - 1; i >= 0; i--) {
        current = board->getValue(i, col);
        if (flipHelper(current, player, hasSame)) {
            break;
        }
    }
    if (hasSame) {
        for (int j = row - 1; j >= i; j--) {
            board->update(j, col, player);
        }
    }

    //Down-Right
    int temp_row;
    hasSame = false;
    for (i = col + 1, temp_row = row + 1; i < size && temp_row < size; i++, temp_row++) {
        current = board->getValue(temp_row, i);
        if (flipHelper(current, player, hasSame)) {
            break;
        }
    }
    if (hasSame) {
        for (j = col + 1, k = row + 1; j <= i, k <= temp_row; j++, k++) {
            board->update(k, j, player);
        }
    }

    //Up-Right
    hasSame = false;
    for (i = col + 1, temp_row = row - 1; i < size && temp_row >= 0; i++, temp_row--) {
        current = board->getValue(temp_row, i);
        if (flipHelper(current, player, hasSame)) {
            break;
        }
    }
    if (hasSame) {
        for (j = col + 1, k = row - 1; j <= i, k >= temp_row; j++, k--) {
            board->update(k, j, player);
        }
    }

    //Up-Left
    hasSame = false;
    for (i = col - 1, temp_row = row - 1; i >= 0 && temp_row >= 0; i--, temp_row--) {
        current = board->getValue(temp_row, i);
        if (flipHelper(current, player, hasSame)) {
            break;
        }
    }
    if (hasSame) {
        for (j = col - 1, k = row - 1; j >= i, k >= temp_row; j--, k--) {
            board->update(k, j, player);
        }
    }

    //Down-Left
    hasSame = false;
    for (i = col - 1, temp_row = row + 1; i >= 0 && temp_row < size; i--, temp_row++) {
        current = board->getValue(temp_row, i);
        if (flipHelper(current, player, hasSame)) {
            break;
        }
    }
    if (hasSame) {
        for (j = col - 1, k = row + 1; j >= i, k <= temp_row; j--, k++) {
            board->update(k, j, player);
        }
    }
}
