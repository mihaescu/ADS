#include<stdio.h>
#include<conio.h>

#define m 4
using namespace std;

typedef struct NodeB{
        int nr;
        int keys[m+1];
       
        struct NodeB *pNodes[m+1]; 
        
        } ;



NodeB *insert(int key);// insert key read in the B tree and will return the corresponding root pointer
void splitPage(NodeB *node,int keyx,int &upKey,int &ok);// search keyX in the current page node and inserted in place of corresponding
void placeInPage(NodeB *node,int position,int keyx,int &upKey,int &ok);//actually insert the keyX in the page node in the position position of of keys vector
void insertInNonFullLeaf(NodeB *node,int position,int keyx,int &upKey,int &ok);//enter in the current node
void copyPage(NodeB *destination,NodeB *source,int destIndex,int sourceIndex,int n);//copy the information from the page node to the page dest starting with the index id
void search(NodeB *node,int numtosearch);//search a key in the tree
void displayTree(NodeB *node,int level);//display the tree
NodeB *deleteKey(NodeB **node,int key);// delete a key 
int findMinimum(NodeB *node);


