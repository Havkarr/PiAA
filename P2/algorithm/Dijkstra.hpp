#pragma once
#include "../graph/G_list.hpp"
#include "../graph/matrix.hpp"
#include <vector>

struct route
{
    std::string name; // Nazwa wierzchołka
    int indexV; // Indeks poprzedniego wierzchołka
    int distance; // Odległość od punktu startowego 
};

/**
* Funkcja realizująca algorytm Dijkstry
* @param graph graf zaimplementowany za pomocą macierzy sąsiedztwa
* @param indV indeks wierzchołka startowego
* @return wektor obiektów route które zawierają: nazwe wierzchołka,
* krawędź po której dostaniemy się do tego wierzchołka oraz jego 
* odległość od punktu początkowego. 
*/
vector<route> Dijkstra(Mat::matrixGraph graph, int indV);

/**
* Funkcja realizująca algorytm Dijkstry
* @param graph graf zaimplementowany za pomocą macierzy sąsiedztwa
* @param indV indeks wierzchołka startowego
* @param endV indeks wierzchołka końcowego
* @return wektor obiektów route które zawierają: nazwe wierzchołka,
* krawędź po której dostaniemy się do tego wierzchołka oraz jego 
* odległość od punktu początkowego. 
*/
vector<route> Dijkstra(Mat::matrixGraph graph, int indV, int endV);

/**
* Funkcja realizująca algorytm Dijkstry
* @param graph graf zaimplementowany za pomocą listy sąsiedztwa
* @param indV indeks wierzchołka startowego
* @return wektor obiektów route które zawierają: nazwe wierzchołka,
* krawędź po której dostaniemy się do tego wierzchołka oraz jego 
* odległość od punktu początkowego. 
*/
vector<route> Dijkstra(List::listGraph graph, int indV);

/**
* Funkcja realizująca algorytm Dijkstry który szuka najkrótszej 
* ścieżki pomiędzy 2 wierzchołkami.
* @param graph graf zaimplementowany za pomocą listy sąsiedztwa
* @param indV indeks wierzchołka startowego
* @param endV indeks wierzchołka końcowego
* @return wektor obiektów route które zawierają: nazwe wierzchołka,
* krawędź po której dostaniemy się do tego wierzchołka oraz jego 
* odległość od punktu początkowego. 
*/
vector<route> Dijkstra(List::listGraph graph, int indV, int endV);