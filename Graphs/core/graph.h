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


/* CORE*/
graph* loadGraph(FILE* fp);															//creates the graph, V - number of vertices , E - number of Edges , returns the created graph
void DFS(graph *G, std::vector<int> &visited2, std::vector<int> &visitedWeights, int end, int weight, int prevWeight, int &count, int distanceDFS[N]);

/*utils*/
bool nodeVisited(std::vector<int> &visited, int node);								//function which finds if "node" has been visited
std::vector<int> getAdjNodes(graph *G, int node);
std::vector<int> getAdjWeights(graph *G, int node);
void graphGenerator(char * fileName);												//function which generates directed graphs					

/*test*/




#endif
