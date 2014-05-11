#include <stdlib.h>
#include <stdio.h>

#define NODES 6
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define INFINITE 10000000

void push(int** capacity, int** flow, int* excess, int u, int v);
void relabel(int** capacity, int** flow, int* height, int u);
void discharge(int * const * capacity, int** flow, int* excess, int* height, int* seen, int u);
void moveToFront(int i, int* list);
int pushRelabel(int** capacity, int** flow, int source, int sink);
void printMatrix(FILE* f, int** matrix);