#include<stdio.h>
//#include<conio.h>
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

void insert(NodeTreap *current, int element, float pr);
int member(NodeTreap *current, int element);
void deleteTreap(NodeTreap *current, int element);
void displayTreap(NodeTreap parent, int k);
void splitTreap(NodeTreap *current,int element);
void mergeTreaps(NodeTreap* current, NodeTreap* tle, NodeTreap* tla);