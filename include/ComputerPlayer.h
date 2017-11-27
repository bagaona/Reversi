//
// Created by amir on 02/11/17.
//

#ifndef REVERSI_ComputerPLAYER_H
#define REVERSI_ComputerPLAYER_H


#include "Player.h"

class ComputerPlayer: public Player {
public:
    /************************************************************************
   * Name: ComputerPlayer (Constructor)
   * Input: t- The player's token
   * Output: -
   * Operation: Matches a player with a token
   *************************************************************************/
    ComputerPlayer(const char t);
    /************************************************************************
    * Name: ~ComputerPlayer (Destructor)
    * Input: -
    * Output: -
    * Operation: Not in use right now
    *************************************************************************/
    ~ComputerPlayer();
    /************************************************************************
    * Name: MakeTurn
    * Input: -
    * Output: -
    * Operation: Gets a row and a col from the Computer player and makes a move
    *************************************************************************/
    virtual Coordinate makeTurn(Logic* l, Board* originalBoard, Printer* printer, set<Coordinate> availableMoves) const;

private:
    Board* tempBoard;
};


#endif //REVERSI_ComputerPLAYER_H
