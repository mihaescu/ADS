#include "optimal_tree.h"
#include "prototypes.h"
#include <set>

int main(){
	int keys[] = { 10, 12, 20, 30, 40, 7 };
	int freq[] = { 34, 8, 50, 12, 31, 14 };
	//This is a set that store the elements of the freq array, because the set will be changed
	set<int> s;
	
	int iterator_1;
	int iterator_2;
	int iterator_3;

	// Create an auxiliary 2D matrix to store the results of subproblems 
	int **cost;
	int **root;

	//This is the size of the matrix called cost:
	int n = sizeof(keys) / sizeof(keys[0]);
	for (iterator_1 = 0; iterator_1 < n; iterator_1++) {
		s.insert(freq[iterator_1]);
	}
	
	//Memory allocation:
	cost = new int*[n+1];
	for (iterator_1 = 0; iterator_1 <= n; iterator_1++) {
		cost[iterator_1] = new int[n+1];
	}
	root = new int*[n+1];
	for (iterator_1 = 0; iterator_1 <= n; iterator_1++) {
		root[iterator_1] = new int[n+1];
	}
	
	for (iterator_1 = 0; iterator_1 < n; iterator_1++) {
		for (int iterator_2 = iterator_1; iterator_2 < n; iterator_2++) {
			root[iterator_1][iterator_2] = 0;
		}
	}

	//The actual call from the OBST:
	printf("Cost of Optimal BST is %d ", optimalSearchTree(root, cost, keys, freq, n));
	cout << endl;

	//Print the root matrix:
	cout << "The root matrix is:" << endl;
	for (iterator_1 = 0; iterator_1 < n; iterator_1++) {
		for (iterator_2 = iterator_1; iterator_2 > 0; iterator_2--) {
			cout << "  ";
		}
		for ( iterator_3 = iterator_1; iterator_3 < n; iterator_3++) {
			cout << root[iterator_1][iterator_3] << " ";
		}
		cout << endl;
	}

	//The reconstruction of the OBST:
	cout << "The root of the Optimal Binary Search Tree is: " << root[0][n-1] << endl;
	Node *root_tree = NULL;
	root_tree = tree_reconstruction(root_tree, s, root, n, keys, freq);
	cout << "The OBST is:" << endl;
	Display(root_tree, 4);

	//delete the nodes without the root of the OBST:
	for (iterator_1 = 0; iterator_1 < n; iterator_1++) {
		if (iterator_1 != root[0][n - 1]) {
			Delete(root_tree, keys[iterator_1]);
		}
	}
	Delete(root_tree, keys[root[0][n - 1]]);//delete the root of the OBST
	 
	//Free the allocated memory:
	for (iterator_1 = 0; iterator_1 <= n; iterator_1++) {
		delete[] cost[iterator_1];
	}
	delete[] cost;
	for (iterator_1 = 0; iterator_1 <= n; iterator_1++) {
		delete[] root[iterator_1];
	}
	delete[] root;

	return 0;
}
