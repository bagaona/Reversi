//
// Created by amir on 25/10/17.
//

#ifndef UNTITLED_NEXTMOVE_H
#define UNTITLED_NEXTMOVE_H
#include "Logic.h"

//A sub-class that represents a normal logic of the game

class NormalLogic: public Logic{

public:
    /************************************************************************
	* Name: NormalLogic (Default Constructor)
	* Input: b - The board that the logic should be implied on
	* Output: -
	* Operation: Initialize Normal-Logic calculation for the game
	*************************************************************************/
    NormalLogic(Board*& b);
    /************************************************************************
      * Name: Logic (Destructor)
      * Input: -
      * Output: -
      * Operation: Not in use for now
      *************************************************************************/
    ~NormalLogic();

    /************************************************************************
     * Name: helper
     * Input: current - the current char in the board.
     * player and other - the players.
     * &sawother - tells if other's char has been seen in the line
     * &need_update - tells if the board should be update (so the player can
     * put a new token)
     * Output: Return true if the loop should break (when see ' ' or player's char)
     * Operation: Helps each of the 'for' and save code. Also changes the value of
     * &sawOther and &need_update when other player's char appear and when
     * ' ' appears.
     *************************************************************************/
    bool shouldStop(const char &current, const char &player,
                    const char &other, bool &sawOther, bool &need_update) const;

    /************************************************************************
      * Name: flipHelper
      * Input: current - the current char on the board
      * player - the player
      * hasSame - bool that checks if there's a token in this line that is same
      * as the player's token
      * Output: Return true if the loop should break (when see ' ' or player's char)
      * Operation: Helps the flip to decide if the line should be flipped
      *************************************************************************/
    bool flipHelper(const char &current, const char &player, bool &hasSame) const;

    void setAvailableMoves(set<Coordinate> &availableMoves);

    //All of the other funcs were described in Logic class
    virtual void calculate(Coordinate &c, const char &player);
    virtual set<Coordinate> availableMoves(const char token);
    virtual bool isLegal(Coordinate &c) const;
    virtual void flip(Coordinate c, const char &player);
    virtual void setCurrentBoard(Board *& b);
};


#endif //UNTITLED_NEXTMOVE_H
