#include<stdio.h>
#include"msp.h"

 
int main(){

	graph *g;
	int source;
	FILE *f = fopen("input.txt","r");
	g = readGraph(f);
	printf("Insert source node:\n");
	scanf("%d", &source);
	int *dist, *pred;
	dist = createDist(g);
	pred = createPred(g);
	MSP(g, source,dist,pred);
	findPath(g, dist, pred, source);

	

	system("PAUSE");
	return 0;
}
