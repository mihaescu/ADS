#include <stdio.h>
#include"MinHeap.h"
#include "Graph.h"

void Init(MinHeap *mh){

   mh->heapSize = 0;
   mh->heap[0].distance = -N;
   mh->heap[0].destinationVertex  = -1;
}
void Insert(MinHeap *mh,MinHeapNode element){
    
	mh->heapSize++;
    mh->heap[ mh->heapSize] = element;
   
   int current =  mh->heapSize;
   while( mh->heap[current/2].distance > element.distance){
		 mh->heap[current] =  mh->heap[current/2];
        current /= 2;
   }
	 mh-> heap[current] = element;
}
MinHeapNode DeleteMin(MinHeap *mh){
		
	MinHeapNode minElement,lastElement;
    int child,current;
    minElement =  mh->heap[1];
    lastElement =  mh->heap[ mh->heapSize--];

    for(current = 1; current*2 <=  mh->heapSize ;current = child){
              
		child = current*2;
              
        if(child !=  mh->heapSize &&  mh->heap[child+1].distance <  mh->heap[child].distance ) 
			child++;
                
               
        if(lastElement.distance >  mh->heap[child].distance)
			 mh->heap[current] =  mh->heap[child];
		else
			break;
                
       }
	mh->heap[current] = lastElement;
    return minElement;
}