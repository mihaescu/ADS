#include"PushRelabel.h"

void push(adjMatrixGraph *G, int* excess, int u, int v) {
	int send = MIN(excess[u], G->capacities[u][v] - G->flow[u][v]);
	G->flow[u][v] += send;
	G->flow[v][u] -= send;
	excess[u] -= send;
	excess[v] += send;
}

void relabel(adjMatrixGraph *G, int* height, int u) {
	int v;
	int minHeight = INFINITE;
	for (v = 0; v < G->noOfVertices; v++) {
		if (G->capacities[u][v] - G->flow[u][v] > 0) {
			minHeight = MIN(minHeight, height[v]);
			height[u] = minHeight + 1;
		}
	}
}

void discharge(adjMatrixGraph *G, int* excess, int* height, int* seen, int u) {
	while (excess[u] > 0) {
		if (seen[u] < G->noOfVertices) {
			int v = seen[u];
			if ((G->capacities[u][v] - G->flow[u][v] > 0) && (height[u] > height[v])){
				push(G, excess, u, v);
			}
			else{
				seen[u] += 1;
			}
		}
		else {
			relabel(G, height, u);
			seen[u] = 0;
		}
	}
}

void moveToFront(int i, int* list) {
	int temp = list[i];
	int n;
	for (n = i; n > 0; n--){
		list[n] = list[n - 1];
	}
	list[0] = temp;
}

int pushRelabel(adjMatrixGraph *G, int source, int sink) {
	if (G == 0){
		exit(0);
	}
	int *excess, *height, *list, *seen, p;

	excess = (int *)calloc(G->noOfVertices, sizeof(int));
	height = (int *)calloc(G->noOfVertices, sizeof(int));
	list = (int *)calloc(G->noOfVertices, sizeof(int));
	seen = (int *)calloc(G->noOfVertices, sizeof(int));


	for (int i = 0, p = 0; i < G->noOfVertices; i++){
		if ((i != source) && (i != sink)) {
			list[p] = i;
			p++;
		}
	}

	height[source] = G->noOfVertices;
	excess[source] = INFINITE;
	for (int i = 0; i < G->noOfVertices; i++){
		push(G, excess, source, i);
	}

	p = 0;
	while (p < G->noOfVertices - 2) {
		int u = list[p];
		int old_height = height[u];
		discharge(G, excess, height, seen, u);
		if (height[u] > old_height) {
			moveToFront(p, list);
			p = 0;
		}
		else{
			p += 1;
		}
	}
	int maxflow = 0;
	for (int i = 0; i < G->noOfVertices; i++){
		maxflow += G->flow[source][i];
	}

	free(list);
	free(seen);
	free(height);
	free(excess);

	return maxflow;
}

