#ifndef __BST_H__
#define __BST_H__


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct node{
	int key;
	node *left, *right;
}TreeNode;

TreeNode *mkTreeNode(int key, TreeNode *left, TreeNode *right);
TreeNode *mkEmptyTree();
bool treeEmpty(TreeNode *root);
void treeInsert(TreeNode **root, int key);
void inorder(TreeNode *root);
bool treeSearch(TreeNode *root, int key);
void treeRemove(TreeNode **root, int key);
void displayTree(TreeNode *root, int i);

#endif
