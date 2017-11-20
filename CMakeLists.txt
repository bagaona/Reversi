cmake_minimum_required(VERSION 3.8)
project(Reversi)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Board.cpp Board.h ConsolePrinter.cpp ConsolePrinter.h GameManager.cpp GameManager.h HumanPlayer.cpp HumanPlayer.h Logic.cpp Logic.h NormalLogic.cpp NormalLogic.h
        Coordinate.cpp Coordinate.h Player.cpp Player.h Printer.cpp Printer.h ComputerPlayer.cpp ComputerPlayer.h)
add_executable(Reversi ${SOURCE_FILES})