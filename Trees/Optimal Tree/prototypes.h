#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

typedef struct _Node{
	int data;
	struct _Node *left;
	struct _Node *right;
}Node;

void Display(Node* root, int nivel);
Node *Add_Node(Node *root, int data);
Node* FindMin(Node* root);
Node* Delete(Node *root, int data);
int search_node(Node *root, int data);
#endif // PROTOTYPES_H_INCLUDED