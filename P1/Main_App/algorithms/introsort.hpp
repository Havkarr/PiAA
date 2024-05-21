#ifndef _Introsort_HPP_
#define _Introsort_HPP_
#include <vector>
#include "..\structure.hpp"

/**
* Funkcja która będzie odpowiadała
* za rekurencyjne dzielenie tablicy na mniejsze. 
* @param list oryginalna lista z filmami
* @param start początek tablicy
* @param end koniec tablicy
* @param depth_limit limit ilości rekursji. Przykładowa wartość to 2log2(n), 
* gdzie: n - liczba elementów do posortowania.
* @return Funkcja nie zwraca argumentów. 
*/
void quick_sort_mod(std::vector<movie>* list, int start, int end, int depth_limit);

/**
* Funkcja która odpowiada za posortowanie mniejszych tablic.
* Funkcja sortuje za pomocą algorytmu kopcowania. 
* @param list oryginalna lista z filmami
* @return Funkcja nie zwraca argumentów. 
*/
void heap_sort(std::vector<movie>* list);

/**
* Funkcja pomocnicza budująca maksymalny kopiec.
* @param list oryginalna lista z filmami
* @param size rozmiar kopca
* @param parent index korzenia
* @return Funkcja nie zwraca argumentów. 
*/
void build_max_heap(std::vector<movie>* list, int size, int parent);

/**
* Główna funkcja która sortujedane za pomocą 
* insert sorta i zmodyfikowanej wersji quick sorta.
* @param list oryginalna lista z filmami
* @return Funkcja nie zwraca argumentów. 
*/
void intro_sort(std::vector<movie>* list);

/**
* Funkcja która odpowiada za ostateczne uszeregowanie wartości
* na liście.
* @param list oryginalna lista z filmami
* @param size rozmiar listy
* @return Funkcja nie zwraca argumentów. 
*/
void insert_sort(std::vector<movie>* list, int size);

#endif