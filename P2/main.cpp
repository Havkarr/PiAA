//g++ main.cpp ./graph/G_list.cpp ./graph/matrix.cpp ./algorithm/Dijkstra.cpp -o main

#include "./graph/matrix.hpp"
#include "./graph/G_list.hpp"
#include "./algorithm/Dijkstra.hpp"
#include <string>
#include <cstdlib>
#include <iostream>
#include <chrono>


using namespace std;


void generateGraph(Mat::matrixGraph &g, int n, int d)
{
    // Dodawanie krawędzi
    string name = "Vertex_";
    for (int i = 0; i < n; i++)
    {
        name = name + to_string(i);
        g.insertVertex(name);
        name = "Vertex_";
    }

    srand(time(NULL));

    int edgesCount = 0; // Liczba krawedzi w grafie
    int vertexCount = g.vertices(false).size(); // Liczba wierzchołków
    float density = 0; // Gestość grafu
    string v2 = "Vertex_";
    int num = 0; 
    
    // Uzupełnij graf o losowe krawedzie
    while (density < float(d)/100)
    {
        num = rand() % n;
        name = name + to_string(num);
        num = rand() % n;
        v2 = v2 + to_string(num);

        if (name != v2 && !g.areAdjacent(name, v2))
        {
            g.insertEdge(name, v2, (rand()%500)+1);
        }

        name = "Vertex_";
        v2 = "Vertex_";
        edgesCount = g.edges(false).size();
        density = (2 * edgesCount)/float(vertexCount * (vertexCount-1));
    }
}

void generateGraph(List::listGraph &g, int n, int d)
{
    // Dodawanie krawędzi
    string name = "Vertex_";
    for (int i = 0; i < n; i++)
    {
        name = name + to_string(i);
        g.insertVertex(name);
        name = "Vertex_";
    }

    srand(time(NULL));

    int edgesCount = 0;
    int vertexCount = g.vertices(false).size();
    float density = 0;
    string v2 = "Vertex_";
    int num = 0;
    
    // Uzupełnij graf o losowe krawedzie
    while (density < float(d)/100)
    {
        num = rand() % n;
        name = name + to_string(num);
        num = rand() % n;
        v2 = v2 + to_string(num);

        if (name != v2 && !g.areAdjacent(name, v2))
        {
            g.insertEdge(name, v2, (rand()%500)+1);
        }

        name = "Vertex_";
        v2 = "Vertex_";
        edgesCount = g.edges(false).size();
        density = (2 * edgesCount)/float(vertexCount * (vertexCount-1));
    }
}

Mat::matrixGraph mg;
List::listGraph lg;

int main(void)
{
    cout << "Podaj liczbe wierzcholkow dla grafu na liscie sasiedztwa: ";
    int n=0, den=0;
    cin >> n;
    cout << "Podaj gestosc dla grafu na liscie sasiedztwa (liczba z przedzialu 0-100): ";
    cin >> den;

    if (n < 0 )
    {
        cout << "\nPodano zla liczbe wierzcholkow.\n";
        return 1;
    }
    else if( den < 0 || den > 100 )
    {
        cout << "\nPodano zla gestosc grafu.\n";
        return 1; 
    }
    
    cout << "\nGraf na liscie sasiedztwa:\n";
    generateGraph(lg, n, den);
    cout << "Wierzcholki w grafie:\n" << "____________________________________________\n";
    lg.vertices(1);
    cout << "\nKrawedzie w grafie:\n" << "____________________________________________\n";
    lg.edges(1);
    cout << "\nAlgorytm Dijkstry dla grafu na liscie sasiedztwa:\n" << "____________________________________________\n";
    Dijkstra(lg,0);

    // Graf na macierzy

    cout << "Podaj liczbe wierzcholkow dla grafu na macierzy sasiedztwa: ";
    cin >> n;
    cout << "Podaj gestosc dla grafu na macierzy sasiedztwa (liczba z przedzialu 0-100): ";
    cin >> den;

    if (n < 0 || isalpha(n) )
    {
        cout << "\nPodano zla liczbe wierzcholkow.\n";
        return 1;
    }
    else if( den < 0 || den > 100 || isalpha(den))
    {
        cout << "\nPodano zla gestosc grafu.\n";
        return 1; 
    }
    
    cout << "\nGraf na macierzy sasiedztwa:\n";
    generateGraph(mg, n, den);
    cout << "Wierzcholki w grafie:\n" << "____________________________________________\n";
    mg.vertices(1);
    cout << "\nKrawedzie w grafie:\n" << "____________________________________________\n";
    mg.edges(1);
    cout << "\nAlgorytm Dijkstry dla grafu na macirzy sasiedztwa:\n" << "____________________________________________\n";
    Dijkstra(mg,0);
    
    return 0;
}