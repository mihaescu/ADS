#include "prototypes.h"

int internalPathLength(Node *t, int &count1){
        if(t == NULL) {
            count1 = 0;
            return 0;
        }
        else if(t->left == NULL && t->right == NULL){
            count1 = 1;
            return 0;
        }
        else {
            count1 = 1;
            int leftCount;
            int rightCount;
            int sum = internalPathLength(t->left, leftCount) + internalPathLength(t->right, rightCount);

            count1 += leftCount + rightCount;

            return sum + count1 - 1;
        }
    }

void Display(Node* root, int nivel)
{
	int i;
	if (root != 0)
	{
		Display(root->right, nivel + 1);
		for (i = 0; i <= nivel; i++)
			printf("  ");
		printf("%d\n", root->data);
		Display(root->left, nivel + 1);
	}
}


Node *Add_Node(Node *root, int data)
{//the function takes as a parameter the root and the number that needs to be added
 //we first check if there is a root, so the tree is created
 //we allocate memory for the new node and set the values for data,left_child,right_child.

	if (root == NULL)
	{
		root = (Node *)malloc(sizeof(Node));
		root->data = data;
		root->left = root->right = NULL;
	}

	else if (data <= root->data)
	{
		root->left = Add_Node(root->left, data);//if the number is smaller it will be placed on the left side of the parent
	}
	else {
		root->right = Add_Node(root->right, data);//if the number is bigger it will be placed on the right side of the parent
	}
	return root;
}

Node* FindMin(Node* root)
{
	while (root->left != NULL) root = root->left;
	return root;
}

Node* Delete(Node *root, int data) {
	if (root == NULL) {

            return root;}
	else if (data < root->data)
		root->left = Delete(root->left, data);

	else if (data > root->data)
		root->right = Delete(root->right, data);

	else {
		// Case 1:
		if (root->left == NULL && root->right == NULL) {
			free(root);
			root = NULL;
		}
		//Case 2:
		else if (root->left == NULL) {
			Node *temp = root;
			root = root->right;
			free(temp);
		}
		else if (root->right == NULL) {
			Node *temp = root;
			root = root->left;
			free(temp);
		}
		// Case 3:
		else {
			Node *temp = FindMin(root->right);//mergem in dreapta si cautam  nr minim
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}



bool Search(Node *root, int data)
{
    if(root == NULL){
        return false;
    }else{
        if(data == root->data){
            return true;
        }else{
            if(data < root->data){

                 return Search(root->left,data);
            }else{

                return Search(root->right,data);
            }
        }
    }
    return false;
}
