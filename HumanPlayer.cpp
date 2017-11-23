//
// Created by amir on 02/11/17.
//

#include "HumanPlayer.h"
#include <iostream>

using namespace std;
    HumanPlayer::HumanPlayer(const char t): Player(t) {
}
HumanPlayer::~HumanPlayer() {
}
Coordinate HumanPlayer::makeTurn(Logic* l, Board* b, Printer* printer, set<Coordinate> availableMoves) const{
    int row, col;
    printer->massage("\nEnter Row: ");
    cin >> row;
    while ((!cin)) {
        printer->massage("Endter a number!\nEnter Row: ");
        cin.clear(); // clears error flags
        cin.ignore(9999, '\n');
        cin >> row;
    }
    printer->massage("Enter Col: ");
    cin >> col;
    while ((!cin)) {
        printer->massage("Enter a number!\nEnter Col: ");
        cin.clear(); // clears error flags
        cin.ignore(9999, '\n');
        cin >> col;
    }
    printer->massage("\n");
    return Coordinate(--row, --col); //the -- because the input is higher
}
