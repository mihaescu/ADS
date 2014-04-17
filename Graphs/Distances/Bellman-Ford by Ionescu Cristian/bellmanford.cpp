#include"bellmanford.h"



graph *createGraph(FILE *fp)									// creates a graph with V vertixes and E edges
{
	int V,E;
	fscanf(fp,"%d",&V);
	fscanf(fp,"%d",&E);

	graph *G=( graph*)malloc(sizeof(graph));					// allocate memory for the graph
	G->noOfVertices=V;											// set the number of vertixes
	G->noOfEdges=E;												// set the number of edges

	G->pEdge=(edge*)malloc(sizeof(edge)*G->noOfEdges);			// allocate memory for the edges
	for(int i=0;i<E;i++)										// set the edges
	{
		fscanf(fp,"%d",&G->pEdge[i].source);
		fscanf(fp,"%d",&G->pEdge[i].destination);
		fscanf(fp,"%d",&G->pEdge[i].weight);
	}

	fclose(fp);
	return G;													// return the graph
}

void BellmanFord(graph *G,int source,int **cost,int *predecesors)												
/// bellmanford alogrithm
{
	
	// set all costs to infinite
	for(int i =0;i<G->noOfVertices;i++)																	
	{
		cost[1][i]=infinite;
	}
	int u, v,weight;
	//set the cost of the source to 0
	cost[1][source]=0;																						

	// relax all edges V-1 times
	for(int i=0;i<G->noOfVertices;i++)							
	{	//for each "j" edge between 2 vertexes source - destination
		for(int j=0;j<G->noOfEdges;j++)																			
		{
			u = cost[1][G->pEdge[j].source];
			v = cost[1][G->pEdge[j].destination];
			weight = G->pEdge[j].weight;
			if( u < v - weight)																					//if current weight of the destination vertex is bigger than the sum
			{																									// of the source weight and edge weight
				cost[1][G->pEdge[j].destination] = cost[1][G->pEdge[j].source] + G->pEdge[j].weight;			// then update the destination weight
				predecesors[G->pEdge[j].destination]=G->pEdge[j].source;										// update his predecesor
			}
		}
	}


	//check if there is a negative weight cycle.
	for(int i=0;i<G->noOfEdges;i++)
	{
		if(cost[1][G->pEdge[i].source] < cost[1][G->pEdge[i].destination] - G->pEdge[i].weight)			// if we find a smaller weight than the weight found previous,
		{																								// then the graph contains a negative weight cycle
			cost[1][G->pEdge[i].destination]=minfinite;
		}
	}
}

void reconstructPath( int source, int destination, graph *G, int *predecesors)	//function that reconstructs the predecesors from the source to the desired vertex of the Graph
{
	int *aStack = (int*)malloc(sizeof(int)*G->noOfVertices);					// a pseudo-stack in which at the end,the source will be at the top
	int top = 0;

	while (source != destination)												//pseudo-push into stack
	{
		aStack[top] = destination;
		top++;
		destination = predecesors[destination];
	}

	aStack[top] = source;


	printf("the path is:");
	while (top>=0)																//pseudo-pop all the elements
	{
		printf(" %d ", aStack[top]);
		top--;
	}
	printf("\n");
	free(aStack);
}

int *allocateMemoryForPredecesors(int noOfVertices)
{
	int *predecesors = (int*)malloc(sizeof(int)*noOfVertices);			//predecesors array memmory allocation
	for (int i = 0; i < noOfVertices; i++)
	{
		predecesors[i] = i;												//set one vertex predecesor to himself
	}

	return predecesors;													//return the array
}

int **alocateMemoryForCost(int noOfVertices)
{
	int **cost = (int**)malloc(sizeof(int*));							//cost matrix memmory allocation
	for (int i = 0; i < 2; i++)
		cost[i] = (int*)malloc(sizeof(int)*noOfVertices);


	for (int i = 0; i < noOfVertices; i++)
	{
		cost[0][i] = i;													//set the first line of the cost matrix with the vertices
	}
	return cost;														//return the matrix
}

void driverProgram(char *inputFile, char *outputFile)
{
	FILE *fin = fopen(inputFile, "r");
	FILE *fout = fopen(outputFile, "w");
	int source;
	graph *G = loadGraph(fin);
	int **cost = alocateMemoryForCost(G->noOfVertices);
	int *predecesors = allocateMemoryForPredecesors(G->noOfVertices);

	


	printf_s("Give the source vertex:");
	scanf_s("%d", &source);
	BellmanFord(G, source, cost, predecesors);
	for (int i = 0; i < G->noOfVertices; i++)
	{
		fprintf_s(fout, "%d\n", cost[1][i]);
	}

	while (true)
	{
		int destination;
		printf_s("Give the vertex to which you want to reconstruct the path:");
		scanf_s("%d", &destination);
		if (cost[1][destination] == infinite)
		{
			printf_s("there is no path to %d from %d\n", destination, source);
		}
		else if (cost[1][destination] == minfinite)
		{
			printf_s("it is a negative cycle cannot display path\n");
		}
		else
		{
			reconstructPath(source, destination, G, predecesors);
		}

		printf_s("Continue? \n1.Yes\n0.No\n");
		int dummy;
		scanf_s("%d",&dummy);
		if (dummy == 0)
		{
			break;
		}
	}
	fclose(fin);
	fclose(fout);
}


int speedTest(graph *G)
{
	int *predecesors = allocateMemoryForPredecesors(G->noOfVertices);	
	int **cost = alocateMemoryForCost(G->noOfVertices);					
	int source, t0, test[10];
	int average = 0;
	printf_s("give the source vertex:");
	scanf_s("%d", &source);
	for (int i = 0; i < 10; i++)
	{
		t0 = clock();
		BellmanFord(G, source, cost, predecesors);
		test[i] = clock() - t0;
		average += test[i];
	}

	return average / 10;

}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------TESTING------------------------------------------------------------------------------------------------

int calculateCost(graph *G, std::vector<int> &visited)
{
	int cost = 0;
	for (unsigned int j = 0; j<visited.size() - 1; j++)								//for all the nodes in the path
	{
		int source = visited[j];
		int destination = visited[j + 1];

		for (int i = 0; i<G->noOfEdges; i++)								//find their edge
		{
			if (G->pEdge[i].source == source && G->pEdge[i].destination == destination)
			{
				cost += G->pEdge[i].weight;									//add the edge weight
			}
		}
	}
	return cost;
}


void DFS(graph *G, std::vector<int> &visited, int end, int &cost)
{
	int temp;
	int back;
	int i;
	back = visited.back();
	std::vector<int> adjNodes = getAdjNodes(G, back);						//get the last node adiance nodes
	for (std::vector<int>::iterator node_it = adjNodes.begin();				//for all adiance nodes
		node_it != adjNodes.end();
		node_it++)
	{
		int node = (*node_it);
		if (nodeVisited(visited, node)) continue;							//check if the node has ben visited

		if (node == end)													//if the node is the one we search
		{
			visited.push_back(*node_it);									//add it to the path

			int hops = (int)visited.size();

			for (i = 0; i < hops; i++)
			{
				//std::cout << visited[i] << " ";
				temp = calculateCost(G, visited);							//calculate the path cost
				if (cost > temp)
					cost = temp;
			}

			int n = (int)visited.size() - 1;								
			visited.erase(visited.begin() + n);								//clear the path and keep only the source vertex

			break;
		}
	}
	for (std::vector<int>::iterator node_it = adjNodes.begin();				//for each node in the adiance list
		node_it != adjNodes.end();
		node_it++)
	{
		int node = (*node_it);

		if (nodeVisited(visited, node) || node == end)						//if the node has been visited or it's the node we search continue
			continue;

		visited.push_back(node);											//otherwise put the node in the path

		DFS(G, visited, end, cost);											//backtrack

		int n = (int)visited.size() - 1;									
		visited.erase(visited.begin() + n);									//clear the path and keep only the source vertex
	}
}

bool compareFiles(FILE *fp1, FILE *fp2)										//compare two files
{
	int a, b;																//it is know that the file data is interger type
	while (!feof(fp1) && !feof(fp2))										//while both files have data
	{
		fscanf_s(fp1, "%d", &a);											//read them
		fscanf_s(fp2, "%d", &b);
		if (a != b)															//comapre if are the same
		{
			return false;													//return false if not so
		}
	}
	return true;															//otherwise return true5
}

void testProgram()
{
	FILE *file1 = fopen("input.in", "r");
	FILE *file2 = fopen("output.data", "w");

	graph *G = loadGraph(file1);
	int **testcost = alocateMemoryForCost(G->noOfVertices);
	int *testpredecesors = allocateMemoryForPredecesors(G->noOfVertices);


	BellmanFord(G, 0, testcost, testpredecesors);
	for (int i = 0; i < G->noOfVertices; i++)
	{
		fprintf_s(file2, "%d\n", testcost[1][i]);
	}
	fclose(file1);
	fclose(file2);
	file1 = fopen("output.data", "r");
	file2 = fopen("result.txt", "r");

	if (compareFiles(file1, file2))
	{
		printf_s("Test succeded!\n");
	}
	else
	{
		printf_s("Test failed!\n");
	}

}
