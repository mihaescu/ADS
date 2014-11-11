#ifndef __BTREE_H__
#define __BTREE_H__
#define m 4
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include<string.h>
#define MAX 10001

/** STRUCTURE */

typedef struct NodeB_
{
    int nr;
    int keys[m+1];
    struct NodeB_ *pNodes[m+1];
}NodeB;

/** DATA MANAGERS*/
void Generate(FILE *f1,int n, int a, int b);
void LoadData(FILE *f1,int n,int vect[MAX]);

/** MAIN FUNCTIONS*/
NodeB *Insert(NodeB *root, int x);
void Search(NodeB *r, int x);
void DeleteKey(NodeB **node, int key);
void DisplayTree(NodeB *node, int lever);

/** UTIL FUNCTIONS*/
void SplitPage(NodeB *page, int x, int *ind, int *urc, int *h, NodeB **adr, NodeB **purc);
void PlaceInPage(NodeB *page, int k, int x, int *ind, int *urc, int *h, NodeB **adr, NodeB **purc);
void InsertInNonFullLeaf(NodeB *r, int k, int x, int *ind, int *urc, int *h, NodeB **adr, NodeB **purc);
void CopyPage(NodeB *destination, NodeB *source, int destIndex, int sourceIndex, int n);
int FindMinimum(NodeB *node);

/**TEST FUNCTIONS*/




#endif

