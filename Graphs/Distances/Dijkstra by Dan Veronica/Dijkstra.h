#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__

#include "graph.h"
#include "MinHeap.h"
#include<vector>

#define inf 999999

bool hasNegativeweights(struct graph* graph);

void DijkstraMH(struct graph* graph, int src,MinHeap *mh, int distance[N], int predecesor[N]);
void Dijkstra(struct graph* graph, int src, int distance[N], int predecesor[N]);

void getDistance(struct graph* graph, int source, int destination ,MinHeap *mh, int distance[N], int predecesor[N]);
void getPath(struct graph* graph, int source, int destination ,MinHeap *mh, int distance[N], int predecesor[N]);

void DFS(graph *G, std::vector<int> &visited2, std::vector<int> &visitedweights, int end, int weight, int prevweight, int &count, int distanceDFS[N]);
int minDistance(struct graph* graph, int distanceDFS[N]);
void bruteForceDijkstra(int source, graph *G, MinHeap *mh, int end, int weight, int prevweight, int &count, int distance[N], int predecesor[N]);

void printResult(struct graph* graph, int distance[N], int source);
 #endif