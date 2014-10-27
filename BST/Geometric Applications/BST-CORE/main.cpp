#include<stdio.h>
#include<stdlib.h>
#include"BST.h"


int main(){

	char option;
	int key;
	TreeNode *tree = mkEmptyTree();

	FILE *fp = fopen("input.txt", "r");

	if (!fp)
	{
		perror("Unable to open file");
		exit(0);
	}

	while (!feof(fp))
	{
		fscanf(fp, "%c", &option);

		if (option == 'I')
		{
			fscanf(fp, "%d", &key);
			treeInsert(&tree, key);
		}
		else if (option == 'D')
		{
			fscanf(fp, "%d", &key);
			treeRemove(&tree, key);
		}

	}

	fclose(fp);

	displayTree(tree, 1);

	system("PAUSE");
	return 0;
}
