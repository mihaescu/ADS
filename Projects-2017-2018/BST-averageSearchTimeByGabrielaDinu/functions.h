#define FUNCTIONS_H_INCLUDED
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <fstream>
using namespace std;

typedef struct _Node
{
    int data;
    struct _Node *left;
    struct _Node *right;
}
Node;

int count_nodes(Node *node);
void buildInput(ofstream &outputFile, int minValue, int MaxValue, int nrOfValues);
Node *Add_Node(Node *root,int data);
int computeIPL(Node *root,int value);
float computeAveragePathLength(Node *root);


