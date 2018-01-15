#define FUNCTIONS_H_INCLUDED
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <fstream>
#include <time.h>
using namespace std;

typedef struct _Node
{
    int data;
    struct _Node *left;
    struct _Node *right;
}
Node;

Node *Add_Node(Node *node,int data);
void buildInput(ofstream &outputFile, int minValue, int MaxValue, int nrOfValues);
int countNodes(Node *node);
int computeIPL(Node *node,int value);
int internalPathLength(Node *node, int &count1);
float computeAveragePathLength(Node *node);

