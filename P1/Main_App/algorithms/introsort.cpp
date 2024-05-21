#include "introsort.hpp"
#include "quick_sort.hpp"
#include "..\structure.hpp"
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;


void intro_sort(vector<movie>* list)
{
    int size = list->size();
    // Oblicz glebokosc rekursji
    int dl = 2*log2(size);

    quick_sort_mod(list,0,size-1,dl);
    // Poukladaj ostatnie dane za pomoca intro sort
    insert_sort(list, size);
}

void quick_sort_mod(vector<movie>* list, int start, int end, int depth_limit)
{
    if(end <= start)
    {return;}
    if (depth_limit == 0)
    {
        heap_sort(list);
        return;
    }
    
    int i = start - 1, j = end + 1;

    // a - ocena pierwszego elementu na liscie
    float a = list->at(start).grade;
    // b - ocena srodkowego filmu na liscie
    float b = list->at((end + start)/2).grade;
    // c - ocena ostatniego filmu na liscie
    float c = list->at(end).grade;
    float pivot = 5;

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
        quick_sort_mod(list, start, j, depth_limit-1);
    }
    if (i < end)
    {
        quick_sort_mod(list, i, end, depth_limit-1);
    }
}

// Sortowanie przez kopcowanie
void heap_sort(vector<movie>* list)
{
    int n = list->size();

    // Buduj maksymalny kopiec zaczynajac od rodziców
    for (int i = (n/2)+1; i >=0; --i)
    {
        build_max_heap(list, n, i);
    }

    for (int i = n - 1; i > 0; --i)
    {
        swap(list->at(i), list->at(0));
        build_max_heap(list, --n, 0);
    }
}

// Budowanie maksymalnego kopca (heapify)
void build_max_heap(vector<movie>* list, int size, int parent)
{
    int max = parent;   // Tymczasowa wartość maksymalna
    int left = max*2 + 1;   // Lewe dziecko
    int right = max*2 +2;   // Prawe dziecko

    // Ustaw największą wartość jako korzeń poddrzewa 
    if (left < size && list->at(left).grade > list->at(max).grade)
    {
        max = left;
    }
    if (right < size && list->at(right).grade > list->at(max).grade)
    {
        max = right;
    }

    if(max != parent)
    {
        swap(list->at(max), list->at(parent));
    }

}

// Sortowanie przez wstawianie
void insert_sort(vector<movie>* list, int size)
{
    int i,j;
    movie temp;
    for (i = 1; i < size; i++)
    {
        temp = list->at(i);
        // Przesuwaj filmy z mniejszymy ocenami w dół
        for (j = i; j > 0 && temp.grade < list->at(j-1).grade; --j)
        {
            list->at(j) = list->at(j-1);
        }
        list->at(j)=temp;
    }
}