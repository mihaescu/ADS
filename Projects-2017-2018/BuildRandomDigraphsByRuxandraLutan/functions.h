
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define new_node (struct node*)malloc(sizeof(struct node))
#define MAX_NODES 10000

struct node
{
    int vertex;
    struct node *next;
};

struct node *adjList[MAX_NODES];
int nodes, vertices;
int percent;
int visited[MAX_NODES];

int computeOutDegree(int x);
int valueAlreadyExists(int nodInitial, int nodFinal);
void createGraph ( struct node *adjList[MAX_NODES], int nodes, int vertices);
void printGraph(struct node *adjList[MAX_NODES], int nodes);

void DFS(int startNode);
int isGraphAcyclic(int nodes, int startNode);



