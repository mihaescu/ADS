#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <time.h>
#include <fstream>
using namespace std;
extern bool is_search;

typedef struct _Node
{
	int data;
	struct _Node *left;
	struct _Node *right;
}
Node;

void Display(Node* root, int nivel);
Node *Add_Node(Node *root, int data);
Node* Delete(Node *root, int data);
Node* FindMin(Node* root);
bool Search(Node *root, int data);
int internalPathLength(Node *t, int value);
void insert_in_file(fstream &f, Node *root);
#endif // PROTOTYPES_H_INCLUDED
