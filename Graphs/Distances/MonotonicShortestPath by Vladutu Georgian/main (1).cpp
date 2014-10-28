#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include<vector>

typedef struct edge{
	int source;
	int destination;
	int weight;
};

typedef struct graph{
	int vertices;
	int edges;
	int source;
	edge *edgeList;
};

graph* readGraph(FILE *f){
	graph *g = (graph*)malloc(sizeof(graph));
	fscanf(f,"%d %d %d", &g->vertices, &g->edges,&g->source);

	g->edgeList = (edge*)malloc(g->edges*sizeof(edge));
	for (int i = 0; i < g->edges; i++)
		fscanf(f, "%d %d %d", &g->edgeList[i].source, &g->edgeList[i].destination, &g->edgeList[i].weight);
	return g;
}


int min(int *dist, bool *set,int V){
	int i,min=INT_MAX,minIndex;
	for (i = 0; i <= V; i++){  //am schimbat aici < cu <=
		if (set[i] == false && dist[i] <= min){
			min = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}


void MSP(graph *g, int source,int *dist,int *pred){
	//int *dist = (int*)malloc((g->vertices+1)*sizeof(int));   //am schimbat aici g->vertices cu g->vertices+1
	bool *set = (bool*)malloc((g->vertices + 1)*sizeof(bool));
	//int *pred = (int*)malloc((g->vertices + 1)*sizeof(int));


	int i,E=g->edges,V=g->vertices,u,j,v;
	for (i = 0; i <= V; i++){  //am schimbat aici < cu <=
		dist[i] = INT_MAX;
		set[i] = false;
		pred[i] = 0;
	}

	dist[source] = 0;

	for (i = 0; i < V; i++){    //am schimbat aici V-1 cu V
		u = min(dist, set, V);
		set[u] = true;

		for (j = 0; j < E; j++){
			v = g->edgeList[j].destination;                                   
			if (g->edgeList[j].source == u && !set[v] && dist[u] != INT_MAX && dist[u] + g->edgeList[j].weight < dist[v] && dist[u] - dist[pred[u]]<g->edgeList[j].weight){
				dist[v] = dist[u] + g->edgeList[j].weight;
				pred[v] = u;
			}
		}

	}
	u = 3;

}


int *createDist(graph *g){
	int *dist = (int*)malloc((g->vertices + 1)*sizeof(int));
	return dist;
}

int *createPred(graph *g){
	int *pred = (int*)malloc((g->vertices + 1)*sizeof(int));
	return pred;
}

void path(int *pred, int source, int destination){
	if (source != destination){
		path(pred, source, pred[destination]);
		printf("%d ", destination);
	}
	else
		printf("%d ",source);
}

void findPath(graph *g, int *dist, int *pred, int source){
	int i;
	for (i = 1; i <= g->vertices;i++)
	if (dist[i] != INT_MAX){
		printf("Cost from %d to %d is %d. The path is: ", source, i, dist[i]);
		path(pred,source,i);
		printf("\n");
	}
}

int main(){

	graph *g;
	FILE *f = fopen("input.txt","r");
	g = readGraph(f);
	int *dist, *pred;
	dist = createDist(g);
	pred = createPred(g);
	MSP(g, 1,dist,pred);
	findPath(g, dist, pred, 1);

	

	system("PAUSE");
	return 0;
}