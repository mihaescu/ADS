#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"graph.h"
#include"Dijkstra.h"
#include"MinHeap.h"
#include<vector>
#include<assert.h>

int main() {
	FILE *fp = fopen("input.in", "r");	
	int y, tests ,source, count=0, cnt=0, destination;
	int distance[N] = {0}, predecesor[N] = {0};
	int distanceSimple[N], distanceMinHeap[N], distanceBruteForce[N];
	bool ok;
	struct graph* G = (graph*) malloc(sizeof(graph));
	struct MinHeap *mh = (MinHeap*) malloc(sizeof(MinHeap));
	Init(mh);
	
	do{
		puts("________________________________\n");
		puts("Choose an option: \n");
		puts("1. Load the graph\n2. Distance between two nodes\n4. Path between two nodes\n5. Dijkstra\n6. Dijkstra with Min Heap\n7. Brute Force Dijkstra\n8. Exit");
		puts("________________________________\n");
		scanf("%d", &y);

		switch(y){

		case 1:
			G = loadgraph(fp);
			system("cls");
			break;

		case 2:
			//Get shortest distance between two nodes
			puts("Give the source node: ");
			scanf("%d", &source);
			printf("Give the destination node: ");
			scanf("%d", &destination);				
			getDistance(G, source, destination , mh, distance, predecesor);
			for(int i = 0; i <= G->noOfVertices; i ++){
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
			if( !hasNegativeweights(G)){//preprocessing
				puts("\nThe graph is valid for applying Dijkstra.");
				DijkstraMH(G, source, mh, distance, predecesor);				
				getPath(G, source, destination, mh, distance, predecesor);
				for(int i = 0; i <= G->noOfVertices; i ++){
					predecesor[i] = 0;
					distance[i] = 0;
				}
			}
			else
				puts("\nThe graph is invalid for applying Dijkstra.\nOne or more of the edges has negative weight.");
			getch();
			system("cls");
			break;

		case 5://Simple Dijkstra
			puts("Give the source: ");
			scanf("%d", &source);
			if( !hasNegativeweights(G)){//preprocessing
				puts("\nThe graph is valid for applying Dijkstra.");
				Dijkstra(G, source, distance, predecesor);
				printResult(G, distance, source);
				for(int i = 0;i <= G->noOfVertices; i ++){
					predecesor[i] = 0;
					distance[i] = 0;
				}
			}
			else
				puts("\nThe graph is invalid for applying Dijkstra.\nOne or more of the edges has negative weight.");
			getch();
			system("cls");
			break;

		case 6://Dijkstra with Min Heap
			puts("Give the source: ");
			scanf("%d", &source);
			if( !hasNegativeweights(G)){//preprocessing
				puts("\nThe graph is valid for applying Dijkstra.");
				DijkstraMH(G, source, mh, distance, predecesor);	
				printResult(G, distance, source);
				for(int i = 0;i <= G->noOfVertices; i ++){
					predecesor[i] = 0;
					distance[i] = 0;
				}
			}
			else
				puts("\nThe graph is invalid for applying Dijkstra.\nOne or more of the edges has negative weight.");
			getch();
			system("cls");
			break;

		case 7://brute force Dijkstra
			puts("Give the source: ");
			scanf("%d", &source);
			if( !hasNegativeweights(G)){//preprocessing
				puts("\nThe graph is valid for applying Dijkstra.");
				bruteForceDijkstra(source, G, mh, 0, 0, 0, count, distance, predecesor);
				printResult(G, distance, source);
			}
			for(int i = 0; i <= G->noOfVertices; i ++){
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
