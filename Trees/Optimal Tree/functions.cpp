#include "prototypes.h"

void Display(Node *root, int nivel) {
	int i;
	if (root != NULL) {
		Display(root->right, nivel + 1);
		for (i = 0; i <= nivel; i++)
			printf("       ");
		printf("%d\n", root->data);
		Display(root->left, nivel + 1);
	}
}

Node *Add_Node(Node *root, int data) {
	if (root == NULL) {
		root = (Node *)malloc(sizeof(Node));
		root->data = data;
		root->left = NULL;
		root->right = NULL;
	}
	else if (data < root->data) {
		root->left = Add_Node(root->left, data);
	}
	else if (data > root->data) {
		root->right = Add_Node(root->right, data);
	}
	return root;
}

Node* FindMin(Node* root) {
	while (root->left != NULL)
		root = root->left;
	return root;
}

Node* Delete(Node *root, int data) {
	if (root == NULL) return root;
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
		// Case 2:
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
			Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

int search_node(Node *root, int data) {
	int found = 0;
	int pozitie = 0;

	while (root != NULL && found != 1) {
		if (data < root->data) {
			root = root->left;
			pozitie++;
		}
		else
			if (data > root->data) {
				root = root->right;
				pozitie++;
			}
			else {
				found = 1;
				pozitie++;
			}
	}
	if (found == 0) {
		pozitie = -1;
	}
	return pozitie;
}