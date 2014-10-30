#ifndef __GRAPH_H__
#define __GRAPH_H__

#include<stdio.h>
#include<stdlib.h>

typedef struct edge{
	int source;
	int destination;
	int weight;
};

typedef struct graph{
	int vertices;
	int edges;
	edge *edgeList;
};

graph* readGraph(FILE *f);


#endif
