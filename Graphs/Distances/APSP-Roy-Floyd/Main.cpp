#include <stdio.h>
#include <conio.h>
#include <iostream>

#include "Header.h"

int main()

{
    char ch;
    int x, y, n, m;
	int cost[100][100];

	initial_cost(cost, n, m);

    printf("\n The weight matrix is:\n");
    display_matrix(cost, n);
    Roy_Floyd(cost, n);

    printf("\n The minimum cost matrix is:\n");
    display_matrix(cost, n);

    do
    {
        printf("\n\nDetermine which is the minimum cost path between two nodes of the graph\n");
        printf("x= ");
        scanf("%d", &x);
        
		printf("y= ");
        scanf("%d", &y);
        print_path(x, y, cost, n);
        
		printf("\n\n\n Do you want to find a path between other nodes from the graph? <y/n>");
        ch = getch();
    }
    while(ch == 'y' ||ch == 'Y');

    getch();
    return 0;
}
