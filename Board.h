// 204313100
// Amir Bagaon

#ifndef REVERSI_BOARD_H
#define REVERSI_BOARD_H


#include "ConsolePrinter.h"

class Board {
private:
    char** board; // The board
    const int size; //The board's size
    Printer* printer; //The board's printer

public:
    /*************************************************************************
    * Name: Board (Constructor)
    * Input: size - the size of the board
    * Output: -
    * Operation: The function build a board with the size from input
    *************************************************************************/
    Board(const int &size, Printer*& p);

    /*************************************************************************
    * Name: ~Board (Destructor)
    * Input: -
    * Output: -
    * Operation: The function frees the allocated memory for the board.
    *************************************************************************/
    ~Board();

    /*************************************************************************
    * Name: Initialize
    * Input: size - the size of the board
    * Output: -
    * Operation: The function Initialize the board with ' ','O','X' on the
    * right places.
    *************************************************************************/
    void initialize();

    /*************************************************************************
    * Name: PrintBoard
    * Input: -
    * Output: -
    * Operation: The function prints the board.
    *************************************************************************/
    void printBoard();

    /*************************************************************************
    * Name: Update
    * Input: row, col, and the token of the player
    * Output: -
    * Operation: The function updates a new piece/token on the board
    *************************************************************************/
    void update(const int &row, const int &col, const char &player) const;

    /*************************************************************************
    * Name: GetSize
    * Input: -
    * Output: Returns the size
    * Operation: "      "   "
    *************************************************************************/
    const int getSize() const;
    /*************************************************************************
    * Name: GetValue
    * Input: row and col of spesific cell
    * Output: Returns the value of the char in the cell
    * Operation: "      "   "
    *************************************************************************/
    char getValue(const int &row, const int &col) const;

    /*************************************************************************
    * Name: StartMode
    * Input: -
    * Output: -
    * Operation: Set the board as the start of the game (4 tokens on middle)
    *************************************************************************/
    void startMode() const;

    /*************************************************************************
    * Name: Clear
    * Input: -
    * Output: -
    * Operation: Clears the board (all cells are ' ')
    *************************************************************************/
    void clear() const;

    /*************************************************************************
    * Name: IsFull
    * Input: -
    * Output: -
    * Operation: Returns if the board is full
    *************************************************************************/
    bool isFull() const;
};


#endif //REVERSI_BOARD_H