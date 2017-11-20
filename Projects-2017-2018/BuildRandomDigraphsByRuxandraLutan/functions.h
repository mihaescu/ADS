
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

int path_length(int x);
int value_in_path(int nod_initial, int nod_final);
void create_graph ( struct node *adj_list[MAX_NODES], int nodes, int vertices);
void print_graph(struct node *adj_list[MAX_NODES], int nodes);



