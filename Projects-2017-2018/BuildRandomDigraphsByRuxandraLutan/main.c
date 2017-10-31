#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define new_node (struct node*)malloc(sizeof(struct node))
#define MAX_NODES 10000

struct node
{
    int vertex;
    struct node *next;
};

struct node *adj_list[MAX_NODES];
int nodes, vertices;
int percent;

int path_length(int x) {
    int length = 0;
    struct node *p = adj_list[x];
    while(p != NULL) {
        length++;
        p = p -> next;
    }
    return length;
}

int value_in_path(int nod_initial, int nod_final) {
    struct node *p = adj_list[nod_initial];
    while(p != NULL) {
        if(p -> vertex == nod_final) {
            return 1;
        } else {
            p = p -> next;
        }
    }
    return 0;
}

int create_graph ( struct node *adj_list[MAX_NODES], int nodes, int vertices) {
    int i, j;
    int x, y;
    char reply;
    struct node *p, *c;
    int k = 0;

    while(k != vertices) {
        x = rand() % (nodes + 1);
        while(x == 0) {
            x = rand() % (nodes + 1);
        }
        //printf("x = ");
        //scanf("%d", &x);
        if(path_length(x) < nodes - 1) {
            y = rand() % (nodes + 1);
            while(y == 0 || x == y || value_in_path(x,y) == 1) {
                y = rand() % (nodes + 1);
            }

            //printf("y = ");
            //scanf("%d", &y);

            //inserarea elementelor arcului
            c = new_node;
            c -> vertex = y;
            c -> next = NULL;
            if ( adj_list[x] == NULL ) {
                adj_list[x] = c;
            } else {
                p = adj_list[x];
                while ( p -> next != NULL )
                    p = p -> next;
                p -> next = c;
            }
            k++;
        }
    }
}

print_graph(struct node *adj_list[MAX_NODES], int nodes) {
    FILE *out = fopen("output.txt", "w");

    fprintf(out, "%d %d\n", nodes, vertices);
    int i;
    struct node *p;
    for(i = 1; i <= nodes; i++) {
        p = adj_list[i];
        while(p != NULL) {
            fprintf(out, "%d %d \n", i, p->vertex);
            p = p->next;
        }
    }
}

int main()
{
    srand(time(NULL));

    printf("Nodes = ");
    scanf("%d", &nodes);
    printf("Vertices in percent = ");
    scanf("%d", &percent);

    vertices = percent * nodes * (nodes - 1) / 100;

    int i;
    for( i = 1 ; i <= nodes ; i++ )
        adj_list[i] = NULL;
    create_graph(adj_list, nodes, vertices);

    print_graph(adj_list, nodes);

    return 0;
}
