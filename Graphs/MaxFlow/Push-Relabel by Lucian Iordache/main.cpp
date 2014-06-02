#include"PushRelabel.h"


int main() {
	FILE *fo = fopen("output.out", "w");
	FILE *fi = fopen("input.in", "r");
	int **flow, **capacities, i, j;
	
	//trebuie citire cu functie din core!
	flow = (int **)calloc(NODES, sizeof(int*));
	capacities = (int **)calloc(NODES, sizeof(int*));
	
	
	for (i = 0; i < NODES; i++) {
		flow[i] = (int *)calloc(NODES, sizeof(int));
		capacities[i] = (int *)calloc(NODES, sizeof(int));
	}
	while (!feof(fi)){
		fscanf(fi, "%d%d", &i, &j);
		fscanf(fi, "%d", &capacities[i][j]);
	}
	fclose(fi);

	fprintf(fo, "Capacity matrix:\n");
	printMatrix(fo, capacities);
	fprintf(fo, "Max Flow:\n%d\n", pushRelabel(capacities, flow, 0, 5));
	fprintf(fo, "Flow matrix:\n");
	printMatrix(fo, flow);
	fclose(fo);
	return 0;
}