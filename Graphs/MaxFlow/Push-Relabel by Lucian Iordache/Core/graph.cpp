#include "graph.h"

adjMatrixGraph* loadAdjMatrixGraph(FILE* fp){
	int V, E;
	int x, y, capacity;
	fscanf(fp, "%d", &V);
	fscanf(fp, "%d", &E);

	adjMatrixGraph *G = (adjMatrixGraph*)malloc(sizeof(adjMatrixGraph));					// allocate memory for the adjMatrixGraph
	G->noOfVertices = V;											// set the number of vertixes
	G->noOfEdges = E;												// set the number of edges

	G->flow = (int **)calloc(V, sizeof(int*));						// allocate memory for the edges
	G->capacities = (int **)calloc(V, sizeof(int*));			
	for (int i = 0; i < V; i++) {
		G->flow[i] = (int *)calloc(V, sizeof(int));
		G->capacities[i] = (int *)calloc(V, sizeof(int));
	}
	for (int i = 0; i < E; i++)										// set the edges
	{
		fscanf(fp, "%d%d%d", &x, &y, &capacity);
		G->capacities[x][y] = capacity;

	}
	fclose(fp);
	return G;													// return the adjMatrixGraph
}

void printCapacitiesMatrix(FILE* f, adjMatrixGraph *G) {
	int i, j;
	for (i = 0; i < G->noOfVertices; i++) {
		for (j = 0; j < G->noOfVertices; j++){
			fprintf(f, "%d\t", G->capacities[i][j]);
		}
		fprintf(f, "\n");
	}
}

void printFlowMatrix(FILE* f, adjMatrixGraph *G) {
	int i, j;
	for (i = 0; i < G->noOfVertices; i++) {
		for (j = 0; j < G->noOfVertices; j++){
			fprintf(f, "%d\t", G->flow[i][j]);
		}
		fprintf(f, "\n");
	}
}