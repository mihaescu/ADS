#ifndef __BTREE_H__
#define __BTREE_H__
#define m 4
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct NodeB_
{
    int nr;
    int keys[m+1];
    struct NodeB_ *pNodes[m+1];
}NodeB;

NodeB *Insert(NodeB *root, int x);
void SplitPage(NodeB *page, int x, int *ind, int *urc, int *h, NodeB **adr, NodeB **purc);
void PlaceInPage(NodeB *page, int k, int x, int *ind, int *urc, int *h, NodeB **adr, NodeB **purc);
void InsertInNonFullLeaf(NodeB *r, int k, int x, int *ind, int *urc, int *h, NodeB **adr, NodeB **purc);
void CopyPage(NodeB *destination, NodeB *source, int destIndex, int sourceIndex, int n);
void Search(NodeB *r, int x);
void DisplayTree(NodeB *node, int lever);
void DeleteKey(NodeB **node, int key);
int FindMinimum(NodeB *node);

#endif
