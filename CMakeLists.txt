cmake_minimum_required(VERSION 3.8)
project(Reversi)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
set(CMAKE_CXX_STANDARD 98)
add_subdirectory(lib/google_tests)
include_directories(lib/google_tests/googletest/include)
include_directories(lib/google_tests/googlemock/include)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_FILES tests/main_test.cpp tests/test_Board.cpp tests/test_NormalLogic.cpp
        tests/test_ComputerPlayer.cpp tests/test_Coordinate.cpp)

set(SOURCE_FILES src/Board.cpp include/Board.h src/Cell.cpp include/Cell.h
        src/ConsolePrinter.cpp include/ConsolePrinter.h src/GameManager.cpp
        include/GameManager.h src/HumanPlayer.cpp include/HumanPlayer.h
        src/Logic.cpp include/Logic.h src/NormalLogic.cpp include/NormalLogic.h
        src/Coordinate.cpp include/Coordinate.h src/Player.cpp include/Player.h
        src/Printer.cpp include/Printer.h src/ComputerPlayer.cpp include/ComputerPlayer.h)

add_executable(Reversi ${SOURCE_FILES} src/main.cpp)
add_executable(TestGame ${TEST_FILES} ${SOURCE_FILES} ${TEST_FILES} tests/main_test.cpp)
target_link_libraries(TestGame gtest gtest_main pthread)









