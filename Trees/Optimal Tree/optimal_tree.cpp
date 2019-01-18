#include "optimal_tree.h"

// A Dynamic Programming based function that calculates minimum cost of a Binary Search Tree. 
int optimalSearchTree(int **root, int **cost, int keys[], int freq[], int n) {
	/* cost[i][j] = Optimal cost of binary search tree
	   that can be formed from keys[i] to keys[j].
	   cost[0][n-1] will store the resultant cost */

	 // For a single key, cost is equal to frequency of the key (The case when L = 1)
	for (int i = 0; i <= n; i++) {
		cost[i][i] = freq[i];
		root[i][i] = i;
	}

	// Now we need to consider chains of length 2, 3, ...
	// L is chain length. 
	for (int L = 2; L <= n; L++){
		// i is row number in cost[][] 
		for (int i = 0; i <= n - L + 1; i++){//it takes every chain of L nodes (in consecutive order) 
			// Get column number j from row number i and chain length L 
			int j = i + L - 1;
			cost[i][j] = INT_MAX;

			// Try making all keys in interval keys[i..j] as root 
			for (int r = i; r <= j; r++){
				// c = cost when keys[r] becomes root of this subtree 
				int c = ((r > i) ? cost[i][r - 1] : 0) +((r < j) ? cost[r + 1][j] : 0) + sum(freq, i, j);
				if (c < cost[i][j]) {
					cost[i][j] = c;
					root[i][j] = r;
				}
			}
		}
	}
	return cost[0][n - 1];
}

// A utility function to get sum of array elements freq[i] to freq[j] 
int sum(int freq[], int i, int j){
	int s = 0;
	for (int k = i; k <= j; k++)
		s += freq[k];
	return s;
}

Node* tree_reconstruction(Node* root_tree, set<int> &s, int **root, int n, int keys[], int freq[]) {
	int iterator_1;
	int iterator_2;
	
	//A vector used to show which key was inserted and which was not
	vector<bool> inserted_keys(n, false);
	
	//Insert the root of the OBST and mark it as inserted in the inserted_keys vector
	root_tree = Add_Node(root_tree, keys[root[0][n - 1]]);
	inserted_keys[root[0][n - 1]] = true;
	set<int>::iterator it = s.find(freq[root[0][n - 1]]);
	if (it != s.end()) {
		s.erase(it);
	}

	for (iterator_1 = 0; iterator_1 < n; iterator_1++) {
		for (iterator_2 = iterator_1 + 1; iterator_2 < n; iterator_2++) {
			//if the key was not inserted yet and it is a parent for another one:
			set<int>::iterator it = s.find(freq[root[iterator_1][iterator_2]]);
			if (inserted_keys[root[iterator_1][iterator_2]] == false && it != s.end()) {
				s.erase(it);
				Add_Node(root_tree, keys[root[iterator_1][iterator_2]]);
				inserted_keys[root[iterator_1][iterator_2]] = true;
			}
		}
	}

	//if a key wasn't inserted (if it is a leaf):
	for (iterator_1 = 0; iterator_1 < n && s.size() != 0; iterator_1++) {
		if (inserted_keys[iterator_1] == false) {
			set<int>::iterator it = s.find(freq[iterator_1]);
			if (it != s.end()) {
				s.erase(it);
				Add_Node(root_tree, keys[iterator_1]);
				inserted_keys[iterator_1] = true;
			}
		}
	}
	
	return root_tree;
}