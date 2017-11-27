//
// Created by amir on 02/11/17.
//

#ifndef REVERSI_PLAYER_H
#define REVERSI_PLAYER_H

#include <iostream>
#include "Printer.h"
#include "Logic.h"

using namespace std;

class Player {

protected:
    const char sign;

public:
    /************************************************************************
	* Name: Player (Constructor)
	* Input: token - The player's token
	* Output: -
	* Operation: Matches a player with a token
	*************************************************************************/
    Player(const char t);

    /************************************************************************
	* Name: ~Player (Destructor)
	* Input: -
	* Output: -
	* Operation: Not in use right now
	*************************************************************************/
    virtual ~Player();

    /************************************************************************
    * Name: GetToken
    * Input: -
    * Output: Returns the player token
    * Operation: " " "
    *************************************************************************/
    virtual char getToken();

    /************************************************************************
    * Name: MakeTurn
    * Input: -
    * Output: -
    * Operation: Make the turn after the player chooses row and col
    *************************************************************************/
    virtual Coordinate makeTurn(Logic* l, Board* b, Printer* printer, set<Coordinate> availableMoves) const = 0;
};


#endif //REVERSI_PLAYER_H
