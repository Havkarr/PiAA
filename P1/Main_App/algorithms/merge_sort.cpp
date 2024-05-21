#include "merge_sort.hpp"
#include "..\structure.hpp"
#include <vector>
#include <iostream>


using namespace std;


void merge_sort(vector<movie>* list)
{
    int lenght = list->size();
    if (lenght <= 1)
    {
        return;
    }
    int middle = lenght/2;

    vector<movie> left_vec;
    vector<movie> right_vec;

    // Podziel liste na 2 mniejsze podzbiory
    for (int i = 0; i < lenght; i++)
    {
        if(i < middle){
            left_vec.push_back(list->at(i));}
        else{
            right_vec.push_back(list->at(i));}
    }

    merge_sort(&left_vec);
    merge_sort(&right_vec);
    merge(list, left_vec, right_vec);

    return;
}

void merge(vector<movie>* list, vector<movie> left, vector<movie> right)
{
    int size = list->size();
    int left_size = size/2, right_size = size - left_size;

    int l = 0; // Lewy wektor
    int r = 0; // Prawy wektor
    int i = 0; // Główna lista

    // Sortuj oba wektory
    while (l < left_size && r < right_size)
    {
        if (left[l].grade <= right[r].grade)
        {
            list->at(i) = left[l];
            ++l;++i;
        }
        else
        {
            list->at(i) = right[r];
            ++r;++i;
        }
    }
    
    // Gdy jeden bedzie pusty, skopiuj drugi do listy.
    while (l < left_size)
    {
        list->at(i) = left[l];
        ++l;++i;
    }
    while (r < right_size)
    {
        list->at(i) = right[r];
        ++r;++i;
    }
    
    return;
}