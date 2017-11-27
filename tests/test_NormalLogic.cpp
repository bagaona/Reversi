#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Board.h"
#include "../include/Logic.h"
#include "../include/NormalLogic.h"
#include "LogicTest.h"

//LogicTest ::LogicTest() {}
//void LogicTest  ::SetUp() {}
//void LogicTest ::TearDown() {}

TEST_F(LogicTest, HasMoves) {
    set<Coordinate> availableMoves = logic->availableMoves('X');
    EXPECT_EQ(availableMoves.empty(), false);
}
TEST_F(LogicTest, IsLegalMove) {
    set<Coordinate> availableMoves = logic->availableMoves('X');
    Coordinate c(1,1);
    EXPECT_EQ(logic->isLegal(c), false);
}

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
TEST_F(LogicTest, IsLegal) {
    set<Coordinate> availableMoves = logic->availableMoves('X');
    Coordinate c(1,1);
    EXPECT_EQ(logic->isLegal(c), false);
    Coordinate c2(2,3);
    EXPECT_EQ(logic->isLegal(c2), true);
}
TEST_F(LogicTest, wow) {

}





