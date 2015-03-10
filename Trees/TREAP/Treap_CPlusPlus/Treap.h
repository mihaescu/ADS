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
* Treap Class Declaration
*/
struct CTree
{
	void initialize();
	void sigrotl(ctree &);
	void sigrotr(ctree &);
	void insert(ctree &, int);
	void remove(ctree &, int);
	void display(ctree, int);
	void inorder(ctree);    
	bool find(ctree, int);	
	CTree()
	{}
};
