
#define PROTOTYPES_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

typedef struct _Node
{
    int data;
    struct _Node *left;
    struct _Node *right;
}
Node;
int count_nodes (Node *node);
int maxDepth(Node* node) ;
Node *Add_Node(Node *root,int data);


