//
// Created by amir on 25/10/17.
//

#include "GameManager.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "ConsolePrinter.h"

using namespace std;

GameManager::GameManager() {
    initialize(8);
}
GameManager::GameManager(const int &size) {
    initialize(size);
}
GameManager::~GameManager() {
    delete(players[0]);
    delete(players[1]);
    delete[] players;
    delete(logic);
    delete(board);
    delete(printer);
}
void GameManager::initialize(const int &size) {

    printer = new ConsolePrinter();

    board = new Board(size);
    board->startMode();

    logic = new NormalLogic(board, printer);

    players = new Player*[2];
    players[0] = new HumanPlayer('X');
    players[1] = new ComputerPlayer('O');

}
void GameManager::run() {
    tie = 0; //updates when player cant move
    int turn = 0;
    while(!board->isFull()) {
        playTurn(players[turn]); // play current turn
        if (tie == 2) { // if both players cant move
           printer->noMoreMoves();
            break;
        }
        turn = 1 - turn; // switch the turn to other player
        logic->endTurn();
    }
    endGame();
}
void GameManager::playTurn(Player *&player) {
    printer->printBoard(board);
    const char token = player->getToken();
    printer->yourTurn(token);

    set<Coordinate> availableMoves = logic->legalMoves(token); // Get available moves

    if (!availableMoves.empty()) { //Check if there are avaliable moves for the player
        printer->availableMoves(availableMoves); // Print available moves
        putNext(player, availableMoves); //Player puts his token
        tie = 0;
    } else {
        tie++; //if it equals to 2 - theres a tie
        printer->cantMove(); //print that the player cant move
        char pressAnyKey;
        cin >> pressAnyKey; //wait for user to press any key
    }

}

void GameManager::putNext(Player *&p, set<Coordinate> &availableMoves) const{
    bool flag = true;
    int row, col;

    while (flag) {
        Coordinate position(p->makeTurn(logic, board, printer, availableMoves)); //Get coordinate by player's choose
        row = position.getRow();
        col = position.getCol();
        if (logic->isLegal(row, col)) { //Check if the move is legal
            flag = false;
            board->update(row, col, p->getToken()); //update this one token
            logic->flip(row, col, p->getToken()); // flip other tokens
        } else {
            printer->massage("Illegal move\n");
        }
    }
}


void GameManager::winner() const{
    char p1 = players[0]->getToken();
    char p2 = players[1]->getToken();
    int score1 = 0;
    int score2 = 0;

    for (int x = 0;x < board->getSize();x++) {
        for(int y = 0;y < board->getSize();y++) {
            if (board->getValue(x, y) == p1) {
                score1++;
            } else if (board->getValue(x, y) == p2) {
                score2++;
            }
        }
    }
    printer->winner(p1, p2, score1, score2);
}

void GameManager::endGame() {
    printer->printBoard(board);
    winner();
}

