#ifndef _AVL_H_
#define _AVL_H_

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<math.h>
#include<time.h>
using namespace std;
struct NodeAVL{
	int key;
	int echi;
	NodeAVL *left, *right;
};

int max( int a, int b);
int maxPathLength(NodeAVL *p);
void computeBalanceFactor (NodeAVL *p);
NodeAVL* leftRot (NodeAVL *p);
NodeAVL* rightRot (NodeAVL *p);
NodeAVL* doubleLeftRot (NodeAVL *p);
NodeAVL* doubleRightRot (NodeAVL *p);
NodeAVL* balance (NodeAVL *p);
NodeAVL* insertAVLNode (NodeAVL *p, int x);
NodeAVL* deleteAVLNode (NodeAVL *p, int x);
void displayAVLTree( NodeAVL *node, int level);
void afisare_meniu(NodeAVL *root);
void cauta_nod(NodeAVL *node, int value,int *found);
int test_insertAVLNode(char file[]);
int test_deleteAVLNode(char file[]);
int isAVLTree(NodeAVL *root);
void buildInput (int size, int min, int max, char file[]);

#endif
