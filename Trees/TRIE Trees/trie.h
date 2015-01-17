#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *the American alphabet(26 letters) plus blank.
 */
#define MAX 27       
/*
 *the minimum lenght of a word
 */
#define W_MIN 20
/*
 *empty word
 */
#define NO_LEAF NULL

/*
 *1 leaf 0 node
 */
/*
 *set as leaf (word) the (dir)th child of node 
 */
#define SET_LEAF(node, dir) ((node)->is_leaf |=  (1 << (dir)))
/*
 *set as node the (dir)th child of node 
 */
#define SET_NODE(node, dir) ((node)->is_leaf &= ~(1 << (dir)))
/*
 *check if the (dir)th child of node is a leaf
 */
#define  IS_LEAF(node, dir) ((node)->is_leaf &   (1 << (dir)))
/*
 *check if the (dir)th child of node is a node
 */
#define  IS_NODE(x, dir) (!((x)->is_leaf & (1 << (dir))) && ((x)->child[dir].node != NULL))


typedef char* Leaf;    

typedef struct _root_struct {
	unsigned int leafcount;                   //number of words in the trie
	struct _internal_node * root;			  // reference to the root node of the trie
}Trie;

typedef struct _internal_node {
	unsigned int is_leaf;                     //flags to tell whether each child is a leaf or an internal node
	union {
		struct _internal_node * node;         //the node stored in one child(if the child is a node)
		Leaf                    leaf;         // the string stored in one child(if the child is a leaf)
	} child[MAX];							  // a list of pointers corresponding to the used alphabet		 
}Node;

/*
 *check if the trie is empty
 */
int is_empty(Trie *tree);
/*
 *create a new trie
 */
Trie *new_trie(void);
/*
 *create a new node
 */
Node *new_node(void);
/*
*compare two leaves and return 0 if the leaves are identical or position of the first character that does not match
*/
int compare(Leaf a, Leaf b);
/*
*decide which branch shoult follow
*/
int decide(Leaf a, unsigned int pos);
/*
 *add a word in the trie
 */
Leaf insert(Trie *tree, Leaf leaf, int should_replace, int* error);
/*
 *searching for a given key in a trie
 */
Leaf search(Trie *tree, Leaf leaf);
/*
 *deleting a leaf from a previously initialised and populated tree
 */
Leaf delete(Trie *tree, Leaf leaf);
/*
 *display words stored in the trie
 */
void display(Trie *tree);
/*
 *load words from file
 */
void file(Trie *tree, char *file,int *error);

#endif