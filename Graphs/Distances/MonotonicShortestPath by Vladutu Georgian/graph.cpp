#include"graph.h"

graph* readGraph(FILE *f){
	graph *g = (graph*)malloc(sizeof(graph));
	fscanf(f, "%d %d", &g->vertices, &g->edges);

	g->edgeList = (edge*)malloc(g->edges*sizeof(edge));
	for (int i = 0; i < g->edges; i++)
		fscanf(f, "%d %d %d", &g->edgeList[i].source, &g->edgeList[i].destination, &g->edgeList[i].weight);
	return g;
}
