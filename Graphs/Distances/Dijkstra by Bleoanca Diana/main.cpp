#include <fstream>
#include <vector>
#include <set>
#include <iostream>

#define DIM 50010
#define INF DIM*1000

using namespace std;

vector<pair<int, int>> adjacency_list[DIM]; /// aici se creeaza un vector de vectori de perechi (fiecare element
                                            ///al vectorului are 2 campuri de tip int),
                                            /// in care o sa pastram lista de adiacenta al fiecarui nod.
set<pair<int, int>> tail; ///creem un set in care pastram nodul si distanta acestuia;
                            /// perechile din set sunt ( distance[nod], nod)

int distances[DIM], x, y, c, no_vertices, no_edges, k;

ifstream fin("dijkstra.in");

int main()
{
    fin >> no_vertices >> no_edges;
    for( int i = 1; i <= no_edges; i++ )
    {
        fin >> x >> y >> c; /// citim legaturile care se formeaza intre noduri si costul acestora
        ///Pentru graf orientat:
        adjacency_list[x].push_back( make_pair(y, c) ); /// in lista de adiacenta a nodului de plecare adaugam
                                                        /// o pereche formata din nodul si costul adiacent

        ///Daca graful este neorientat adaugam:
        ///adjacency_list[y].push_back( make_pair(x, c) );
    }

    for( int i = 1; i <= no_vertices; i++ )
    {
        distances[i] = INF; ///initializam distantele fiecarui nod ca fiind infinit
    }

    ///Consideram ca 1 este nodul de plecare.
    distances[1] = 0; /// distanta nodului de plecare este 0

    tail.insert( make_pair( 0,1 ) ); /// adaugam in set distanta nodului 1;
    ///in set tinem perechi(cost, nod) doar pentru nodurile nealese inca si actualizate macar o data;
    ///in paralel tinem distantele minime la noduri si in vectorul distances


    while( !tail.empty() ) ///cat timp exista elemente in set
    {
        int vertex = tail.begin() -> second; ///din primul element al setului, pastram al doilea
                                                ///camp din pereche (nodul), pentru ca apoi sa
        tail.erase( tail.begin() );             ///il stergem

        for( int i = 0; i < adjacency_list[vertex].size(); i++ ) ///parcurgem lista de adiacenta a nodului curent
        {
            int neighbour = adjacency_list[vertex][i].first; ///nod vecin
            int cost = adjacency_list[vertex][i].second;   ///costul pana la nodul vecin

            if( distances[neighbour] > distances[vertex] + cost )  ///daca distanta nodului vecin e mai mare
            {                            ///decat distanta nodului curent + costul pana la acesta, trebuie sa
                                        ///actualizam valoarea din vectorul distances al vecinului.

                tail.erase (  make_pair( distances[neighbour], neighbour) ); ///cauta in set daca exista acest nod si il sterge
                distances[neighbour] = distances[vertex] + cost;      ///actualizeaza noua distanta a nodului vecin
                tail.insert (  make_pair( distances[neighbour], neighbour) );   /// adaugam parechea cu costul actualizat si nod

                ///Acest if actualizeaza distantele astfel incat sa aiba cele mai mici valori posibile( cel mai scurt drum
                                                                                            ///pana la nodul respectiv).
            }
        }
    }

    ///Trebuie sa afisam distanta de la nodul de pornire pana la toate nodurile grafului.
    for( int i = 2; i <= no_vertices; i++ ) ///parcurgem toate nodurile grafului, in afara de cel de pornire (in cazul nostru
    {                                                                                                   /// nodul 1
        if( distances[i] == INF ) /// daca nu s-a actualizat niciodata distanta acelui nod ( nu se poate ajunge la acest nod
            cout << "0 ";         ///din nodul de pornire ) , afiseaza distanta 0.
        else
            cout << distances[i] << " ";
    }
}
