#include <stdio.h>
#include <conio.h>
#include "graph.h";
#include "topologicalSort.h"

int main()
{
	FILE *f = fopen("date.in", "rt");
	graph *G = loadGraph(f);

	int *sortedGraphNodes = TopologicalSort(G);


	int i = 0;

	printf("DFS Topological Sort:\n");
	if (sortedGraphNodes == NULL)
	{
		printf("This graph is not valid\n");
	}
	else
	{
		for (i; i < G->noOfVertices; i++)
		{
			printf("%d ", sortedGraphNodes[i]);
		}
	}

	sortedGraphNodes = TopSortIndegree(G);

	printf("\nIndegree Topological Sort:\n");

	if (sortedGraphNodes == NULL)
	{
		printf("This graph is not valid\n");
	}
	else
	{
		for (i = 0; i < G->noOfVertices; i++)
		{
			printf("%d ", sortedGraphNodes[i]);
		}
	}

	printf("\n%d\n", ValidateTopSort(G, sortedGraphNodes));

	_getch();
	return  0;
}