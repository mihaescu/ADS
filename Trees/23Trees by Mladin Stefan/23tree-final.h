#include<stdio.h>
#include<stdlib.h>

#define inf INT_MAX

struct tree23
{
	int K1, K2;
	tree23 *tl, *tm, *tr;
};
void READ(tree23 *&ROOT, FILE* input);
void PRINTTREE(tree23 *ROOT);

void time_tests(int N_1, int N_2, int N_step);

bool validate_tree23_nodetype(tree23* ROOT);

tree23* INSERT(tree23 *ROOT, int key);
tree23* DEL(tree23 *ROOT, int key);