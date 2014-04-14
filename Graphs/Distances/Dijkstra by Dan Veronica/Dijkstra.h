#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__

#include "Graph.h"
#include "MinHeap.h"
#include<vector>

#define inf 999999

bool hasNegativeCosts(struct Graph* Graph);

void DijkstraMH(struct Graph* Graph, int src,MinHeap *mh, int distance[N], int predecesor[N]);
void Dijkstra(struct Graph* Graph, int src, int distance[N], int predecesor[N]);

void getDistance(struct Graph* Graph, int source, int destination ,MinHeap *mh, int distance[N], int predecesor[N]);
void getPath(struct Graph* Graph, int source, int destination ,MinHeap *mh, int distance[N], int predecesor[N]);

void DFS(Graph *G, std::vector<int> &visited2, std::vector<int> &visitedCosts, int end, int cost, int prevCost, int &count, int distanceDFS[N]);
int minDistance(struct Graph* graph, int distanceDFS[N]);
void bruteForceDijkstra(int source, Graph *G, MinHeap *mh, int end, int cost, int prevCost, int &count, int distance[N], int predecesor[N]);

void printResult(struct Graph* Graph, int distance[N], int source);

bool compare(struct Graph* Graph, int distanceSimple[N], int distanceMinHeap[N], int distanceBruteForce[N]);
 #endif