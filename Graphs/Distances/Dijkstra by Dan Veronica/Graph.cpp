#include"Graph.h"
#include <fstream>
#include<malloc.h>
#include<conio.h>
#include<vector>

Graph *GraphInit(){

	struct Graph *G= (Graph*) malloc(sizeof(Graph));
	G->adjListarr = (Edge*)malloc(sizeof(Edge)*G->E);	
	G->E=0;
	G->V=0;
	G->adjListarr=NULL;
	return G;
}
Graph *loadGraph(FILE *fp){
		
	struct Graph *G = GraphInit();
	
	int V, E;
	fscanf(fp, "%d", &V);
	fscanf(fp, "%d", &E);

	G = (Graph*)malloc(sizeof(Graph));			
	G->V = V;											
	G->E = E;										

	G->adjListarr = (Edge*)malloc(sizeof(Edge)*G->E);			
	
	for (int i = 0; i < E; i ++){

		fscanf(fp, "%d", &G->adjListarr[i].source);
		fscanf(fp, "%d", &G->adjListarr[i].destination);
		fscanf(fp, "%d", &G->adjListarr[i].cost);
	}

	fclose(fp);
	return G;			
}
bool nodeVisited(std::vector<int> &visited, int node){

	for (int i = 0; i < visited.size();i++)
		if (node == visited[i])
			return true;
	return false;
}
void printGraph(struct Graph *G){
	
	int adjnodes[N], adjcosts[N], nodesCounter=0;

	puts("\nNr of vertices:");
	printf("%d",G->V);

	puts("\nNr of edges:");
	printf("%d",G->E);

	puts("\n");

	for(int j = 1 ; j <= G->V ; j ++){
		for (int i = 0; i < G->E;i++)//getting the adjencent nodes and their costs

			if (G->adjListarr[i].source == j){
				adjnodes[nodesCounter] = G->adjListarr[i].destination;
				adjcosts[nodesCounter] = G->adjListarr[i].cost;
				nodesCounter ++;
			}

		puts("\n");
		printf("List for node %d: -> ",j);

		for (int iter = 0; iter < nodesCounter; iter ++)
			printf( "%d (cost: %d) -> ",adjnodes[iter],adjcosts[iter]);

		//reinitialisation of the two arrays 
		for (int i = 0; i < G->E;i++){
			adjnodes[nodesCounter] = 0;
			adjcosts[nodesCounter] = 0;
		}
		nodesCounter=0;

	}	
	puts("\n");
	getch();
}

bool nodeVisited2(std::vector<int> &visited, int node){

	for (int i = 0; i < visited.size();i++)
		if (node == visited[i])
			return true;
	return false;
}
std::vector<int> getAdjNodes(Graph *G, int node){

	std::vector<int> nodes;

	for (int i = 0; i < G->E;i++)
		if (G->adjListarr[i].source == node)
			nodes.push_back( G->adjListarr[i].destination);
		
	return nodes;
}
std::vector<int> getAdjCosts(Graph *G, int node){

	std::vector<int> costs;

	for (int i = 0; i < G->E;i++)
		if (G->adjListarr[i].source == node)
			costs.push_back(G->adjListarr[i].cost);
	
	return costs;
}