# 204313100
# Amir Bagaon

a.out: Board.o main.o GameManager.o Logic.o Player.o HumanPlayer.o NormalLogic.o ConsolePrinter.o Printer.o
	g++ GameManager.o Board.o main.o Logic.o Player.o HumanPlayer.o NormalLogic.o ConsolePrinter.o Printer.o

Board.o: Board.cpp Board.h
	g++ -c Board.cpp
GameManager.o: GameManager.cpp GameManager.h
	g++ -c GameManager.cpp
Logic.o: Logic.cpp Logic.h
	g++ -c Logic.cpp
Player.o: Player.cpp Player.h
	g++ -c Player.cpp
HumanPlayer.o: HumanPlayer.cpp HumanPlayer.h
	g++ -c HumanPlayer.cpp
NormalLogic.o: NormalLogic.cpp NormalLogic.h
	g++ -c NormalLogic.cpp
Printer.o: Printer.cpp Printer.h
	g++ -c Printer.cpp
ConsolePrinter.o: ConsolePrinter.cpp ConsolePrinter.h
	g++ -c ConsolePrinter.cpp
main.o: main.cpp GameManager.h HumanPlayer.h
	g++ -c main.cpp
