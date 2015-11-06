#include "roy-floyd.h"

#include <stdio.h>
#include <conio.h>
#include <iostream>

void initial_cost(int cost[100][100], int &n, int &m)
{
    int i, j, x, y, c;
    
	FILE *f;
	f = fopen("roy_in.txt", "rt");
    if(f)
		printf("The file has been successfuly opened! ");
    else
		printf("Error opening file! ");
    
	printf("\n");
    fscanf(f, "%d", &n);
    fscanf(f, "%d\n", &m);

    for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
		{
			if(i == j)
				cost[i][j] = 0;
			else
				cost[i][j] = 9000;
		}

    for(i = 1; i <= m; i++)
    {
		fscanf(f,"%d%d%d\n", &x, &y, &c);
		cost[x][y] = c;
    }

    fclose(f);
}


void display_matrix(int cost[100][100], int n)

{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
			if(cost[i][j] == 9000)
				printf("   -");
			else
				printf("%4d", cost[i][j]);
           printf("\n");
    }
}


void Roy_Floyd(int cost[100][100], int n)

{

    for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(cost[i][j] > cost[i][k] + cost[k][j])
					cost[i][j] = cost[i][k] + cost[k][j];
}


void print_path (int first, int last, int cost[100][100], int n)
{
    if(cost[first][last] < 9000)
    {
        printf("\n The path from %d to %d has the weight %d", first, last, cost[first][last]);
        printf("\n The minimum cost path is: %d", first);
        compute_path(first,last, n, cost);
    }
    else
		printf("\n There is no path between %d to %d", first, last);
}


void compute_path(int i, int j, int n, int cost[100][100])
{
    int ok = 0, k = 1;

    while(k <= n && !ok)
    {
        if(i != k && j != k)
			if(cost[i][j] == cost[i][k] + cost[k][j])
			{
				compute_path(i, k, n, cost);
				compute_path(k, j, n, cost);
				ok = 1;
			}
        k++;
    }
    if(!ok)
    {
        printf("%d", j);
    }
}

