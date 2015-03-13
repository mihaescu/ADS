#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef struct ctreenode *ctree;
/*
* Tree Node Declaration
*/
struct ctreenode
{
	int key, fix;
	ctree left, right;
};

extern ctree nullnode, root;

/*
* Treap Functions' Declaration
*/
void initialize();
void rotLeft(ctree &);
void rotRight(ctree &);
void insert(ctree &, int);
void remove(ctree &, int);
void display(ctree, int);
void inorder(ctree);    
bool find(ctree, int);	
