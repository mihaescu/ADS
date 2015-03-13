#include "Treap.h"

ctree nullnode, root;

/*
* Main Contains Menu
*/
int main()
{
	srand ((unsigned int)time (NULL));

	int num;
	char choice;

	bool flag = false;

	initialize();

	while (1)
	{
		printf("\n---------------------");
		printf("\n Operations on Treap");
		printf("\n---------------------\n");
		printf("\n1. Insert Element;");
		printf("\n2. Delete Element;");
		printf("\n3. Inorder Traversal;");
		printf("\n4. Display in Order;");
		printf("\n5. Quit.\n");

		printf("\nEnter your choice: ");
		scanf(" %c", &choice);

		switch (choice)
		{
		case '1':
			printf("Enter the number to be inserted: ");
			scanf("%d", &num);
			insert(root, num);
			break;

		case '2':
			if (root == nullnode)
			{
				printf("Tree is empty, nothing to delete");
				continue;
			}
			printf("Enter the number to be deleted: ");
			scanf("%d", &num);

			if (find(root, num))
				flag = true;
			else
				printf("Element not found.\n");

			remove(root, num);

			if (!find(root, num) && flag)
				printf("Element Deleted.\n");
			break;

		case '3':
			if (root == nullnode)
			{
				printf("Tree is empty, insert element first.\n");
				continue;
			}
			printf("Inorder Traversal:\n");
			inorder(root);
			printf("\n");
			break;  

		case '4':
			if (root == nullnode)
			{
				printf("Tree is empty.\n");
				continue;
			}
			printf("Display Treap:\n");
			display(root, 1);
			printf("\n");
			break;
		case '5':
			exit(1);
			break;

		default:
			printf("Wrong choice!\n");
		}
	}
}
