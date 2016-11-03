#ifndef _AVL_H_
#define _AVL_H_

#include<stdio.h>
#include<stdlib.h>

struct NodeAVL{
	int key;
	int echi;
	NodeAVL *left, *right;
};

//core functions
NodeAVL* insertAVLNode (NodeAVL *p, int x);
NodeAVL* deleteAVLNode (NodeAVL *p, int x);
void displayAVLTree (NodeAVL *p, int level);

//helper frunctions
int max( int a, int b);
int maxPathLength(NodeAVL *p);
void computeBalanceFactor (NodeAVL *p);
NodeAVL* leftRot (NodeAVL *p);
NodeAVL* rightRot (NodeAVL *p);
NodeAVL* doubleLeftRot (NodeAVL *p);
NodeAVL* doubleRightRot (NodeAVL *p);
NodeAVL* balance (NodeAVL *p);

//build input functions
void buildInput (int size, int min, int max, char file[]);

//test functions
//returns 1 if tree rooted at p is AVL or -1 otherwise
int test_insertAVLNode();
int test_deleteAVLNode();

//helper test functions
int isAVLTree(NodeAVL *p);

#endif