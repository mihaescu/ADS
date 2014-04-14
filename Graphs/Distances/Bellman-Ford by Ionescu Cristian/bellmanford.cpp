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

void BellmanFord(graph *G,int source,int **cost,int *predecesors)												// bellmanford alogrithm
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

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------TESTING------------------------------------------------------------------------------------------------

void graphGenerator()
{
	int noOfEdges = 0;
	srand(time(0));

	FILE *fp = fopen("testsample.txt", "w");
	int noOfVertices = 50;													//the number of vertices the graph will have
	for (int i = 0; i<noOfVertices; i++)									//for each vertex generate between 1 and 4 edges
	{
		int currEdges = rand() % 3 + 1;
		noOfEdges += currEdges;												//add them to the total number of vertices
		edge *pEdge = (edge*)malloc(sizeof(edge)*currEdges);				//alloc memory for vertex's edges
		for (int j = 0; j<currEdges; j++)									//for each edge
		{
			bool exists;
			do
			{
				pEdge[j].destination = rand() % noOfVertices;				//give a destination vertex
				pEdge[j].source = i;										//mark its source
				pEdge[j].weight = rand() % 30;								//give a weight
				exists = false;
				for (int k = 0; k<j; k++)									//check if the already exists or the vertex has an edge to himself
				if (pEdge[j].destination == pEdge[k].destination || pEdge[j].destination == pEdge[j].source)
				{
					exists = true;
				}
				if (exists == false)										//if the edge doesn't exist,write the edge
				{
					fprintf(fp, "%d %d %d\n", pEdge[j].source, pEdge[j].destination, pEdge[j].weight);
					//printf("%d %d %d\n",pEdge[j].source,pEdge[j].destination,pEdge[j].weight);
				}
			} while (exists == true);
		}

		free(pEdge);														//dealloc pEdge memory
	}
	fprintf(fp, "%d %d\n", noOfVertices, noOfEdges);						//write the total number of vertices and edges
	fclose(fp);
}

bool containsNode(std::vector<int> &visited, int node)
{
	for (unsigned int i = 0; i < visited.size(); i++)						//search the visited vector for the node value
	if (node == visited[i])													//if found return true
		return true;
	return false;															//else false
}

std::vector<int> getAdjNodes(graph *G, int node)							
{
	std::vector<int> nodes;																
	for (int i = 0; i < G->noOfEdges; i++)									//search all graph edges
	if (G->pEdge[i].source == node)											//if edge source is "node"
	{
		nodes.push_back(G->pEdge[i].destination);							//memorize its destination
	}
	return nodes;															//return the destination nodes
}

int calculateCost(graph *G, std::vector<int> &visited)
{
	int cost = 0;
	for (int j = 0; j<visited.size() - 1; j++)								//for all the nodes in the path
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
		if (containsNode(visited, node)) continue;							//check if the node has ben visited

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

		if (containsNode(visited, node) || node == end)						//if the node has been visited or it's the node we search continue
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