//
// Created by amir on 07/11/17.
//

#include <iostream>
#include "ConsolePrinter.h"
using namespace std;

void ConsolePrinter::printBoard(char** &board, const int &size) const{
    cout << "  ";
    for(int i = 1;i <= size;i++) {
        cout << "| " << i << " ";
    }
    cout << "|" << endl;

    cout << string(size*4 + 3, '-') << endl;

    for(int x = 0;x < size;x++) {
        int row = x + 1;
        cout << row;
        for(int y = 0;y < size;y++) {
            cout << " | " << board[x][y];
        }
        cout << " |" << endl;
        //Prints the line below
        cout << string(size*4 + 3, '-') << endl;
    }
}
void ConsolePrinter::startTurn(const int &row, const int &col) const {
    cout << "Your possible moves:" << endl;
    cout << "(" << row + 1 << "," << col + 1 << ")";
}
void ConsolePrinter::anotherPlace(const int &row, const int &col) const {
    cout << ",(" << row + 1 << "," << col + 1 << ")";
}
void ConsolePrinter::cantMove() const {
    cout << "No possible moves. Play passes back to the other player. "
            "Press any key and enter to continue" << endl;
}
void ConsolePrinter::massage(const string &s) const {
    cout << s;
}
void ConsolePrinter::noMoreMoves() const {
    cout << "Neither players can move!!!" << endl;
}
void ConsolePrinter::yourTurn(const char &token) const {
    cout << endl;
    cout << token << ": It's your move" << endl;
}
void ConsolePrinter::winner(const char &p1, const char &p2, const int &score1,
                            const int &score2) const{
    cout << "Score: " << endl;
    cout << p1 << ": " << score1 << ", " << p2 << ": " << score2 << endl;
    if (score1 == score2) {
        cout << "Tie!" << endl;
    } else {
        if (score1 > score2) {
            cout << "The winner is: " << p1 << endl;
        } else {
            cout << "The winner is: " << p2 << endl;
        }
    }
}