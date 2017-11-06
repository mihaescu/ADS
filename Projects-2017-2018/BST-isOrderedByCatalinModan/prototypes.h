#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <time.h>
#define G_plaja_valori 1000






typedef struct _Node {
        int data;
        struct _Node *left;
        struct _Node *right;
}
Node;



void Display( Node *root, int nivel );
Node *Add_Node( Node *root, int data );
void preorder( Node *root );
void inorder( Node *root );
void postorder( Node *root );
Node *FindMin( Node *root );
Node *FindMax( Node *root );
Node *Delete( Node *root, int data );
int getMin( Node *node );
int getMax( Node *node );
int randomNumberGenerator();
bool checkValues( Node *node, int minimum, int maximum );



#endif // PROTOTYPES_H_INCLUDED
