#ifndef topologicalSort_h
#define topologicalSort_h

#include "graph.h"
#include <stdio.h>
#include <queue>
typedef enum color {white, gray, black};
typedef enum method{ dfs, indegree };

int* TopologicalSort(graph* );
int TopSortDFS(graph*, int, color*, int*, int*);
int* TopSortIndegree(graph*);
int ValidateTopSort(graph*, const int*);
#endif