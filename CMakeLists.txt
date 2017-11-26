cmake_minimum_required(VERSION 3.8)
project(Reversi)

set(CMAKE_CXX_STANDARD 98)
add_subdirectory(lib/google_tests)
include_directories(lib/google_tests/googletest/include)
include_directories(lib/google_tests/googlemock/include)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_FILES tests/main_test.cpp tests/test_Board.cpp tests/test_NormalLogic.cpp tests/test_ComputerPlayer.cpp tests/test_Coordinate.cpp tests/test_Coordinate.cpp)
set(SOURCE_FILES main.cpp Board.cpp Board.h Cell.cpp Cell.h ConsolePrinter.cpp ConsolePrinter.h GameManager.cpp GameManager.h HumanPlayer.cpp HumanPlayer.h Logic.cpp Logic.h NormalLogic.cpp NormalLogic.h
        Coordinate.cpp Coordinate.h Player.cpp Player.h Printer.cpp Printer.h ComputerPlayer.cpp ComputerPlayer.h)

add_executable(Reversi ${SOURCE_FILES} main.cpp)
add_executable(TestGame ${TEST_FILES} ${SOURCE_FILES} tests/main_test.cpp)
target_link_libraries(TestGame gtest gtest_main)