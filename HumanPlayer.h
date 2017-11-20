//
// Created by amir on 02/11/17.
//

#ifndef REVERSI_HUMANPLAYER_H
#define REVERSI_HUMANPLAYER_H


#include "Player.h"

class HumanPlayer: public Player {
public:
    /************************************************************************
   * Name: HumanPlayer (Constructor)
   * Input: t- The player's token
   * Output: -
   * Operation: Matches a player with a token
   *************************************************************************/
    HumanPlayer(const char t, Logic* l, Board* b);
    /************************************************************************
    * Name: ~HumanPlayer (Destructor)
    * Input: -
    * Output: -
    * Operation: Not in use right now
    *************************************************************************/
    ~HumanPlayer();
    /************************************************************************
    * Name: MakeTurn
    * Input: -
    * Output: -
    * Operation: Gets a row and a col from the human player and makes a move
    *************************************************************************/
    virtual void makeTurn(int (&position)[2], Printer* printer) const;
};


#endif //REVERSI_HUMANPLAYER_H
