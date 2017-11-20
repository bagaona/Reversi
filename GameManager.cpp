//
// Created by amir on 25/10/17.
//

#include "GameManager.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

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
    delete(moves);
    delete(b);
    delete(printer);
}
void GameManager::initialize(const int &size) {

    printer = new ConsolePrinter();

    b = new Board(size, printer);
    b->startMode();

    moves = new NormalLogic(b, printer);

    players = new Player*[2];
    players[0] = new HumanPlayer('X', moves, b);
    players[1] = new ComputerPlayer('O', moves, b);

}
void GameManager::run() {
    tie = 0;
    int turn = 0;
    while(!b->isFull()) {
        playTurn(players[turn], moves);
        if (tie == 2) {
           printer->noMoreMoves();
            break;
        }
        turn = 1 - turn;
        moves->endTurn();
    }
    endGame();
}
void GameManager::playTurn(Player *&player, Logic *&moves) {
    b->printBoard();
    char token = player->getToken();
    printer->yourTurn(token);

    moves->calculateAll(token);

    if (moves->legalMoves()) {
        putNext(moves, player);
        tie = 0;
    } else {
        tie++;
    }
}

void GameManager::putNext(Logic *&m, Player *&p) const{
    bool flag = true;
    int row, col;
    int position [2];
    while (flag) {
        p->makeTurn(position, printer);
        row = position[0];
        col = position[1];
        if (m->isLegal(row, col)) {
            flag = false;
            b->update(row, col, p->getToken());
            m->flip(row, col, p->getToken());
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

    for (int x = 0;x < b->getSize();x++) {
        for(int y = 0;y < b->getSize();y++) {
            if (b->getValue(x, y) == p1) {
                score1++;
            } else if (b->getValue(x, y) == p2) {
                score2++;
            }
        }
    }
    printer->winner(p1, p2, score1, score2);
}

void GameManager::endGame() {
    b->printBoard();
    winner();
}

