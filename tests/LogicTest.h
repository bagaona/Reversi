//
// Created by amir on 27/11/17.
//

#ifndef REVERSI_LOGICTEST_H
#define REVERSI_LOGICTEST_H
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Board.h"
#include "../include/Logic.h"
#include "../include/NormalLogic.h"

using namespace std;


class LogicTest: public testing::Test {
public:

    LogicTest(){
    }

    virtual void SetUp() {
        cout << "Setting up" << endl;
        b = new Board(8, 'X', 'O');
        logic = new NormalLogic(b);
    }
    virtual void TearDown() {
        cout << "Tearing down" << endl;
        delete (b);
        delete(logic);
    }

protected:
    Logic* logic;
    Board* b;
};



#endif //REVERSI_LOGICTEST_H
