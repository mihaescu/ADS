#include "Kruskall.h"

void readData(int &n, int &m, muchie u[20]){

	FILE* f = fopen("cost.txt", "rt");

	int use;

	if(f != NULL){

		fscanf(f, "%d", &n);
		fscanf(f, "%d", &use);

		int i = 0;

		while(!feof(f)){

			i++;

			fscanf(f, "%d %d %d", &u[i].x, &u[i].y, &u[i].c);

		}

		m = i;

		fclose(f);

	}

	for(int i = 0; i < m; i++)

		for(int j = i + 1; j < m; j++)

			if(u[i].c > u[j].c){

				muchie aux;

				aux = u[i];
				u[i] = u[j];
				u[j] = aux;

			}

}

void krusk(int &n, int &m, int L[20], muchie u[20]){

	int i = 1, k = 0, ct = 0;
	int x, y;

	readData(n, m, u);

	for(int i = 0 ; i < n ; i++)

		L[i] = i;

	printf("\n MST has the followind edges: \n");

	while(k < n-1){

		if(L[u[i].x] != L[u[i].y]){

			k++;

			ct = ct + u[i].c;

			printf("[%d <-> %d]\n", u[i].x, u[i].y);

			x = L[u[i].y];					//unite the MSTs through edge [x,y]
			y = L[u[i].x];

			for(int j = 0; j < n; j++)

				if(L[j] == x)

					L[j] = y;

		}

		i++;

	}

	printf("\n Total cost = %d \n",ct);

}
