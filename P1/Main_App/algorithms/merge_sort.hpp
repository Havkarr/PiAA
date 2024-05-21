#ifndef _Merge_sort_HPP_
#define _Merge_sort_HPP_
#include <vector>
#include "..\structure.hpp"

/**
* Główna funkcja merge która będzie odpowiadała
* za rekurencyjne dzielenie tablicy na mniejsze. 
* @param list oryginalna lista z filmami
* @return Funkcja nie zwraca argumentów. 
*/
void merge_sort(std::vector<movie>* list);


/**
* Funkcja pomocnicza która będzie odpowiadała
* za złożenie tablic jednocześnie sortując je. 
* @param list oryginalna lista z filmami
* @param left lewa tablica
* @param right prawa tablica 
* @return Funkcja nie zwraca argumentów. 
*/
void merge(std::vector<movie>* list, std::vector<movie> left, std::vector<movie> right);

#endif