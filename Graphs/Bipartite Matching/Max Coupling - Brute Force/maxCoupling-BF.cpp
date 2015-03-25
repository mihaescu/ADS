#include<stdio.h>
#define Nmax 10

int used[Nmax] ;//holds the used vertexes in the coupling
int graph[Nmax][Nmax] ;// adjacency matrix of the graph
int nrOfEdges; //number of edges in the graph
int nrOfVertices; //number of vertices in the graph
int coupling[Nmax][2]; //the obtained coupling

int buildPerfectCoupling(int k) { 
    int i ,ret;
    if ( !used[k] ) { 
       used[k]=1;
       for( i=0; i<nrOfVertices; i++)
            if( graph[i][k] && !used[i] ) {
                used[i] = 1;
                coupling[nrOfEdges][0] = i;
                coupling[nrOfEdges][1] = k;
                if ( k == nrOfVertices-1){
                   return 1;
                }else{ 
                  nrOfEdges++;
                  ret = buildPerfectCoupling(k+1);
                  if ( ret )
                     return 1;
                  nrOfEdges--;
                }
                used[i] = 0; 
            }
            used[k] = 0;
            return 0; 
    }else{
          if( k == nrOfVertices-1){
              return 1;
          }else {
                return buildPerfectCoupling(k+1);
          }
    }
}

int main(void) {
    int i ,j;
    printf("Number of vertices: ");
    scanf("%d",&nrOfVertices);  
    printf("Input the adjacency matrix (0/1):\n");
    for ( i=0; i<nrOfVertices;i++){
        for(j=0; j<nrOfVertices; j++)
                 scanf("%d",&graph[i][j]);
        used[i]=0;
    }
    if( buildPerfectCoupling(0) ) {
        printf("Perfect coupling is:\n");
        for(j=0; j<nrOfEdges; j++)
             printf("%d-%d\n",coupling[j][0],coupling[j][1]);
    }else{
	     printf("A perfect coupling do not exist!");
    }
    return 1;
}
