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
Coordinate ComputerPlayer::makeTurn(Logic* logic, Board* b, Printer* printer, set<Coordinate> availableMoves) const{

    //ברגע שמוחקים את קן-מוב, אז הוא נחשב כמהלך לא חוקי. הפתרון יהיה לשלוח לאיז-ליגל סט מסוים ולהעביר אותו הלאה, עד שנחזירו בקליולייט

    Board* tempBoard = new Board(b);
    set<Coordinate> backUp = availableMoves;
    char opponent = b->getOpponent(sign);


    int maxScore = b->getSize() * b->getSize() * (-1);
    int row, col, minRow, minCol;
    col = minRow = minCol = row = -1;
    int minMaxScore = b->getSize() * b->getSize();


    std::set<Coordinate>::iterator computerIT;
    for (computerIT=availableMoves.begin(); computerIT!=availableMoves.end(); ++computerIT) { //Run over each move the computer can do
//        cout << endl << "(" << (*computerIT).getRow() + 1 << "," << (*computerIT).getCol() + 1 << "): " << endl;
        tempBoard->update((*computerIT), sign); //update this one token
        logic->flip((*computerIT), sign, tempBoard); // flip other tokens
//        printer->printBoard(tempBoard);
        logic->endTurn(); // erase set

        set<Coordinate> humanMoves = logic->availableMoves(opponent, tempBoard);
        if (humanMoves.empty()) {
            printer->cantMove();
            logic->setAvailableMoves(backUp);
            delete(tempBoard);
            return (*computerIT);
        }
//        printer->availableMoves(humanMoves);
//
        std::set<Coordinate>::iterator humanIT;
        for (humanIT=humanMoves.begin(); humanIT!=humanMoves.end(); ++humanIT) { //Run over each move the human can do
            //
            tempBoard->update((*computerIT).getRow(), (*computerIT).getCol(), sign); //update this one token
            logic->flip((*computerIT), sign, tempBoard); // flip other tokens
            logic->endTurn();
            //


            tempBoard->update((*humanIT), opponent); //update this one token
            logic->flip((*humanIT), opponent, tempBoard); // flip other tokens
//            printer->printBoard(tempBoard);
            int score = tempBoard->score(opponent);
//            cout << "(" << (*humanIT).getRow() + 1 << "," << (*humanIT).getCol() + 1 << "): ";
//            cout << "Score: " << score << endl;
            if (score > maxScore) {
                maxScore = score;

                //take the coordianate of the computer player
                row = (*computerIT).getRow();
                col = (*computerIT).getCol();
                //cout << endl << "ROW: " << row << "COL: " << col << endl;
            }
            tempBoard->copyBoard(b);
        }
        cout << "MaxScore: " << maxScore << endl;
        if (maxScore < minMaxScore) {
            minMaxScore = maxScore;
            minRow = row;
            minCol = col;
        }
    }

    logic->setAvailableMoves(backUp);
    delete(tempBoard);
    cout << endl << endl;
    printer->printBoard(b);
    cout << endl << "ROW: " << minRow << "COL: " << minCol<< endl;
return Coordinate(minRow ,minCol);
}