#include"PushRelabel.h"

void push(int** capacity, int** flow, int* excess, int u, int v) {
	int send = MIN(excess[u], capacity[u][v] - flow[u][v]);
	flow[u][v] += send;
	flow[v][u] -= send;
	excess[u] -= send;
	excess[v] += send;
}

void relabel(int** capacity, int** flow, int* height, int u) {
	int v;
	int minHeight = INFINITE;
	for (v = 0; v < NODES; v++) {
		if (capacity[u][v] - flow[u][v] > 0) {
			minHeight = MIN(minHeight, height[v]);
			height[u] = minHeight + 1;
		}
	}
}

void discharge(int** capacity, int** flow, int* excess, int* height, int* seen, int u) {
	while (excess[u] > 0) {
		if (seen[u] < NODES) {
			int v = seen[u];
			if ((capacity[u][v] - flow[u][v] > 0) && (height[u] > height[v])){
				push(capacity, flow, excess, u, v);
			}
			else{
				seen[u] += 1;
			}
		}
		else {
			relabel(capacity, flow, height, u);
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

int pushRelabel(int** capacity, int** flow, int source, int sink) {
	int *excess, *height, *list, *seen, p;

	excess = (int *)calloc(NODES, sizeof(int));
	height = (int *)calloc(NODES, sizeof(int));
	list = (int *)calloc(NODES, sizeof(int));
	seen = (int *)calloc(NODES, sizeof(int));


	for (int i = 0, p = 0; i < NODES; i++){
		if ((i != source) && (i != sink)) {
			list[p] = i;
			p++;
		}
	}

	height[source] = NODES;
	excess[source] = INFINITE;
	for (int i = 0; i < NODES; i++){
		push(capacity, flow, excess, source, i);
	}

	p = 0;
	while (p < NODES - 2) {
		int u = list[p];
		int old_height = height[u];
		discharge(capacity, flow, excess, height, seen, u);
		if (height[u] > old_height) {
			moveToFront(p, list);
			p = 0;
		}
		else{
			p += 1;
		}
	}
	int maxflow = 0;
	for (int i = 0; i < NODES; i++){
		maxflow += flow[source][i];
	}

	free(list);
	free(seen);
	free(height);
	free(excess);

	return maxflow;
}

void printMatrix(FILE* f, int** matrix) {
	int i, j;
	for (i = 0; i < NODES; i++) {
		for (j = 0; j < NODES; j++){
			fprintf(f, "%d\t", matrix[i][j]);
		}
		fprintf(f, "\n");
	}
}