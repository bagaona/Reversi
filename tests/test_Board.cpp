#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Board.h"
#include "BoardTest.h"

TEST_F(BoardTest, CellTest) {
    Coordinate c(5,5);
    board.update(c,'X');
    EXPECT_EQ(board.getValue(5, 5), 'X');
    board.update(5, 5, 'O');
    EXPECT_EQ(board.getValue(5, 5), 'O');
}
TEST_F(BoardTest, InvalidIndexTest) {
    EXPECT_EQ(board.getValue(3, 3), 'O');
    EXPECT_EQ(board.getValue(4, 4), 'O');
    EXPECT_EQ(board.getValue(3, 4), 'X');
    EXPECT_EQ(board.getValue(4, 3), 'X');
}




TEST_F(BoardTest, Starting_postion) {
    EXPECT_EQ(board.getValue(3, 3), 'O');
    EXPECT_EQ(board.getValue(4, 4), 'O');
    EXPECT_EQ(board.getValue(3, 4), 'X');
    ASSERT_EQ(board.getValue(4, 3), 'X');
}

TEST_F(BoardTest, CopyConstructor) {
    Board* b = new Board(8, 'X', 'O');
    Board b2(b);
    EXPECT_EQ(b2.getValue(3, 3), 'O');
    EXPECT_EQ(b2.getValue(4, 4), 'O');
    EXPECT_EQ(b2.getValue(3, 4), 'X');
    ASSERT_EQ(b2.getValue(4, 3), 'X');
}


