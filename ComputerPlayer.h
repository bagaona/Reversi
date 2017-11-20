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
    ComputerPlayer(const char t, Logic* l, Board* b);
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
    virtual void makeTurn(int (&position)[2], Printer* printer) const;
};


#endif //REVERSI_ComputerPLAYER_H
