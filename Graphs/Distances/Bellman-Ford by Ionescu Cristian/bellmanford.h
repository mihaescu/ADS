#ifndef BELLMANFORD_H
#define BELLMANFORD_H
#include"graph.h"
#define infinite INT_MAX
#define minfinite INT_MIN
											

void BellmanFord(graph *G,int source,int **cost,int *predecesors);					// bellman ford algorithm
																					// Ggraph - the graph on which bellman ford is performed,source - the source vertex, 
																					// cost - a 2d array in which we hold the minimum distance between the source and all other vertices
																					// predecesors - an array in which we store for each vertex it's predecesor

void reconstructPath(int source, int destination, graph *G, int *predecesors);		//function that reconstructs the predecesors from the source to the desired vertex of the Graph

int *allocateMemoryForPredecesors(int noOfVertices);								//function which allocates memory for the predecesor array and returns the array, noOfVertices represent the number of vertices the graph has

int **alocateMemoryForCost(int noOfVertices);										//function which allocates memory for the cost matrix and return the matrix,noOfVertices represent the number of vertices the graph has

void driverProgram(char *inputFile, char *outputFile);								//sample function for bellman-ford
int speedTest(graph *G);															

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------TESTING------------------------------------------------------------------------------------------------


void DFS(graph *G, std::vector<int> &visited, int end, int &cost);					//DFS backtracking method for generating all acycle paths between two nodes

int calculateCost(graph *G, std::vector<int> &visited);								//function which calculates the cost of the path

bool compareFiles(FILE *fp1, FILE *fp2);

void testProgram();
#endif
