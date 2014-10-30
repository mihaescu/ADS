#ifndef __MSP_H__
#define __MSP_H__

#include"graph.h"
#include<limits.h>
#include<stdlib.h>

int min(int *dist, bool *set, int V);
void MSP(graph *g, int source, int *dist, int *pred);
int *createDist(graph *g);
int *createPred(graph *g);
void path(int *pred, int source, int destination);
void findPath(graph *g, int *dist, int *pred, int source);

#endif
