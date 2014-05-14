#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>

#include "AVL_test.h"
#include"AVL.h"

int main()
{
	int key;
	char option;

	NodeAVL *root = NULL;

	FILE *fp = fopen ( "input.txt", "r" );

	if (!fp)
	{
		perror ( "Unable to open file" );
		exit(0);
	}

	while(!feof(fp))
	{
		fscanf(fp, "%c", &option);

		if( option == 'I' )
		{
			fscanf(fp, "%d", &key); 
			root = insertAVLNode( root, key );
		}
		else if( option == 'D' )
		{
			fscanf(fp, "%d", &key); 
			root = deleteAVLNode( root, key );
		}

	}

	fclose(fp);

	displayAVLTree(root,10);

	system("PAUSE");
	return 0;	
}



