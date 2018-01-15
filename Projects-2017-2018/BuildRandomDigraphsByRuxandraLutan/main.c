#include "functions.h"

int main()
{
    srand(time(NULL));

    int noGraphs, g;
    FILE *in = fopen("input.txt", "r");
    fscanf(in, "%d", &noGraphs);

    for(g = 1; g <= noGraphs; g++) {
        fscanf(in, "%d %d", &nodes, &percent);
        vertices = percent * nodes * (nodes - 1) / 100;

        if(percent >= 50) {
            char filename[10];
            createFileName(filename);
            FILE *out = fopen(filename, "w");
            fprintf(out, "Cannot create an acyclic Digraph with %d percent vertices!!!", percent);
        } else {
            int i;
            for( i = 1 ; i <= nodes ; i++ )
                adjList[i] = NULL;
            createGraph(adjList, nodes, vertices);
            printGraph(adjList, nodes);
        }
        if(g == 10)
           break;
    }

    return 0;
}



