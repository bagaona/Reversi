# Or Paz	
# 311250708

a.out: compileAll
	g++ *.o 

	
compileAll: *.h *.cpp
	g++ -c *.cpp

clean:
	rm -f *.o



