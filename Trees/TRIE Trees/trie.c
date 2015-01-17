#include "trie.h"


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Trie *new_trie(void) {
	Trie *result;
	result = (Trie*)malloc(sizeof (Trie));
	result->root = new_node();
	if (result != NULL) {
		result->leafcount = 0;
	}
	return result;
}

Node *new_node(void)
{
	int i;
	Node *result=(Node*)malloc(sizeof(Node));
	if (result) {
		result->is_leaf = 0;
	}
	for (i = 0; i < MAX; i++) {
		result->child[i].node = NULL;
	}
	return result;
}

int is_empty(Trie *tree)
{
	return tree->leafcount == 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int compare(Leaf leaf, Leaf result)
{
	int res;
	int n = strcmp(leaf, result);
	if (n == 0) {
		return 0;
	}
	else {
		for (res = 0; *leaf == *result; leaf++, result++, res++) {
			if (*leaf == '\0')
				return res;
		}
	}
	return res;
}

int decide(Leaf a, unsigned int pos)
{
	if (a[pos] == '\0') {
		return 0;
	}
	else {
		return a[pos] - 96;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Leaf search(Trie *tree, Leaf leaf)
{
	int dir, i = 0;
	Leaf result = NO_LEAF;
	Node *traveler = NULL;

	traveler = tree->root;
	/*
	*Walk tree
	*/
	while (1) {
		dir = decide(leaf, i);
		if (!IS_LEAF(traveler, dir) && traveler->child[dir].node == NULL) {           //if dir branch node points to NULL
			return NO_LEAF;
		}
		if (IS_LEAF(traveler, dir)) {
			result = traveler->child[dir].leaf;
			if (compare(leaf, result) == 0) {
				return result;
			}
			else {
				return NO_LEAF;
			}
		}
		else {
			traveler = traveler->child[dir].node;                                     //move down in trie
		}
		i++;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void create_subtree(Node *node, Leaf leaf, int i, int *error);

Leaf insert(Trie *tree, Leaf leaf, int should_replace, int *error)
{
	int i = 0, dir;
	Node *traveler = NULL;
	Leaf result = NO_LEAF;

	traveler = tree->root;
	/*
	*Walk tree
	*/
	while (1) {
		dir = decide(leaf, i);
		if (!IS_LEAF(traveler, dir) && traveler->child[dir].node == NULL) {     //if dir branch node points to NULL  
			traveler->child[dir].leaf = leaf;                                   //simply insert the word
			SET_LEAF(traveler, dir);
			tree->leafcount++;                                                  //update leaf count
			return NO_LEAF;
		}
		else if (IS_LEAF(traveler, dir)) {
			if (compare(leaf, traveler->child[dir].leaf) == 0) {
				if (should_replace) {									        //treat collision(only case where the insertion algorithm returns something other than NO_LEAF)
					result = traveler->child[dir].leaf;
					traveler->child[dir].leaf = leaf;
					return result;
				}
				else {
					return leaf;
				}
			}
			create_subtree(traveler, leaf, i, error);
			if (*error != -1) {
				tree->leafcount++;                                               //update leaf count
			}
			return NO_LEAF;
		}
		else {
			traveler = traveler->child[dir].node;                                //move down in trie
		}
		i++;
	}
}

/*
*Build a new subtree while the word to be inserted and the item that was in the leaf node have
the same letters or the end of one of them is reached.
*/

void create_subtree(Node *node, Leaf leaf, int i, int *error) {
	int dir;
	Node *aux = NULL, *helper = node;
	Leaf old = NO_LEAF;

	dir = decide(leaf, i);
	old = node->child[dir].leaf;
	while (leaf[i] == old[i] && leaf[i] && old[i]) {
		aux = new_node();                                                           //allocate new internal node and insert new character in it
		if (aux == NULL) {                                                          //if allocation fails
			*error = -1;
			return;
		}
		SET_NODE(helper, dir);
		helper->child[dir].node = aux;
		helper = helper->child[dir].node;
		dir = decide(leaf, ++i);
	}
	/*
	*Store in leaves the item that was to be inserted and the item that was originally in the leaf node.
	*/
	dir = decide(leaf, i);
	helper->child[dir].leaf = leaf;
	SET_LEAF(helper, dir);
	dir = decide(old, i);
	helper->child[dir].leaf = old;
	SET_LEAF(helper, dir);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
*calculates the number of leaves and number of nodes
*/
void nr_children(Node *node, int* n, int* l)
{
	int i;
	*n = *l = 0;
	for (i = 0; i < MAX; i++) {
		if (IS_NODE(node, i)) {
			(*n)++;
		}
		else if (IS_LEAF(node, i)) {
			(*l)++;
		}
	}
}

void aux_delete(Node *node, Leaf leaf, int idx) {
	int dir;
	Node *aux;
	dir = decide(leaf, idx);
	if (IS_NODE(node, dir)) {
		aux_delete(node->child[dir].node, leaf, idx + 1);
		aux = node->child[dir].node;
		node->child[dir].node = NULL;
		free(aux);
	}
}

Leaf delete(Trie *tree, Leaf leaf)
{
	int i = 0, j, dir, idx = 0, n = 0, l = 0;
	Node *traveler = NULL, *parent = NULL, *aux = NULL;
	Leaf result = NO_LEAF, l_aux = NO_LEAF;

	if (tree->leafcount == 0) {
		return NO_LEAF;
	}

	traveler = parent = tree->root;
	/*
	*Walk tree
	*/
	while (1) {
		dir = decide(leaf, i);                                                 //move down in trie
		if (IS_NODE(traveler, dir)) {
			traveler = traveler->child[dir].node;
			nr_children(traveler, &n, &l);
			if (n > 1 || l > 2 || (n > 0 && l > 0)) {                          //if actual node has at least one node and one leaf or two nodes or three leaves
				idx = i;
				parent = traveler;                                         //actual node becomes parent
			}
		}
		else if (IS_LEAF(traveler, dir)) {                                     //if we find a leaf
			if (compare(leaf, traveler->child[dir].leaf) == 0) {               //and if 
				result = traveler->child[dir].leaf;
				if (traveler == parent) {
					traveler->child[dir].leaf = NO_LEAF;
					SET_NODE(traveler, dir);
					tree->leafcount--;
					return result;
				}
				else {
					for (j = 0; j < MAX; j++) {
						if (IS_LEAF(traveler, j) && traveler->child[j].leaf != result) {
							l_aux = traveler->child[j].leaf;
							break;
						}
					}
					aux_delete(parent, result, idx);
					dir = decide(l_aux, idx);
					parent->child[dir].leaf = l_aux;
					SET_LEAF(parent, dir);
					tree->leafcount--;
					return result;
				}
			}
			else {
				return NO_LEAF;
			}
		}
		else {
			break;
		}
		i++;
	}
	return NO_LEAF;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void displayN(Node *node);

void display(Trie *tree)
{
	Node *node = NULL;
	if (!is_empty(tree)) {
		node = tree->root;
		displayN(node);
	}
	else {
		printf("The Trie is empty!\n");
	}

}

void displayN(Node *node) {
	int dir;

	for (dir = 0; dir < MAX; dir++) {
		if (IS_LEAF(node, dir)) {
			printf("%s\n", node->child[dir].leaf);
		}
		else if (IS_NODE(node, dir))
		{
			displayN(node->child[dir].node);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int is_lowercase(char c);

void file(Trie *tree, char *file, int *error)
{
	Leaf leaf;
	int i = 0;
	char c;
	FILE *f = fopen(file, "r");
	if (!f) {
		printf("Error opening the file %s!\n", file);
		return;
	}
	while (!feof(f)) {
		leaf = (Leaf)malloc(W_MIN*sizeof(Leaf));
		while (!feof(f) && is_lowercase(c = fgetc(f)) && i<20) {
			leaf[i++] = c;
		}
		leaf[i] = '\0';
		insert(tree, leaf, 0, error);
		i = 0;
	}
}

int is_lowercase(char c)
{
	return (c > 96 && c < 123);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////