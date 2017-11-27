#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/NormalLogic.h"

TEST(NormalLogicTest, AvailableMoves) {
    Board* board =new Board(8,'X','O');
    NormalLogic logic(board);

}