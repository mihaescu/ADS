#ifndef Header
#define Header

#include<stdio.h>
#include<stdlib.h>

struct Interval
{
	int lo;
	int hi;
};

struct BSTNode
{
	BSTNode *left;
	BSTNode *right;
	Interval nodeInfo;
	int maxRight;

};



struct BSTNode *insert(struct BSTNode *root,Interval *newInterval);
void searchPoint(struct BSTNode *node,int point,FILE *fo);
void segmentIntersect(struct BSTNode *node,Interval *interval,FILE *fo);
void displayTree(BSTNode *root, int level,FILE *fo);
Interval *createNewInterval(Interval *newNode,FILE *f);








#endif