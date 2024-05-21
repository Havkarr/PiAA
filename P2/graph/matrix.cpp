#include "matrix.hpp"
#include <vector>
#include <iostream>

using namespace std;

namespace Mat 
{
    Mat::matrixGraph::matrixGraph()
    {
        indicators_vertex.push(0);
        indicators_edge.push(0);
    }
    
    void Mat::matrixGraph::insertVertex(string name)
    {
        if (findVertex(name) != nullptr)
        {
            cout << "Taki wierzcholek juz istnieje\n";
            return;
        }

        // Stwórz nowy wierzchołek
        Vertex temp;
        temp.name = name;
        temp.index = indicators_vertex.top();

        // Dodaj wierzchołek do wektora 
        if (temp.index >= Verticies.size())
        {
            Verticies.push_back(temp);
            // Zaktualizuj kolejke indeksów
            indicators_vertex.push(indicators_vertex.top()+1);
        }
        else
        {
            Verticies[temp.index].index = temp.index;
            Verticies[temp.index].name = temp.name;
        }
        indicators_vertex.pop();
        // Jeżeli węzeł otrzymał index który był potrzebny poprzednio
        // to nie dodawaj nowej 
        if (temp.index < matrix.size())
        {
            return;
        }

        // Uaktualnij macierz sąsiedztwa
        matrix.push_back(vector<int>{-1});
        matrix[Verticies.size()-1].resize(matrix.size(),-1);

        for (int i = 0; i < Verticies.size(); ++i)
        {
            matrix[i].push_back(-1);
        }
    }

    void Mat::matrixGraph::insertEdge(string start, string end, int val)
    {
        Vertex* s = findVertex(start);
        Vertex* e = findVertex(end);
        
        if (s == nullptr || e == nullptr)
        {
            cout << "Nie ma takich wierzcholkow.\n";
            return;
        }
        if (matrix[s->index][e->index] >= 0)
        {
            cout << "Taka krawedz juz istnieje.\n";
            return;
        }
        // Stwórz nową krawędź
        Edge temp;

        temp.value = val;
        temp.start = s;
        temp.end = e;
        temp.index = indicators_edge.top();

        if (temp.index >= Edges.size())
        {
            Edges.push_back(temp);
            indicators_edge.push(indicators_edge.top()+1);
        }
        else
        {
            Edges[temp.index].index = temp.index;
            Edges[temp.index].value = temp.value;
            Edges[temp.index].start = temp.start;
            Edges[temp.index].end = temp.end;
        }
        indicators_edge.pop();

        // Zaktualizuj macierz sąsiedztwa
        matrix[s->index][e->index] = temp.index;
        matrix[e->index][s->index] = temp.index;
    }

    Vertex* Mat::matrixGraph::findVertex(string name)
    {        
        for (int i = 0; i < Verticies.size(); i++)
        {
            if (Verticies[i].name == name)
            {
                return &Verticies[i];
            }
        }   
    
        return nullptr;
    }

    void Mat::matrixGraph::removeEdge(int index)
    {
        if (index >= Edges.size())
        {
            cout << "Podano zly index.\n";
            return;
        }
        

        // Zwróć index do puli
        indicators_edge.push(index);

        matrix[Edges[index].start->index][Edges[index].end->index] = -1;
        matrix[Edges[index].end->index][Edges[index].start->index] = -1;
        
        // Usuń wierzchołki które łączysz
        Edges[index].start = nullptr;
        Edges[index].end = nullptr;
        
        // Usuń krawędź z wektora Edges
        Edges[index].value = -1;
        Edges[index].index = -1;
    }

    void Mat::matrixGraph::removeVertex(string name)
    {
        // Znajdz wierzchołek
        Vertex* temp = findVertex(name);

        if (temp == nullptr)
        {
            cout << "Nie ma takiego wierzcholka.\n";
            return;
        }

        // Usuń krawędzie oraz zaktualizuj macierz
        for (int i = 0; i < matrix.size(); i++)
        {   
            if (matrix[temp->index][i] >= 0)
            {
                removeEdge(matrix[temp->index][i]);
            }
            if (matrix[i][temp->index] >= 0)
            {
                removeEdge(matrix[i][temp->index]);
            }
        }

        // Zwróć indeks do puli
        indicators_vertex.push(temp->index);
        temp->name = "#";
        temp->index = -1;
    }

    vector<Vertex> Mat::matrixGraph::vertices(bool print)
    {
        if(print)
        {
            for (int i = 0; i < Verticies.size(); ++i)
            {
                if (Verticies[i].index < 0)
                {
                    continue;
                }
                cout << Verticies[i].index << ". " << Verticies[i].name << endl;
            }
        }
        
        return Verticies;
    }

    vector<Edge> Mat::matrixGraph::edges(bool print)
    {
        if(print)
        {
            for (int i = 0; i < Edges.size(); ++i)
            {
                if (Edges[i].index < 0)
                {
                    continue;
                }
                cout << Edges[i].index << ". " << Verticies[Edges[i].start->index].name << " -> " << Verticies[Edges[i].end->index].name << ": " << Edges[i].value << endl;
            }
        }
        return Edges;
    }

    vector<vector<int>> Mat::matrixGraph::vg(bool print)
    {
        if(print)
        {
            // Wypisz wizualizację macierzy
            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix.size(); j++)
                {
                    if (matrix[i][j] >= 0)
                    {
                        cout << " [x] ";
                    }
                    else
                    {
                        cout << " [ ] ";
                    }
                    
                    
                }
                cout << endl;
                
            }
        }
        return matrix;
    }

    vector<Edge*> Mat::matrixGraph::incidentEdges(string name) 
    {
        vector<Edge*> temp;
        Vertex* t = findVertex(name);

        if (t == nullptr)
        {
            cout << "Nie znaleziono takiego wierzcholka.\n";
            return temp;
        }

        cout << "Krawedzie incydentne do: " << name << endl;
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][t->index] >= 0)
            {
                temp.push_back(&Edges[matrix[i][t->index]]);
                cout << Edges[matrix[i][t->index]].start->name << " -> " << Edges[matrix[i][t->index]].end->name << ": " << Edges[matrix[i][t->index]].value << endl;
            }
        }
        return temp;
    } 

    string* matrixGraph::endVertices(int e)
    {
        if (e >= Edges.size())
        {
            cout << "Niepoprawny index\n";
            return retTab;
        }
    
        retTab[0] = Edges[e].start->name;
        retTab[1] = Edges[e].end->name;

        cout << retTab[0] << "; " << retTab[1] << endl;
        return retTab;
    } 

    string matrixGraph::oppoiste(string v, int e)
    {
        if (e >= Edges.size())
        {
            cout << "Nie takiej krawedzi\n";
            return "#";
        }
        
        if (Edges[e].start->name == v)
        {
            return Edges[e].end->name;
        }
        else if (Edges[e].end->name == v)
        {
            return Edges[e].start->name;
        }        
        else
        {
            cout << "Podano zla pare wierzcholek=krawedz\n";
            return "#";
        }
    } 

    bool matrixGraph::areAdjacent(string v1, string v2)
    {
        Vertex* tempV1 = findVertex(v1);
        Vertex* tempV2 = findVertex(v2);

        if (tempV1 == nullptr || tempV2 == nullptr)
        {
            cout << "Podano nieprawidlowy wierzcholek\n";
            return false;
        }

        if (matrix[tempV1->index][tempV2->index] >= 0)
        {
            return true;
        }
        return false;
    }

    void matrixGraph::replaceVertex(string v, string r)
    {
        Vertex* temp = findVertex(v);
        if (temp == nullptr)
        {
            cout << "Podano zly wierzcholek\n";
            return;
        }

        temp->name = r;
        return;
    }

    void matrixGraph::replaceEdge(int index, int newVal)
    {
        if (index >= Edges.size())
        {
            cout << "Podano niepoprawny indeks krawedzi.\n";
            return;
        }

        Edges[index].value = newVal;
        return;
    }
};    