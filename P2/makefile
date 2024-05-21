output: main.o Dijkstra.o G_list.o matrix.o
	g++ main.o Dijkstra.o G_list.o matrix.o -o main

main.o: main.cpp
	g++ -c main.cpp

Dijkstra.o: algorithm\Dijkstra.cpp algorithm\Dijkstra.hpp
	g++ -c algorithm\Dijkstra.cpp

G_list.o: graph\G_list.cpp graph\G_list.hpp
	g++ -c graph\G_list.cpp

matrix.o: graph\matrix.cpp graph\matrix.hpp
	g++ -c graph\matrix.cpp

clean:
	rm *.o output