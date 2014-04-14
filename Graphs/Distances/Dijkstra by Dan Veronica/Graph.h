#ifndef __Graph_H__
#define __Graph_H__

#define N 300
#define M 300
#include<vector>

struct Edge{

	int source;
	int destination;
	int cost;
};

struct Graph{

	int V, E;
	struct Edge *adjListarr;
};

Graph *GraphInit();
Graph *loadGraph(FILE *fp);
void printGraph(struct Graph *g);
bool nodeVisited(int visited[N], int node);

std::vector<int> getAdjCosts(Graph *G, int node);
std::vector<int> getAdjNodes(Graph *G, int node);
bool nodeVisited2(std::vector<int> &visited2, int node);
#endif
