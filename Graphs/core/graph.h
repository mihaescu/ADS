#ifndef graph_H
#define graph_H

#include<stdlib.h>
#include<time.h>
#include<vector>
#define N 300
#define M 300
typedef struct edge																	//structure for edge
{
	int source;																		//source vertex
	int destination;																//destination vertex
	int weight;																		//edge weight
};

typedef struct graph																//structure for graph
{
	int noOfVertices;																//number of vertixes
	int noOfEdges;																	//number of edges
	edge *pEdge;																	//edges
};


graph *graphInit();
graph* loadgraph(FILE* fp);															//creates the graph, V - number of vertices , E - number of Edges , returns the created graph

void graphGenerator(char * fileName);												//function which generates directed graphs					

bool nodeVisited(std::vector<int> &visited, int node);								//function which finds if "node" has been visited
bool nodeVisited2(int visited[N], int node);
std::vector<int> getAdjNodes(graph *G, int node);	

std::vector<int> getAdjweights(graph *G, int node);
#endif
