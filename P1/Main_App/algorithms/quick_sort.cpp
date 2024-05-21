#include "quick_sort.hpp"
#include "..\structure.hpp"
#include <vector>
#include <iostream>


using namespace std;


void quick_sort(vector<movie>* list, int start, int end)
{
    if(end <= start)
    {return;}

    int i = start - 1, j = end + 1;

    // a - ocena pierwszego elementu na liscie
    float a = list->at(start).grade;
    // b - ocena srodkowego filmu na liscie
    float b = list->at((end + start)/2).grade;
    // c - ocena ostatniego filmu na liscie
    float c = list->at(end).grade;
    int pivot = 5;

    // Zamien ostatni element z mediana
    if ((a >= b && a <=c) || (a <= b && a >=c))
    {
        // Pierwszy element jest mediana
        pivot = a;

    }
    else if ((b >= a && b <=c) || (b >= a && b <=c))
    {
        // Srodkowy element jest mediana
        pivot = b;
    }    
    else
    {
        // Ostatni element jest mediana
        pivot = c;
    }
    

    // Przesuwaj elementy na liście względem pivotu
    while (1)
    {
        while (pivot > list->at(++i).grade);
        while (pivot < list->at(--j).grade);

        if (i <= j)
        {
            swap(list->at(i), list->at(j));
        }
        else
        {
            break;
        }
    }
    
    if (j > start)
    {
        quick_sort(list, start, j);
    }
    if (i < end)
    {
        quick_sort(list, i, end);
    }
    

}
