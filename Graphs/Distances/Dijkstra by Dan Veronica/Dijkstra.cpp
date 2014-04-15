#include"Graph.h"
#include"Dijkstra.h"
#include"MinHeap.h"
#include<fstream>
#include<malloc.h>
#include<conio.h>


void DijkstraMH(struct Graph* G, int source, MinHeap *mh, int distance[N], int predecesor[N]){

	MinHeapNode temp;
	Init(mh);
	int adjnodes[N], adjcosts[N], nodesCounter=0;
	temp.distance = 0;
	distance[0] = 0;
	mh->seen[source] = 1;
			
	temp.destinationVertex = source;
	Insert(mh, temp);

	for(int node = 0; node < G->E; node ++){
		if(node!= source)
			distance[node]=inf;
	}

	distance[source]=0;
	

	for (int i = 0; i < G->E;i++){//getting the adjencent nodes of the source and their costs

		if (G->adjListarr[i].source == source){
			adjnodes[nodesCounter] = G->adjListarr[i].destination;
			adjcosts[nodesCounter] = G->adjListarr[i].cost;
			nodesCounter ++;
		}
	}	
	for(int j = 1; j <= G->V; j ++){//deals with the source's adjencent nodes	
		for (int i = 0; i < nodesCounter; i ++){
		
			if(j!=source){
				if(adjnodes[i] == j){
					temp.distance = adjcosts[i];
					distance[adjnodes[i]]= adjcosts[i];
					mh->seen[adjnodes[i]]=0;
					
					temp.destinationVertex = adjnodes[i];
					Insert(mh,temp);
					break;
				}
			
				else{			
					distance[j]= inf;
					mh->seen[j]=0;
				}
			}
		}
	}

	while( mh -> heapSize ){

		MinHeapNode min = DeleteMin(mh);
		int currentVertex = min.destinationVertex;
		
		if( mh -> seen[currentVertex] )
			continue;

		mh -> seen[currentVertex] = 1;
		
		for (int i = 0; i < G->E;i++){//getting the adjencent nodes of the source's adjencent node taken into consideration
			
			if (G->adjListarr[i].source == currentVertex){
				adjnodes[nodesCounter] = G->adjListarr[i].destination;
				adjcosts[nodesCounter] = G->adjListarr[i].cost;
				nodesCounter ++;
			}
		}	
		
		for (int i = 0; i < nodesCounter; i ++){
			if( distance[adjnodes[i]] > distance[currentVertex] + adjcosts[i]){//Dijkstra minimum criteria

				distance[adjnodes[i]] = distance[currentVertex] + adjcosts[i];
				temp.destinationVertex = adjnodes[i];
				temp.distance = distance[adjnodes[i]];
				Insert( mh, temp );
				predecesor[adjnodes[i]] = currentVertex;

			}
		}
	}
}
void printResult(struct Graph* G, int distance[N],int source){

	for(int i=1;i<=G->V;i++){
		if( distance[i] != 0 && distance[i] != inf && i!=source)
			printf("Distance from source to %d is %d\n",i,distance[i]);
	}
	getch();
}
void getDistance(struct Graph* Graph, int source, int destination, MinHeap *mh, int distance[N], int predecesor[N]){
	
	DijkstraMH( Graph, source, mh, distance, predecesor );
	printf("Distance from %d to %d is: %d", source, destination, distance[destination] );
	getch();
}
void getPath(struct Graph* Graph, int source, int destination, MinHeap *mh, int distance[N], int predecesor[N]){
	
	DijkstraMH(Graph, source, mh, distance, predecesor);
	printf("The path from %d to %d is: ", source, destination);

	int i = destination;
	int count = 0, path[N];
	if(source == 1)
		printf("%d, ", source);
	while( i != source){
		if( predecesor[i] != 0 ){
			i = predecesor[i];
			path[count] = i;
			count ++;
		}
		else 
			break;
	}
	for(int j = count;j >= 0;j --)
		if(path[j] > 0)
			printf("%d, ", path[j]);
	printf("%d", destination);
	getch();
}
bool hasNegativeCosts(struct Graph* G){
	bool ok=false;
	int adjcosts[N],nodesCounter=0;
		
	for(int j = 0; j <= G->V; j ++ ){//getting the adjencent nodes' costs of every node
		for (int i = 0; i < G->E; i ++)

			if (G->adjListarr[i].source == j){
				adjcosts[nodesCounter] = G->adjListarr[i].cost;
				nodesCounter ++;
			}		
		for (int i=0;i<nodesCounter;i++){
			if(adjcosts[i]< 0)
				ok = true;
		}
	}
	return ok;
}
void Dijkstra(struct Graph* G, int source, int distance[N], int predecesor[N]){

	int currentVertex, count, visited[100], min;

	for(int node = 0; node < G->E; node ++){
		if(node!= source)
		visited[node] = 0;
		distance[node]=inf;
	}

	distance[source]=0;
	
	for(int node = 0; node < G->E; node ++){
		if (G->adjListarr[node].source == source){
			visited[G->adjListarr[node].destination] = 0;
			distance[G->adjListarr[node].destination]=G->adjListarr[node].cost;
		}
	}
	count=2;
	
	while(count <= G->V) {
		min = inf;
		for(int node = 0; node < G->V; node ++)
			if(distance[node]<min && !visited[node]){
				min=distance[node];
				currentVertex=node;
			}
		visited[currentVertex]=1;
		count++;
		
		for(int node = 0; node <= G->E; node ++){

			if(G->adjListarr[node].source == currentVertex)
				if((distance[currentVertex] + G->adjListarr[node].cost < distance[G->adjListarr[node].destination]) && !visited[G->adjListarr[node].destination])

					distance[G->adjListarr[node].destination] = distance[currentVertex] + G->adjListarr[node].cost;
		}
	}
}
void DFS(Graph *G, std::vector<int> &visited2, std::vector<int> &visitedCosts, int end, int cost, int prevCost, int &count, int distanceDFS[20]){

	int back;
	back = visited2.back();
	std::vector<int> adjNodes = getAdjNodes(G, back);
	std::vector<int> costs = getAdjCosts(G, back);

	typedef std::vector<int>::iterator iterNodes;
	typedef std::vector<int>::iterator iterCosts;

	
	for (std::pair<iterNodes, iterCosts> i(adjNodes.begin(), costs.begin()); i.first != adjNodes.end(); ++ i.first, ++ i.second){
	
		int node = (*i.first);

		if (nodeVisited2(visited2, node)) 
			continue;

		if (node == end){
			visited2.push_back(*i.first);
			prevCost = cost;
			cost = cost + (*i.second);
			visitedCosts.push_back(cost);
			
			count ++;
			distanceDFS[count] = cost;

			int n = (int)visited2.size() - 1;
			visited2.erase(visited2.begin() + n);
			int m = (int)visitedCosts.size() - 1;
			visitedCosts.erase(visitedCosts.begin() + m);
			cost = prevCost;
		
			break;
		}
	}

	for (std::pair<iterNodes, iterCosts> i(adjNodes.begin(), costs.begin()); i.first != adjNodes.end(); ++ i.first, ++ i.second){

		int node = (*i.first);

		if (nodeVisited2(visited2, node) || node == end)
			continue;
		prevCost=cost;
		cost = cost + (*i.second);
		visited2.push_back(node);
		
		DFS(G, visited2,visitedCosts, end, cost, prevCost, count, distanceDFS);

		int n = (int)visited2.size() - 1;
		visited2.erase(visited2.begin() + n);
		int m = (int)visitedCosts.size() - 1;
		if(m > 0)
			visitedCosts.erase(visitedCosts.begin() + m);
		cost = prevCost;
	}

}

int minDistance(struct Graph* graph, int distanceDFS[N]){
	int min = inf;
	for(int j = 0;j <= graph->V; j ++)
		if(distanceDFS[j] < min && distanceDFS[j] > 0)
			min = distanceDFS[j];
	return min;
}

void bruteForceDijkstra(int source, Graph *G, MinHeap *mh, int end, int cost, int prevCost, int &count, int distance[N], int predecesor[N]){
	int destination;
	int minDistanceDFS[N] = {0}, distanceDFS[N] = {0};
	int cnt = 0;
	

		for(int i = 0; i <= G->V; i ++){
			distance[i] = 0;	
			minDistanceDFS[i]  = 0;
			distanceDFS[i] = 0;
		}

		std::vector<int> visited;
		std::vector<int> visitedCosts;
		
		DijkstraMH( G, source, mh, distance, predecesor);
		
		for(int destination = 1; destination <= G->V; destination ++){
		
			distanceDFS[source] = 0;//vector for all the paths from source to destination
		
			if(destination != source){
				visited.push_back(source);
				DFS(G, visited, visitedCosts, destination, cost, prevCost, count, distanceDFS);
				minDistanceDFS[destination] = minDistance( G, distanceDFS);

				for(int i = 0; i <= G->V; i ++)
					distanceDFS[i] = 0;				//reset the vector				
			}
		}

}