
#include<stdio.h>
#include<stdlib.h>
#include<deque>
using namespace std;


struct MinHeap{
	deque<MinHeapNode> MH;
};


void push(deque<MinHeapNode>& minHeap, int _distance, int _destination, int _predecesor){
	MinHeapNode node;
	node.distance = _distance;
	node.destination = _destination;
	node.predecesor = _predecesor;

	minHeap.push_back(node);
	int i = minHeap.size() - 1;

	while (i >= 0 && minHeap[(i - 1) / 2].distance > minHeap[i].distance){
		MinHeapNode aux = minHeap[(i - 1) / 2];
		minHeap[(i - 1) / 2] = minHeap[i];
		minHeap[i] = aux;
		i = (i - 1) / 2;
	}

}

MinHeapNode pop(deque<MinHeapNode>& minHeap){
	MinHeapNode top = minHeap[0];
	minHeap[0] = minHeap[minHeap.size() - 1];
	minHeap.pop_back();

	int i = 0, size = minHeap.size();

	while ((2 * i + 1)<size){
		MinHeapNode  aux = minHeap[i];

		if ((2 * i + 2) < size){
			if (minHeap[2 * i + 1].distance > minHeap[2 * i + 2].distance && minHeap[i].distance > minHeap[2 * i + 2].distance){
				minHeap[i] = minHeap[2 * i + 2];
				minHeap[2 * i + 2] = aux;
				i = 2 * i + 2;
				continue;
			}
		}
		if (minHeap[i].distance > minHeap[2 * i + 1].distance){
			minHeap[i] = minHeap[2 * i + 1];
			minHeap[2 * i + 1] = aux;
			i = 2 * i + 1;
		}
		else
			break;


	}


	return top;


}







typedef struct edge{
	int source;
	int destination;
	int weight;
};

typedef struct graph{
	int vertices;
	int edges;
	edge *edgeList;
};


graph* readGraph(FILE *f){
	graph *g = (graph*)malloc(sizeof(graph));
	fscanf(f, "%d %d", &g->vertices, &g->edges);

	g->edgeList = (edge*)malloc(g->edges*sizeof(edge));
	for (int i = 0; i < g->edges; i++)
		fscanf(f, "%d %d %d", &g->edgeList[i].source, &g->edgeList[i].destination, &g->edgeList[i].weight);
	return g;
}


int *createDist(graph *g){
	int *dist = (int*)malloc((g->vertices + 1)*sizeof(int));
	return dist;
}

int *createPred(graph *g){
	int *pred = (int*)malloc((g->vertices + 1)*sizeof(int));
	return pred;
}





void MSP(graph *g, int source, int *dist, int *pred){
	bool *set = (bool*)malloc((g->vertices + 1)*sizeof(bool));
	int i, E = g->edges, V = g->vertices, u, j, v, distU;
	deque<MinHeapNode> minHeap;


	for (i = 0; i <= V; i++){  //am schimbat aici < cu <=
		dist[i] = INT_MAX;
		set[i] = false;
		pred[i] = 0;
	}

	dist[source] = 0;
	u = source;
	set[source] = true;
	distU = INT_MAX;

	do{

		for (j = 0; j < E; j++){
			v = g->edgeList[j].destination;
			if (g->edgeList[j].source == u && !set[v] && dist[u] != INT_MAX){
				push(minHeap, dist[u] + g->edgeList[j].weight, v, u);

			}
		}
		MinHeapNode top = pop(minHeap);
		if (dist[top.destination]>top.distance && top.distance - dist[top.predecesor] >  dist[top.predecesor] - dist[pred[top.predecesor]]){
			dist[top.destination] = top.distance;
			pred[top.destination] = top.predecesor;
		}
		u = top.destination;
		set[u] = true;

	} while (minHeap.size() > 0);



}






void path(int *pred, int source, int destination){
	if (source != destination){
		path(pred, source, pred[destination]);
		printf("%d ", destination);
	}
	else
		printf("%d ", source);
}

void findPath(graph *g, int *dist, int *pred, int source){
	int i;
	for (i = 1; i <= g->vertices; i++)
	if (dist[i] != INT_MAX){
		printf("Distance from %d to %d is %d. The path is: ", source, i, dist[i]);
		path(pred, source, i);
		printf("\n");
	}
	else
		printf("Distance from %d to %d is infinite\n", source, i);
}




int main(){


	graph *g;
	int source;
	FILE *f = fopen("input.txt", "r");
	g = readGraph(f);
	printf("Insert source node:\n");
	scanf("%d", &source);
	int *dist, *pred;
	dist = createDist(g);
	pred = createPred(g);
	MSP(g, source, dist, pred);
	findPath(g, dist, pred, source);


	system("PAUSE");
	return 0;
}
