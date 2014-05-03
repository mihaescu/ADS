#include "graph.h"

graph* loadGraph(FILE* fp)
{
	int V, E;
	fscanf(fp, "%d", &V);
	fscanf(fp, "%d", &E);

	graph *G = (graph*)malloc(sizeof(graph));					// allocate memory for the graph
	G->noOfVertices = V;											// set the number of vertixes
	G->noOfEdges = E;												// set the number of edges

	G->pEdge = (edge*)malloc(sizeof(edge)*G->noOfEdges);			// allocate memory for the edges
	for (int i = 0; i<E; i++)										// set the edges
	{
		fscanf(fp, "%d", &G->pEdge[i].source);
		fscanf(fp, "%d", &G->pEdge[i].destination);
		fscanf(fp, "%d", &G->pEdge[i].weight);
	}

	fclose(fp);
	return G;													// return the graph
}


void graphGenerator(char * fileName)
{
	int noOfEdges = 0;
	srand(time(0));

	FILE *fp = fopen(fileName, "w");
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

bool nodeVisited(std::vector<int> &visited, int node)
{
	for (unsigned int i = 0; i < visited.size(); i++)						//search the visited vector for the node value
	if (node == visited[i])													//if found return true
		return true;
	return false;															//else false
}

std::vector<int> getAdjCosts(Graph *G, int node) {

	std::vector<int> costs;

	for (int i = 0; i < G->E;i++)
		if (G->adjListarr[i].source == node)
			costs.push_back(G->adjListarr[i].cost);
	
	return costs;
}