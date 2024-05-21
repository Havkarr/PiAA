
output: main.o introsort.o merge_sort.o quick_sort.o 
	g++ main.o introsort.o merge_sort.o quick_sort.o -o MainApp 

main.o: main.cpp
	g++ -c main.cpp

introsort.o: algorithms\introsort.cpp algorithms\introsort.hpp
	g++ -c algorithms\introsort.cpp

merge_sort.o: algorithms\merge_sort.cpp algorithms\merge_sort.hpp
	g++ -c algorithms\merge_sort.cpp

quick_sort.o: algorithms\quick_sort.cpp algorithms\quick_sort.hpp
	g++ -c algorithms\quick_sort.cpp

clean:
	rm *.o output
    