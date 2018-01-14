#include "functions.h"

//function to add nodes in a BST
Node *Add_Node(Node *node,int data)
{//first we check if the tree has been created(if it's not empty)

    if(node==NULL)
    {
        node=(Node *)malloc(sizeof(Node));
        node->data=data;
        node->left=NULL;
        node->right=NULL;
    }
    else if(data <= node->data)
    {
        node->left=Add_Node(node->left,data);//the node is the left child if its value is smaller than his parent's value
    }
    else {

        node->right=Add_Node(node->right,data);//the node is the right child if its value is greater than his parent's value
        }
    return node;
}

//Function to randomly generate input in files
void buildInput(ofstream &outputFile, int minValue, int MaxValue, int nrOfValues){
    int random_node;
    time_t t;
    srand((unsigned) time(&t));
    for(int iterator1 = 0; iterator1 < nrOfValues; iterator1++){
        random_node = minValue + rand() % (MaxValue - minValue+1);
        outputFile << random_node << endl;
    }
}

//function that counts the number of nodes in a BST
int countNodes (Node *node)
{
    int counter=1;

    if (node ==NULL) //if there are no nodes in a tree/subtree return 0
        return 0;

    else
    {
        counter =counter + countNodes(node->left);
        counter =counter + countNodes(node->right);
        return counter;
    }
}


//function to compute the internal path length
int computeIPL(Node *node, int value){

    if(node == NULL)
        {
            return 0;
        }
    return (value+computeIPL(node->right,value+1)+computeIPL(node->left,value+1));
}

//a second function to compute the internal path length
int internalPathLength(Node *node, int &count1){
        if(node == NULL) {
            count1 = 0;
            return 0;
        }
        else if(node->left == NULL && node->right == NULL){
            count1 = 1;
            return 0;
        }
        else {
            count1 = 1;
            int leftCount;
            int rightCount;
            int sum = internalPathLength(node->left, leftCount) + internalPathLength(node->right, rightCount);

            count1 += leftCount + rightCount;

            return sum + count1 - 1;
        }
}

//function to compute the average path length as the internal path length divided by tree size, plus 1

float computeAveragePathLength(Node *node){
    int ipl = computeIPL(node,0);
    int nr_nodes = countNodes(node);
    float apl = (float)ipl/nr_nodes+1;
    return apl;
}
