#include "functions.h"
#include <fstream>
#include <time.h>
using namespace std;

int count_nodes (Node *node)
{
    int counter=1;

    if (node ==NULL)
        return 0;

    else
    {
        counter =counter + count_nodes(node->left);
        counter =counter + count_nodes(node->right);
        return counter;
    }
}

Node *Add_Node(Node *root,int data)
{//first we check if the tree has been created(if it's not empty)

    if(root==NULL)
    {   root=(Node *)malloc(sizeof(Node));
        root->data=data;
        root->left=root->right=NULL;
    }
    else if(data <= root->data)
    {
        root->left=Add_Node(root->left,data);//the node is the left child if its value is smaller than his parent's value
    }
    else {
        root->right=Add_Node(root->right,data);//the node is the right child if its value is greater than his parent's value
        }
    return root;
}



void buildInput(ofstream &outputFile, int minValue, int MaxValue, int nrOfValues){
    int random_node;
    time_t t;
    srand((unsigned) time(&t));
    for(int iterator1 = 0; iterator1 < nrOfValues; iterator1++){
        random_node = minValue + rand() % (MaxValue - minValue+1);
        outputFile << random_node << endl;
    }
}

int computeIPL(Node *root, int value){

if(root == NULL)
    {
        return 0;
    }
return (value+computeIPL(root->right,value+1)+computeIPL(root->left,value+1));
}

float computeAveragePathLength(Node *root){
    int ipl = computeIPL(root,0);
    int nr_nodes = count_nodes(root);
    float apl = (float)ipl/nr_nodes+1;
    return apl;
}
