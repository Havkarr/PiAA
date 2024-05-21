#include "G_list.hpp"
#include <vector>
#include <iostream>

using namespace std;

namespace List 
{
    listGraph::listGraph()
    {
        indicators_vertex.push(0);
        indicators_edge.push(0);
    }

    void listGraph::insertVertex(string name)
    {
        Vertex temp;
        temp.name = name;
        temp.index = indicators_vertex.top();

        // Jezeli dodajesz wierzcholek na miejscu ktore bylo juz wczesniej
        // to nie dodawaj nowych wpisow do kolejki indeksow
        if (temp.index < Verticies.size()) 
        {
            Verticies.insert(Verticies.begin() + temp.index, temp);
        }
        else
        {
            // Uaktualnij liste indeksow
            indicators_vertex.push(indicators_vertex.top()+1);
            Verticies.push_back(temp);
        }

        indicators_vertex.pop();
        return;
    }

    void listGraph::removeVertex(string name)
    {
        Vertex* temp = findVertex(name);

        if (temp == nullptr)
        {
            cout << "Nie usunieto wierzcholka\n";
            return;
        }

        // Wyczysc liste sasiedztwa
        for (int i = 0; i < temp->incList.size()+1; i++)
        {
            removeEdge(temp->incList[i]);
        }
        
        indicators_vertex.push(temp->index);
        temp->index = -1;
        temp->name = "#";

        return;
    }

    void listGraph::insertEdge(string start, string end, int val)
    {
        Vertex* s = findVertex(start);
        Vertex* e = findVertex(end);

        if (s == nullptr || e == nullptr)
        {
            return;
        }  

        Edge temp;
        temp.value = val;
        temp.index = indicators_edge.top();
        temp.start = s;
        temp.end = e;
   
        if (temp.index < Edges.size())
        {
            Edges.insert(Edges.begin() + temp.index, temp);
        }
        else
        {
            // Uaktualnij liste indeksow
            indicators_edge.push(indicators_edge.top()+1);
            Edges.push_back(temp);
        }
        
        indicators_edge.pop();
        s->incList.push_back(temp.index);
        e->incList.push_back(temp.index);
    }

    void listGraph::removeEdge(int index)
    {
        if (index >= Edges.size())
        {
            cout << "Podano zly index.\n";
            return;
        }

        Edges[index].value = 0;
        indicators_edge.push(Edges[index].index);
        
        // Usun wpisy o krawedzi z listy wierzcholka startowego
        for (int i = 0; i < Edges[index].start->incList.size(); i++)
        {
            if (Edges[index].start->incList[i] == Edges[index].index)
            {
                Edges[index].start->incList.erase(Edges[index].start->incList.begin()+i);
                break;
            }
        }
        // Usun wpisy o krawedzi z listy wierzcholka koncowego
        for (int j = 0; j < Edges[index].end->incList.size(); j++)
        {
            if (Edges[index].end->incList[j] == Edges[index].index)
            {
                Edges[index].end->incList.erase(Edges[index].end->incList.begin()+j);
                break;
            }
        }

        Edges[index].start = nullptr;
        Edges[index].end = nullptr;

        Edges[index].index = -1;
        return;
    }

    vector<Edge> listGraph::edges(bool print)
    {
        if(print)
        {
            for (int i = 0; i < Edges.size(); i++)
            {
                if (Edges[i].index < 0)
                {
                    continue;
                }
                
                cout << Edges[i].index << ". " << Edges[i].start->name << " -> " << Edges[i].end->name << ": " << Edges[i].value << endl;
            }
        }
        return Edges;
    }

    Vertex* listGraph::findVertex(string name)
    {
        for (int i = 0; i < Verticies.size(); i++)
        {
            if(Verticies[i].name == name)
            {
                return &Verticies[i];
            }
        }

        cout << "Brak takiego wierzcholka w grafie.\n";
        return nullptr;
    }

    vector<Vertex> listGraph::vertices(bool print)
    {
        if(print)
        {
            for (int i = 0; i < Verticies.size(); i++)
            {
                if (Verticies[i].index < 0)
                {
                    continue;
                }
                cout << Verticies[i].index << " " << Verticies[i].name << endl; 
            }
        }
        return Verticies;
    }

    // Nie działa :/
    // Działa :D
    vector<Edge*> listGraph::incidentEdges(string name)
    {
        Vertex* temp = findVertex(name);
        vector<Edge*> bucket;

        if (temp == nullptr)
        {
            return bucket;
        }  

        cout << "Krawedzie incydentne do: " << name << endl;
        for (int i = 0; i < temp->incList.size(); i++)
        {
            cout << Edges[temp->incList[i]].index << ". " << Edges[temp->incList[i]].value << endl;

            bucket.push_back(&Edges[temp->incList[i]]);
        }
        
        return bucket;
    }  

    string* listGraph::endVertices(int e)
    {
        if (e >= Edges.size())
        {
            cout << "Podano zly index.\n";
            return retTab;
        }
        
        retTab[0] = Edges[e].start->name;
        retTab[1] = Edges[e].end->name;

        return retTab;
    }

    string listGraph::oppoiste(string v, int e)
    {
        Vertex* temp = findVertex(v);
        if (temp == nullptr || e >= Edges.size())
        {
            return "#";
        }

        if (Edges[e].start->name != v && Edges[e].end->name != v)
        {
            cout << "Podano zla pare wierzcholek-krawedz\n";
            return "#";
        }
        else
        {
            if (Edges[e].start->name == v)
            {
                return Edges[e].end->name;
            }
            else
            {
                return Edges[e].start->name;
            }
        }
    }
 
    bool listGraph::areAdjacent(string v1, string v2)
    {
       Vertex* Tempv1 = findVertex(v1);
       Vertex* Tempv2 = findVertex(v2);

       if (Tempv1 == nullptr || Tempv2 == nullptr)
       {
            return false;
       }
        
       for (int i = 0; i < Tempv1->incList.size(); i++)
       {
            for (int j = 0; j < Tempv2->incList.size(); j++)
            {
                if (Tempv1->incList[i] == Tempv2->incList[j])
                {
                    // Warunek zapewnia, ze porownanie tego samego wierzcholka napewno da prawdziwa odpowiedz.
                    // Poniewaz porownanie tych samych wierzcholkow zawsze da prawde (zawartosc incList taka sama),
                    // trzeba sprawdzic czy krawedz laczy podane wierzcholki
                    if ((Edges[Tempv1->incList[i]].start->name == v1 && Edges[Tempv1->incList[i]].end->name == v2) ||
                    (Edges[Tempv1->incList[i]].start->name == v2 && Edges[Tempv1->incList[i]].end->name == v1))
                    {
                        return true;
                    }
                }
            }
       }
    
        return false;
    }

    void listGraph::replaceVertex(string v, string r)
    {
        Vertex* temp = findVertex(v);

        if (temp == nullptr)
        {
            cout << "Nie zamieniono wierzcholkow\n";
            return;
        }
        
        temp->name = r;
        return;
    }

    void listGraph::replaceEdge(int index, int newVal)
    {
        if (index >= Edges.size())
        {
            cout << "Podano zly index\n";
            return;
        }
        
        Edges[index].value = newVal;
        return;
    }
};    