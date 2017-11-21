
//A Class that represents the game's Board
#include "Board.h"
#include <iostream>

using namespace std;

//Constructor
Board::Board(const int &s): size(s){
    initialize();
}
Board::Board(Board* b1): size(b1->getSize()){
    board = new char*[size];
    //Allocates a 2d matrix
    for (int i = 0; i < size; i++) {
        board[i] = new char[size];
    }

    copyFromBoard(b1);
}

//Initializes the board
void Board::initialize() {
    board = new char*[size];
    //Allocates a 2d matrix
    for (int i = 0; i < size; i++) {
        board[i] = new char[size];
    }
    clear();
}
const int Board::getSize() const{
    return size;
}

void Board::clear() const{
    //Set empty cells
    for (int x = 0;x < size;x++) {
        for(int y = 0;y < size;y++) {
            board[x][y] = ' ';
        }
    }
}

//Put tokens at start
void Board::startMode() const{
    char white = 'O';
    char black = 'X';
    board[(size / 2) - 1][(size / 2) - 1] = white;
    board[size / 2][size / 2] = white;
    board[(size / 2) - 1][size / 2] = black;
    board[size / 2][(size / 2) - 1] = black;
}
//Updates the board
void Board::update(const int &row, const int &col, const char &player) const{
    board[row][col] = player;
}

//Frees the board's allocation
    Board::~Board() {
    for (int i = 0; i < size; i++) {
        delete[] board[i];
    }
    delete[] board;
}
//Returns the board
char Board::getValue(const int &row, const int &col) const{
    return board[row][col];
}

//Returns if the board is full
bool Board::isFull() const{
    for (int row = 0;row < size;row++) {
        for(int col = 0;col < size;col++) {
            if (board[row][col] == ' ') {
                return false;
            }
        }
    }
    return true;
}
void Board::copyFromBoard(Board *b1) {
    for (int x = 0;x < size;x++) {
        for(int y = 0;y < size;y++) {
            board[x][y] = b1->getCopy()[x][y];
        }
    }
}

