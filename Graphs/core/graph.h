#ifndef GRAPH_H
#define GRAPH_H

#include<stdlib.h>
#include<time.h>
#include<vector>

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


Graph *GraphInit();
graph* loadGraph(FILE* fp);															//creates the graph, V - number of vertices , E - number of Edges , returns the created graph

void graphGenerator(char * fileName);												//function which generates directed graphs					

bool nodeVisited(std::vector<int> &visited, int node);								//function which finds if "node" has been visited
bool nodeVisited2(int visited[N], int node);
std::vector<int> getAdjNodes(graph *G, int node);	

std::vector<int> getAdjCosts(Graph *G, int node);
#endif
