#ifndef OPTIMAL_TREE_H_INCLUDED
#define OPTIMAL_TREE_H_INCLUDED

// Dynamic Programming code for Optimal Binary Search Tree Problem 
#include <stdio.h> 
#include <limits.h>
#include <iostream>
#include <set>
#include <vector>
#include "prototypes.h"
using namespace std;

int sum(int freq[], int i, int j);
int optimalSearchTree(int **root, int **cost, int keys[], int freq[], int n);
Node* tree_reconstruction(Node* root_tree, set<int> &s, int **root, int n, int keys[], int freq[]);
#endif //OPTIMAL_TREE_H_INCLUDED
