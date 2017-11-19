#include "prototypes.h"

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


int maxDepth( Node* node)
{ int lDepth,rDepth ;
   if (node==NULL)
       return 0;
   else
   {
       // compute the depth of each subtree
        lDepth = maxDepth(node->left);
        rDepth = maxDepth(node->right);

       // use the larger one
       if (lDepth > rDepth)
           return(lDepth+1);
       else return(rDepth+1);
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



