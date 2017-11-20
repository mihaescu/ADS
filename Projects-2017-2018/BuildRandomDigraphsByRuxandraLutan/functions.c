#include "functions.h"
#include<string.h>

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

void create_graph ( struct node *adj_list[MAX_NODES], int nodes, int vertices) {

    int x, y;
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

void create_file_name(char filename[20]) {
    char aux[10];
    strcpy(filename, "dg_");
    itoa(nodes, aux, 10);
    strcat(filename, aux);
    strcat(filename, "n_%");
    itoa(percent, aux, 10);
    strcat(filename, aux);
    strcat(filename, "v");
    strcat(filename, ".txt");
}

void print_graph(struct node *adj_list[MAX_NODES], int nodes) {
    char filename[10];
    create_file_name(filename);
    //printf("%s ", filename);

    FILE *out = fopen(filename, "w");

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


