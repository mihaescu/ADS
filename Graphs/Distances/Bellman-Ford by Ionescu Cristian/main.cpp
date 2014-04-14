#include"bellmanford.h"

int main()
{
	int V;												// Number of vertices in graph
	int **ncost;										// minimum weight between Source and Destination

	FILE *fp = fopen("input.in", "r");					//input file
	fscanf(fp, "%d", &V);								//read the number of vertices
	fclose(fp);


	int *predecesors = allocateMemoryForPredecesors(V);	//alocate memory for the predecesors array
	ncost = alocateMemoryForCost(V);					//allocate memory for the cost matrix
	


	fp = fopen("input.in", "r");
	graph* G = createGraph(fp);							//create the graph

	FILE *fout = fopen("output.out", "w");
	int okP;			
	//principal exit variabile if assigned 0
	do
	{
		int source;
		printf("give the source vertex:");
		scanf("%d", &source);
		BellmanFord(G, source, ncost, predecesors);
		for (int i = 0; i < V; i++)													//print the cost between source and all other vertixes
		{
			fprintf_s(fout, "%d\n", ncost[1][i]);
			//printf("The minimum cost between %d and %d is %d\n", source, ncost[0][i], ncost[1][i]);
		}
		fclose(fout);
		FILE *bellman = fopen("output.out", "r");
		FILE *test = fopen("result.txt", "r");
		if (compareFiles(bellman, test))
		{
			printf_s("Test succeded!\n");
		}
		else
		{
			printf_s("Test failed!\n");
		}
		int okS;																	//secondary exit variable if assigned 0
		do
		{
			int destination;							
			printf("give the vertex to which you want to reconstruct the path:");
			scanf("%d", &destination);
			if (ncost[1][destination] == infinite)
				printf("there is no path to %d from %d\n", destination, source);
			else
			if (ncost[1][destination] == minfinite)
			{
				printf("it is a negative cycle cannot display path\n");
			}
			else
				reconstructPath(source, destination, G,predecesors);

			printf("press 0 to exit");
			scanf("%d", &okS);
		} while (okS);

		printf("press 0 to exit\n");
		scanf("%d", &okP);

	} while (okP);
	system("PAUSE");
	return 1;
}