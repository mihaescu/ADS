#pragma once

struct Treap {
	int key, priority;
	Treap *left, *right;
	Treap() {}
	Treap(int key, int priority, Treap* left, Treap* right) {
		this->key = key;
		this->priority = priority;
		this->left = left, this->right = right;
	}
}; // nil indica un nod 'gol'

void init(Treap* &R);
int search(Treap* n, int key);
void rotleft(Treap* &n);
void rotright(Treap* &n);
void balance(Treap* &n);
void insert(Treap* &n, int key, int priority);
void erase(Treap* &n, int key);
void split(Treap* &R, Treap* &Ts, Treap* &Tg, int key);
void join(Treap* &R, Treap* Ts, Treap* Tg, int key);
void displayTreap(Treap* &R, int i);
