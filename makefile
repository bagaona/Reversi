
a.out: compileAll
	g++ *.o 
	rm -f *.o

compileAll: include/*.h src/*.cpp
	g++ -c src/*.cpp

clean:
	rm -f *.o


