#include "Dijkstra.hpp"
#include "../graph/G_list.hpp"
#include "../graph/matrix.hpp"
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector<route> Dijkstra(Mat::matrixGraph graph, int indV)
{
    // Załaduj dane o grafie potrzebne do jego przebadania
    vector<Mat::Vertex> V = graph.vertices(false);
    vector<Mat::Edge> E = graph.edges(false);
    vector<vector<int>> M = graph.vg(false);

    // Stwórz strukturę która przechowa dane o drodze do wierzchołków
    vector<route> routes;
    route r; 

    // Stwórz pomocnicze struktury 
    vector<int> distance(V.size(), INT_MAX);
    vector<int> previous(V.size(), -1);
    vector<bool> visited(V.size(), false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Dodaj pierwszy wierzchołek grafu do kolejki priorytetowej
    distance[indV] = 0;
    pq.push(make_pair(0,indV));

    while (!pq.empty()) 
    {
        // Pobierz dane o wierzchołku
        int currentDistance = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();

        // Jeżeli wierzchołek był już odwiedzony to pomiń go
        if (visited[currentVertex] == true)
        {
            continue;
        }
        visited[currentVertex] = true;
            
        // Sprawdź odległość wierzchołka do innych wierzchołków
        for (int i = 0; i < M[currentVertex].size(); i++)
        {
            // Sprawdź w macierzy sąsiedztwa czy istnieje krawędź między wierzchołkami
            if (M[currentVertex][i] < 0)
            {
                continue;
            }
            
            int nextVertex = i;
            int newDistance = currentDistance + E[M[currentVertex][i]].value;
            
            // Dodaj krótszą drogę jeśli taką znalazłeś
            if (newDistance < distance[nextVertex]) 
            {
                distance[nextVertex] = newDistance;
                previous[nextVertex] = currentVertex;
                pq.push(make_pair(newDistance, nextVertex));
            }
        }
    }
    
    // Uzupełnij strukturę do zwrotu danych
    for (int j = 0; j < V.size(); j++)
    {
        r.name = V[j].name;
        r.distance = distance[j];
        r.indexV = previous[j];
        // Jeżeli wierzchołek nie został odwiedzony to nie dodawaj go do wektora
        if (r.distance == INT_MAX)
        {
            continue;
        }
        
        routes.push_back(r);
    }
    
    // Wyświetlanie ścieżek
    for (int k = 0; k < routes.size(); k++)
    {
        if (routes[k].indexV < 0)
        {
            cout << "Start: "<< routes[k].name << ": " << routes[k].distance << endl;
            continue;
        }
        
        cout << V[routes[k].indexV].name << "->" << routes[k].name << ": " << routes[k].distance << endl;
    }

    return routes;
}

vector<route> Dijkstra(Mat::matrixGraph graph, int indV, int endV)
{
    // Załaduj dane o grafie potrzebne do jego przebadania
    vector<Mat::Vertex> V = graph.vertices(false);
    vector<Mat::Edge> E = graph.edges(false);
    vector<vector<int>> M = graph.vg(false);

    // Stwórz strukturę która przechowa dane o drodze do wierzchołków
    vector<route> routes;
    route r;

    // Stwórz pomocnicze struktury 
    vector<int> distance(V.size(), INT_MAX);
    vector<int> previous(V.size(), -1);
    vector<bool> visited(V.size(), false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Dodaj pierwszy wierzchołek grafu do kolejki priorytetowej
    distance[indV] = 0;
    pq.push(make_pair(0,indV));

    while (!pq.empty()) 
    {
        // Pobierz dane o wierzchołku
        int currentDistance = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();

        // Jeżeli wierzchołek był już odwiedzony to pomiń go
        if (visited[currentVertex] == true)
        {
            continue;
        }
        visited[currentVertex] = true;

        // Sprawdź odległość wierzchołka do innych wierzchołków
        for (int i = 0; i < M[currentVertex].size(); i++)
        {
            // Sprawdź w macierzy sąsiedztwa czy istnieje krawędź między wierzchołkami
            if (M[currentVertex][i] < 0)
            {
                continue;
            }
            
            int nextVertex = E[M[currentVertex][i]].start->index == currentVertex ? E[M[currentVertex][i]].end->index : E[M[currentVertex][i]].start->index;
            int newDistance = currentDistance + E[M[currentVertex][i]].value;
            // Dodaj krótszą drogę jeśli taką znalazłeś
            if (newDistance < distance[nextVertex]) 
            {
                distance[nextVertex] = newDistance;
                previous[nextVertex] = currentVertex;
                pq.push(make_pair(newDistance, nextVertex));
            }
        }

        if (visited[endV] == true)
        {
            break;
        }
        
    }

    // Uzupełnij strukturę do zwrotu danych
    for (int j = 0; j < V.size(); j++)
    {
        r.name = V[j].name;
        r.distance = distance[j];
        r.indexV = previous[j];
        // Jeżeli wierzchołek nie został odwiedzony to nie dodawaj go do wektora
        if (r.distance == INT_MAX)
        {
            continue;
        }
        routes.push_back(r);
    }

    int temp = endV;
    string rt;
    while (temp >= 0)
    {
        rt = V[previous[temp]].name + " --> " + V[temp].name + "; " + rt;
        temp = previous[temp];
    }
    cout << rt << " distance: " << distance[endV] << endl;

    return routes;
}

vector<route> Dijkstra(List::listGraph graph, int indV)
{
    // Załaduj dane o grafie potrzebne do jego przebadania
    vector<List::Vertex> V = graph.vertices(false);
    vector<List::Edge> E = graph.edges(false);
    
    // Stwórz strukturę która przechowa dane o drodze do wierzchołków
    vector<route> routes;
    route r;

    // Stwórz pomocnicze struktury 
    vector<int> distance(V.size(), INT_MAX);
    vector<int> previous(V.size(), -1);
    vector<bool> visited(V.size(), false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Dodaj pierwszy wierzchołek grafu do kolejki priorytetowej
    distance[indV] = 0;
    pq.push(make_pair(0,indV));
    
    while (!pq.empty()) 
    {
        // Pobierz dane o wierzchołku
        int currentDistance = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();

        // Jeżeli wierzchołek był już odwiedzony to pomiń go
        if (visited[currentVertex] == true)
        {
            continue;
        }
        visited[currentVertex] = true;

        // Sprawdź odległość wierzchołka do innych wierzchołków
        for (int i = 0; i < V[currentVertex].incList.size(); i++)
        {
            if (V[currentVertex].incList[i] < 0)
            {
                continue;
            }
            
            int nextVertex = E[V[currentVertex].incList[i]].start->index == currentVertex ? E[V[currentVertex].incList[i]].end->index : E[V[currentVertex].incList[i]].start->index;
            int newDistance = currentDistance + E[V[currentVertex].incList[i]].value;
            // Dodaj krótszą drogę jeśli taką znalazłeś
            if (newDistance < distance[nextVertex]) 
            {
                distance[nextVertex] = newDistance;
                previous[nextVertex] = currentVertex;
                pq.push(make_pair(newDistance, nextVertex));
            }
        }
    }

    // Uzupełnij strukturę do zwrotu danych
    for (int j = 0; j < V.size(); j++)
    {
        r.name = V[j].name;
        r.distance = distance[j];
        r.indexV = previous[j];
        // Jeżeli wierzchołek nie został odwiedzony to nie dodawaj go do wektora
        if (r.distance == INT_MAX)
        {
            continue;
        }
        routes.push_back(r);
    }
    
    // Wyświetlanie ścieżek
    for (int k = 0; k < routes.size(); k++)
    {
        if (routes[k].indexV < 0)
        {
            cout << "Start: "<< routes[k].name << ": " << routes[k].distance << endl;
            continue;
        }
        
        cout << V[routes[k].indexV].name << "->" << routes[k].name << ": " << routes[k].distance << endl;
    }

    return routes;
}

vector<route> Dijkstra(List::listGraph graph, int indV, int endV)
{
    // Załaduj dane o grafie potrzebne do jego przebadania
    vector<List::Vertex> V = graph.vertices(false);
    vector<List::Edge> E = graph.edges(false);
    
    // Stwórz strukturę która przechowa dane o drodze do wierzchołków
    vector<route> routes;
    route r;

    // Stwórz pomocnicze struktury 
    vector<int> distance(V.size(), INT_MAX);
    vector<int> previous(V.size(), -1);
    vector<bool> visited(V.size(), false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Dodaj pierwszy wierzchołek grafu do kolejki priorytetowej
    distance[indV] = 0;
    pq.push(make_pair(0,indV));
    
    while (!pq.empty()) 
    {
        // Pobierz dane o wierzchołku
        int currentDistance = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();

        // Jeżeli wierzchołek był już odwiedzony to pomiń go
        if (visited[currentVertex] == true)
        {
            continue;
        }
        visited[currentVertex] = true;

        // Sprawdź odległość wierzchołka do innych wierzchołków
        for (int i = 0; i < V[currentVertex].incList.size(); i++)
        {
            if (V[currentVertex].incList[i] < 0)
            {
                continue;
            }

            int nextVertex = E[V[currentVertex].incList[i]].start->index == currentVertex ? E[V[currentVertex].incList[i]].end->index : E[V[currentVertex].incList[i]].start->index;
            int newDistance = currentDistance + E[V[currentVertex].incList[i]].value;
            // Dodaj krótszą drogę jeśli taką znalazłeś
            if (newDistance < distance[nextVertex]) 
            {
                distance[nextVertex] = newDistance;
                previous[nextVertex] = currentVertex;
                pq.push(make_pair(newDistance, nextVertex));
            }
        }

        if (visited[endV] == true)
        {
            break;
        }
        
    }

    // Uzupełnij strukturę do zwrotu danych
    for (int j = 0; j < V.size(); j++)
    {
        r.name = V[j].name;
        r.distance = distance[j];
        r.indexV = previous[j];
        // Jeżeli wierzchołek nie został odwiedzony to nie dodawaj go do wektora
        if (r.distance == INT_MAX)
        {
            continue;
        }
        routes.push_back(r);
    }

    int temp = endV;
    string rt;
    while (temp >= 0)
    {
        rt = V[previous[temp]].name + " --> " + V[temp].name + "; " + rt;
        temp = previous[temp];
    }
    cout << rt << " distance: " << distance[endV] << endl;

    return routes;
}