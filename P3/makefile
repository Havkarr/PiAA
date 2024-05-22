output: main.o tic-tac-toe.o min-max.o
	g++ main.o tic-tac-toe.o min-max.o -o main

main.o: main.cpp
	g++ -c main.cpp

tic-tac-toe.o: board\tic-tac-toe.cpp board\tic-tac-toe.hpp
	g++ -c board\tic-tac-toe.cpp

min-max.o: algorithm\min-max.cpp algorithm\min-max.hpp
	g++ -c algorithm\min-max.cpp

clean:
	rm *.o output