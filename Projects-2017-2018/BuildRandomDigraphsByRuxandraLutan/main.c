#include "functions.h"

int main()
{
    srand(time(NULL));

    int no_graphs, g;
    FILE *in = fopen("input.txt", "r");
    fscanf(in, "%d", &no_graphs);

    for(g = 1; g <= no_graphs; g++) {
        fscanf(in, "%d %d", &nodes, &percent);
        vertices = percent * nodes * (nodes - 1) / 100;

        int i;
        for( i = 1 ; i <= nodes ; i++ )
            adj_list[i] = NULL;
        create_graph(adj_list, nodes, vertices);

        print_graph(adj_list, nodes);
    }

    return 0;
}
