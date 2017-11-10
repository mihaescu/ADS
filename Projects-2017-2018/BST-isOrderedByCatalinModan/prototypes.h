#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED

//Libraries definitions
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <time.h>
#define G_plaja_valori 1000





//Structure definition
typedef struct _Node {
        int data;
        struct _Node *left;
        struct _Node *right;
}
Node;


//Prototypes definitions

Node *Add_Node( Node *root, int data );
Node *Delete( Node *root, int data );

void preorder( Node *root );
void inorder( Node *root );
void postorder( Node *root );

void Display( Node *root, int nivel );

Node *FindMin( Node *root );
Node *FindMax( Node *root );

int getMin( Node *node );
int getMax( Node *node );

int randomNumberGenerator();
bool checkValues( Node *node, int minimum, int maximum );



#endif // PROTOTYPES_H_INCLUDED
