#include"PushRelabel.h"


int main() {
	FILE *fo = fopen("data/output.out", "w");
	FILE *fi = fopen("data/undirectedWeighted50N97V.txt", "r");
	adjMatrixGraph *G = loadAdjMatrixGraph(fi);
	fprintf(fo, "Capacity matrix:\n");
	printCapacitiesMatrix(fo, G);
	fprintf(fo, "Max Flow:\n%d\n", pushRelabel(G, 0, 49));
	fprintf(fo, "Flow matrix:\n");
	printFlowMatrix(fo, G);
	fclose(fo);
	return 0;
}