#include<stdio.h>
#include<stdlib.h>

#define inf INT_MAX

/*
 * 2-3 tree "hard-coded" structure.
 */
struct tree23
{
	/*
	 * Integer keys.
	 */
	int K1, K2;
	/*
  	 * Left, middle and right subtree addresses, respectively.
	 */
	tree23 *tl, *tm, *tr;
};

void PRINTTREE(tree23 *ROOT);
void LOADTREE(tree23 *ROOT, FILE* input);

tree23* SEARCH(tree23 *ROOT, int K);

tree23* INSERT(tree23 *ROOT, int key);
tree23* DEL(tree23 *ROOT, int key);