#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Board.h"
#include "../include/Logic.h"
#include "LogicTest.h"

//Test That the available moves get values and not staying empty
TEST_F(LogicTest, HasMoves) {
    set<Coordinate> availableMoves = logic->availableMoves('X');
    EXPECT_EQ(availableMoves.empty(), false);
}
//Test that illegal move will be handle
TEST_F(LogicTest, IsLegalMove) {
    set<Coordinate> availableMoves = logic->availableMoves('X');
    Coordinate c(1,1);
    EXPECT_EQ(logic->isLegal(c), false);
}

//Test that the availableMoves-set contains the real available moves
TEST_F(LogicTest, AvailableMoves) {
    Coordinate c(2,3);
    Coordinate c2(3,2);
    Coordinate c3(4,5);
    Coordinate c4(5,4);
    set<Coordinate> availableMoves = logic->availableMoves('X');
    std::set<Coordinate>::iterator it;
    it = availableMoves.begin();
    EXPECT_EQ((*it), c);
    it++;
    EXPECT_EQ((*it), c2);
    it++;
    EXPECT_EQ((*it), c3);
    it++;
    EXPECT_EQ((*it), c4);
}

//Another test of legal moves, this time contains 1 legal and 1 not
TEST_F(LogicTest, IsLegal) {
    set<Coordinate> availableMoves = logic->availableMoves('X');
    Coordinate c(1,1);
    EXPECT_EQ(logic->isLegal(c), false);
    Coordinate c2(2,3);
    EXPECT_EQ(logic->isLegal(c2), true);
}





