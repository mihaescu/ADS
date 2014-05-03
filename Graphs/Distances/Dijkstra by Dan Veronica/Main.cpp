#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"Graph.h"
#include"test.h"
#include"Dijkstra.h"
#include"MinHeap.h"
#include<vector>
#include <assert.h>

int main() {
	FILE *fp = fopen("graph.in", "r");
	
	int y, tests ,source, count=0, cnt=0, destination;
	int distance[N] = {0}, predecesor[N] = {0};
	int distanceSimple[N], distanceMinHeap[N], distanceBruteForce[N];
	bool ok;
	struct Graph* G = (Graph*) malloc(sizeof(Graph));
	struct MinHeap *mh = (MinHeap*) malloc(sizeof(MinHeap));
	Init(mh);
	
	do{
		puts("________________________________\n");
		puts("Choose an option: \n");
		puts("1. Load the Graph\n2. 2. Print the Graph\n3. Distance between two nodes\n4. Path between two nodes\n5. Dijkstra\n6. Dijkstra with Min Heap\n7. Brute Force Dijkstra\n8. Exit");
		puts("________________________________\n");
		scanf("%d", &y);

		switch(y){

		case 1:
			G = loadGraph(fp);
			system("cls");
			break;

		case 2:
			printGraph(G);
			system("cls");
			break;

		case 3://Get shortest distance between two nodes
			puts("Give the source node: ");
			scanf("%d", &source);
			printf("Give the destination node: ");
			scanf("%d", &destination);				
			getDistance(G, source, destination , mh, distance, predecesor);
			for(int i = 0; i <= G->V; i ++){
				predecesor[i] = 0;
				distance[i] = 0;
			}
			system("cls");
			break;

		case 4://Get shortest path between two nodes
			puts("Give the source node: ");
			scanf("%d", &source);
			printf("Give the destination node: ");
			scanf("%d", &destination);		
			if( !hasNegativeCosts(G)){//preprocessing
				puts("\nThe Graph is valid for applying Dijkstra.");
				DijkstraMH(G, source, mh, distance, predecesor);				
				getPath(G, source, destination, mh, distance, predecesor);
				for(int i = 0; i <= G->V; i ++){
					predecesor[i] = 0;
					distance[i] = 0;
				}
			}
			else
				puts("\nThe Graph is invalid for applying Dijkstra.\nOne or more of the edges has negative cost.");
			getch();
			system("cls");
			break;

		case 5://Simple Dijkstra
			puts("Give the source: ");
			scanf("%d", &source);
			if( !hasNegativeCosts(G)){//preprocessing
				puts("\nThe Graph is valid for applying Dijkstra.");
				Dijkstra(G, source, distance, predecesor);
				printResult(G, distance, source);
				for(int i = 0;i <= G->V; i ++){
					predecesor[i] = 0;
					distance[i] = 0;
				}
			}
			else
				puts("\nThe Graph is invalid for applying Dijkstra.\nOne or more of the edges has negative cost.");
			getch();
			system("cls");
			break;

		case 6://Dijkstra with Min Heap
			puts("Give the source: ");
			scanf("%d", &source);
			if( !hasNegativeCosts(G)){//preprocessing
				puts("\nThe Graph is valid for applying Dijkstra.");
				DijkstraMH(G, source, mh, distance, predecesor);	
				printResult(G, distance, source);
				for(int i = 0;i <= G->V; i ++){
					predecesor[i] = 0;
					distance[i] = 0;
				}
			}
			else
				puts("\nThe Graph is invalid for applying Dijkstra.\nOne or more of the edges has negative cost.");
			getch();
			system("cls");
			break;

		case 7://brute force Dijkstra
			puts("Give the source: ");
			scanf("%d", &source);
			if( !hasNegativeCosts(G)){//preprocessing
				puts("\nThe Graph is valid for applying Dijkstra.");
				bruteForceDijkstra(source, G, mh, 0, 0, 0, count, distance, predecesor);
				printResult(G, distance, source);
			}
			for(int i = 0; i <= G->V; i ++){
				predecesor[i] = 0;
				distance[i] = 0;
			}
			getch();
			system("cls");
			break;

		case 8:
			return 0;
		}
	}while(y != 8);

	return (0);
}
