#include "Treap.h"
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<limits.h>
#define INF INT_MAX
Treap  *R, *nil;
void init(Treap* & R)
{
	srand(unsigned(time(0)));
	R = nil = new Treap(0, 0, NULL, NULL);
}

int search(Treap* n, int key)
{
	if (n == nil) return 0;
	if (key == n->key) return 1;
	if (key < n->key)
		return search(n->left, key);
	else
		return search(n->right, key);
}


void rotright(Treap* &n) {
	Treap *t = n->left;
	n->left = t->right;
	t->right = n;
	n = t;
}

void rotleft(Treap* &n) {
	Treap *t = n->right;
	n->right = t->left;
	t->left = n;
	n = t;
}

void balance(Treap* &n) {
	if (n->left->priority > n->priority)
		rotright(n);
	else if (n->right->priority > n->priority)
		rotleft(n);
}

void insert(Treap* &n, int key, int priority) {
	if (n == nil) {
		n = new Treap(key, priority, nil, nil);
		return;
	}
	if (key < n->key)
		insert(n->left, key, priority);
	else if (key > n->key)
		insert(n->right, key, priority);

	balance(n);
}

void erase(Treap* &n, int key) {
	if (n == nil) return;

	if (key < n->key)
		erase(n->left, key);
	else if (key > n->key)
		erase(n->right, key);
	else {
		if (n->left == nil && n->right == nil)
			delete n, n = nil;
		else {
			(n->left->priority > n->right->priority) ? rotleft(n) : rotright(n);
			erase(n, key);
		}
	}
}

void split(Treap* &R, Treap* &Ts, Treap* &Tg, int key) {
	insert(R, key, INF);
	Ts = R->left, Tg = R->right;
	delete R, R = nil;
}

void join(Treap* &R, Treap* Ts, Treap* Tg, int key) {
	R = new Treap(key, 0, Ts, Tg);
	erase(R, R->key);
}

void displayTreap(Treap* &R, int i)
{
	if (R != NULL)
	{
		displayTreap(R->right, i + 1);
		for (int j = 1; j <= i; j++)
		{
			printf("	");
		}
		printf("%d %d	\n", R->key, R->priority);
		displayTreap(R->left, i + 1);
	}
}
