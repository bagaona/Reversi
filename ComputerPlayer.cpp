//
// Created by amir on 02/11/17.
//

#include "ComputerPlayer.h"
#include <iostream>

using namespace std;
ComputerPlayer::ComputerPlayer(const char t, Logic* l, Board* b): Player(t, l, b) {
    temp = b;
    logic = l;
}
ComputerPlayer::~ComputerPlayer() {
}
void ComputerPlayer::makeTurn(int (&position)[2], Printer* printer) const{
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
    position[0] = --row;
    position[1] = --col;
}
