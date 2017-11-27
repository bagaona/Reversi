#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Board.h"

TEST(BoardTest, CellTest) {
    Board board(8,'X','O');
    Coordinate c(5,5);
    board.update(c,'X');
    EXPECT_EQ(board.getValue(5, 5), 'X');
    board.update(5, 5, 'O');
    EXPECT_EQ(board.getValue(5, 5), 'O');
}
TEST(BoardTest, InvalidIndexTest) {
    Board board(8,'X','O');
    EXPECT_EQ(board.getValue(3, 3), 'O');
    EXPECT_EQ(board.getValue(4, 4), 'O');
    EXPECT_EQ(board.getValue(3, 4), 'X');
    EXPECT_EQ(board.getValue(4, 3), 'X');
}





