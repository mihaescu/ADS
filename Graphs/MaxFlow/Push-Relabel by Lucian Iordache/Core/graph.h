#include<stdlib.h>
#include<stdio.h>


/* for adjacency matrix representation*/
typedef struct adjMatrixGraph							//structure for adjMatrixGraph
{
	int noOfVertices;							//number of vertixes
	int noOfEdges;							    //number of edges
	int **capacities;							//capacity matrix
	int **flow;									//flow matrix
};

adjMatrixGraph* loadAdjMatrixGraph(FILE* fp);				    //function for creating adjacency matrix

void printCapacitiesMatrix(FILE* f, adjMatrixGraph *G);			//Function that display capacities matrix

void printFlowMatrix(FILE* f, adjMatrixGraph *G);                //Function that display flow matrix