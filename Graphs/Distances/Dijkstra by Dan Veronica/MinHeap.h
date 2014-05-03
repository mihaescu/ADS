#ifndef __MinHeap_H__
#define __MinHeap_H__

#include"graph.h"

typedef struct MinHeapNode {
	int destinationVertex, distance;
} MinHeapNode;

typedef struct MinHeap {
	MinHeapNode heap[N];
	int seen[N];
	int heapSize;
} MinHeap;

void Init(MinHeap *mh);
void Insert(MinHeap *mh,MinHeapNode element);
MinHeapNode DeleteMin(MinHeap *mh);

#endif