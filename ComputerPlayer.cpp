//
// Created by amir on 02/11/17.
//

#include "ComputerPlayer.h"
#include <iostream>

using namespace std;
ComputerPlayer::ComputerPlayer(const char t): Player(t) {
}
ComputerPlayer::~ComputerPlayer() {
}
Coordinate ComputerPlayer::makeTurn(Logic* l, Board* b, Printer* printer, set<Coordinate> &availableMoves) const{

    Board* tempBoard = new Board(b);
    std::set<Coordinate>::iterator it;
    for (it=availableMoves.begin(); it!=availableMoves.end();) { //Run over each move the computer can do

    }



//    printer->availableMoves(availableMoves);
  //  return Coordinate(2,4);

}
