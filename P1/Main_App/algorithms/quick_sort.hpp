#ifndef _Quick_sort_HPP_
#define _Quick_sort_HPP_
#include <vector>
#include "..\structure.hpp"

/**
* Główna funkcja która będzie odpowiadała
* za rekurencyjne dzielenie tablicy na mniejsze. 
* @param list oryginalna lista z filmami
* @param start początek tablicy
* @param end koniec tablicy
* @return Funkcja nie zwraca argumentów. 
*/
void quick_sort(std::vector<movie>* list, int start, int end);

#endif