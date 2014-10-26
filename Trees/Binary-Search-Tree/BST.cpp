#include"BST.h"


TreeNode *mkTreeNode(int key, TreeNode *left, TreeNode *right){
	TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
	node->key = key;
	node->left = left;
	node->right = right;
	return node;
}

TreeNode *mkEmptyTree(){
	return NULL;
}

bool treeEmpty(TreeNode *root){
	return root = NULL;
}

void treeInsert(TreeNode **root, int key){
	if (*root==NULL){
		*root = mkTreeNode(key, mkEmptyTree(), mkEmptyTree());
	}
	else 
		if ((*root)->key > key){
			treeInsert(&(*root)->left, key);
	}
	else
		if ((*root)->key < key){
			treeInsert(&(*root)->right, key);
	}
	else
		if ((*root)->key == key)
			printf("Key %d already inserted.\n",key);

}

void inorder(TreeNode *root){
	if (root == NULL)
		return;
	inorder(root->left);
	printf("%d\n", root->key);
	inorder(root->right);
}


bool treeSearch(TreeNode *root, int key){
	if (root == NULL) {
		return false;
	}
	if (root->key == key) {
		return true;
	}
	if (key < root->key) {
		return treeSearch(root->left, key);
	}
	return treeSearch(root->right, key);
}



void treeRemove(TreeNode **root, int key){
	TreeNode *r=(*root),*p=(*root),*q=NULL,*aux=NULL;
	int select,max=-10000,aux2=0;


	//cautam nodul care trebuie sters si parintele lui

	while (r!=NULL){
		if (r->key == key) {
			break;
		}
		if (key < r->key) {
			p = r;
			r = r->left;
			select = 0;
		}
		else{
			p = r;
			r = r->right;
			select = 1;
		}
	}
	

	//daca stergem o frunza
	if (r != NULL){
		if (r->left == NULL && r->right == NULL){
			if (select == 1)
				p->right = NULL;
			else
				p->left = NULL;
			free(r);
		}
		else    //daca stergem un nod cu un singur copil
		if (r->left == NULL || r->right == NULL){
			if (r->left == NULL)
				q = r->right;
			else
				q = r->left;

			if (r == (*root) && r->right == NULL){   //daca nodul cu un singur copil e radacina
				(*root) = (*root)->left;
				free(r);
			}
			else
			if (r == (*root) && r->left == NULL){
				(*root) = (*root)->right;
				free(r);
			}
			else{                          //daca nodul cu un singur copil nu e radacina
				if (select == 0){
					p->left = q;
					free(r);
				}
				else{
					p->right = q;
					free(r);
				}
			}
		}
		//daca nodul care trebuie sters are 2 copii
		else{
			aux = r->left;
			while (aux->right != NULL)
				aux = aux->right;
			aux2 = aux->key;
			treeRemove(&(*root), aux->key);
			r->key = aux2;
		}
	}
	else
		printf("Key %d does not exist!Cannot be removed!\n",key);


}


void displayTree(TreeNode *root, int i){
	if (root != NULL){
		displayTree(root->right, i + 1);
		for (int j = 1; j <= i; j++)
			printf("   ");
		printf("%d   \n", root->key);
		displayTree(root->left, i + 1);
	}
}


