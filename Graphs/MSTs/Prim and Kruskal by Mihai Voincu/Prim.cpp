#include "Prim.h"
#include "Graph.h"

int findEdge(int a[50][50], int Q[50], int n){

	int i,j,min = VMAX;

	for(i = 1; i <= n; i++)

		if(Q[i] != 0 && a[Q[i]][i] < min){

			min = a[Q[i]][i];
			j = i;

		}

	return j;

}

void init(int a[50][50], int Q[50], int H[50], int n){

	for(int i = 0; i < 50; i++){

		Q[i]=0;
		H[i]=0;

		for(int j = 0; j < 50; j++)

			a[i][j] = 0;

	}

}

void updateQ(int a[50][50], int Q[50], int n, int j){

	for(int i = 1; i <= n; i++)

		if(Q[i] != 0 && a[i][Q[i]] > a[i][j])

			Q[i] = j;
}

void displayMST(int H[50], int n){

	printf("\n MST has the followind edges: \n");

	for(int i = 1; i <= n; i++)

		if(H[i] != 0 )

			printf("[%d <-> %d] \n", H[i], i);
}

int prim(int a[50][50], int Q[50], int H[50], int &n, int &r, graph *G){

//-----------------------------------------Loading--------------------------------------
	int k = 0, ct = 0;

	int x, y, c ,i, j;

	n = G->noOfVertices;
	r = 1;

	init(a,Q,H,n);	

	for(i = 1; i <= n; i++){

			for(j = 1; j <= n; j++){

				if(i != j){

					a[i][j] = VMAX;

				}

			}

		}

	for(i = 0; i < n; i++){

		x = G->pEdge[i].source;
		y = G->pEdge[i].destination;
		c = G->pEdge[i].weight;

		a[x][y] = a[y][x] = c;
		
		}

	for(i = 1; i <= n; i++)

			if(i != r)

				Q[i] = r;

//----------------------------------------------EnD------------------------------------------------
//---------------------------------------------Prim------------------------------------------------

	while(k < n-1){					//until there are still more edges
		
		j = findEdge(a,Q,n);		//choose a minimum cost edge that does not form a cycle

		H[j] = Q[j];
		ct += a[Q[j]][j];			//add the edge in the MST and its cost to the total cost

		Q[j] = 0;					//delete the added node
		updateQ(a,Q,n,j);			//update the priority queue

		k++;
	}

	return ct;

}
		 
