#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define LEFT 0
#define RIGHT 1
#define PLUS_INFINTI INT_MAX
#define MINUS_INFINIT -INT_MAX

struct NodeTreap
{
	NodeTreap *left, *right, *parent;
	int element;
	float priority;
};

NodeTreap* insert(NodeTreap*, int, float);
int member(NodeTreap *, int );
NodeTreap* deleteTreap(NodeTreap*, int);
void displayTreap(NodeTreap*, int);
void splitTreap(NodeTreap*,int);
void mergeTreaps(NodeTreap* , NodeTreap* , NodeTreap*);
void rotate(NodeTreap*, NodeTreap*);
