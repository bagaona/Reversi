#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Board.h"
#include "../include/Logic.h"
#include "ComputerTest.h"
#include "../include/ConsolePrinter.h"

//LogicTest ::LogicTest() {}
//void LogicTest  ::SetUp() {}
//void LogicTest ::TearDown() {}

TEST_F(ComputerTest, DoMove) {
    board->update(Coordinate(2,3), 'X');
    logic->flip(Coordinate(2,3), 'X');
    set<Coordinate> availableMoves = logic->availableMoves('O');
    Printer *printer = new ConsolePrinter();
    printer->printBoard(board);
    Coordinate makedMove(player.makeTurn(logic,board, printer , availableMoves));
    EXPECT_EQ(Coordinate(2,2), makedMove);
    board->update(makedMove, 'O');
    logic->flip(makedMove, 'O');
    logic-> endTurn();

    board->update(Coordinate(2,1), 'X');
    logic->flip(Coordinate(2,1), 'X');
    printer->printBoard(board);
    availableMoves = logic->availableMoves('O');
    Coordinate anotherMove(player.makeTurn(logic,board, printer , availableMoves));
    EXPECT_EQ(Coordinate(2,4), anotherMove);
}