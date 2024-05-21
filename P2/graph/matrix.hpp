#pragma once
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

namespace Mat
{
    struct Vertex{
        int index;
        string name;
    };
    struct Edge{
        int value;
        int index;
        Vertex* start;
        Vertex* end;
    };

    class matrixGraph
    {
        private:
            vector<Vertex> Verticies;
            vector<Edge> Edges;
            vector<vector<int>> matrix;
            priority_queue<int, vector<int>, greater<int>> indicators_vertex;
            priority_queue<int, vector<int>, greater<int>> indicators_edge;
            string retTab[2];

        public:
            /**
            * Konstruktor. Jedyną jego funkcją jest zainicjalizowanie pierwszych wartości
            * w kolejkach priorytetowych odpowiadajacych za przydzielanie indeksow do wierzcholkow
            * i krawedzi 
            */
            matrixGraph(); 

            /**
            * Funkcja testowa, służy do wizualizacji macierzy sąsiedztwa.
            * @param print jesli print = true, funkcja wypisze dane w terminalu
            */
            vector<vector<int>> vg(bool print);

            /**
            * Funkcja dodajaca wierzcholek do grafu.
            * @param name - nazwa dodawanego wierzcholka 
            */
            void insertVertex(string name);  
            
            /**
            * Funkcja dodająca krawędź do grafu.
            * @param start - nazwa początkowego wierzchołka 
            * @param end - nazwa końcowgo wierzchołka
            * @param val - waga krawędzi
            */
            void insertEdge(string start, string end, int val);  

            /**
            * Funkcja umożliwia używanie w funkcjach nazw wierzchołków zamiast wskaźników na nie.
            * Ma to na celu poprawienie przejrzystości funkcji i ułatwieniu ich używania.
            * @param name - nazwa szukanego wierzchołka 
            * @return wskaźnik na szukany wierzchołek
            */
            Vertex* findVertex(string name); 

            /**
            * Funkcja usuwająca krawędź z grafu.
            * @param index - Indeks usuwanej krawędzi 
            */
            void removeEdge(int index); 

            /**
            * Funkcja usuwająca wierzchołek z grafu.
            * @param name - nazwa usuwanego wierzchołka 
            */
            void removeVertex(string name); 

            /**
            * Wypisuje wszystkie wierzchołki w grafie wraz z ich indeksami w wektorze Verticies. 
            * @param print jesli print = true, funkcja wypisze dane w terminalu
            */
            vector<Vertex> vertices(bool print); 

            /**
            * Wypisuje wszystkie krawędzie w grafie do terminalu. Format wypisywania jest następujący:
            * Indeks. wierzchołek startowy -> wierzchołek końcowy: waga krawędzi 
            * @param print jesli print = true, funkcja wypisze dane w terminalu
            */
            vector<Edge> edges(bool print); 

            /**
            * Funkcja zwraca krawędzie przylegające do podanego wierzchołka
            * @param name - nazwa wierzcholka 
            * @return wektor zawierający wskaźniki na krawędzie przylegające do danego wierzchołka
            */
            vector<Edge*> incidentEdges(string name); 

            /**
            * Funkcja podaje dwa końcowe wierzchołki krawędzi o indeksie e.
            * @param e - indeks krawedzi
            * @return wskaźnik do tablicy zawierającej nazwy 2 wierzchołków krawędzi e 
            */
            string* endVertices(int e);  

            /**
            * Funkcja zwraca wierzchołek przeciwny do podanego wierzchołka względem krawędzi o indeksie e.
            * @param v - nazwa wierzcholka 
            * @param e - indeks krawedzi
            * @return nazwa wierzhołka przeciwngo do v
            */
            string oppoiste(string v, int e); 

            /**
            * Sprawdza czy dwa wierzchołki są sąsiednie
            * @param v1 - nazwa wierzchołka nr 1
            * @param v2 - nazwa wierzchołka nr 2
            * @return wartość true/false
            */
            bool areAdjacent(string v1, string v2); 

            /**
            * Funkcja zmienia nazwe wierzchołka v.
            * @param v - nazwa wierzchołka istniejącego
            * @param r - nowa nazwa wierzchołka
            */
            void replaceVertex(string v, string r);  
  
            /**
            * Funkcja zmienia wagę krawędzi o podanym indeksie.
            * @param index - indeks krawedzi
            * @param newVal - nowa waga krawędzi 
            */
            void replaceEdge(int index, int newVal); 
    };
} 
