//#include<iostream>
//using namespace std;
#include "treaps.h"
#include<conio.h>

typedef int dir;
NodeTreap root;
NodeTreap tLess,tLarge;
NodeTreap extraNode;




int main()
{
	//srand(time(NULL));

	int opt;
	int el,n;

	float p;

	root = NULL;
	tLess = NULL;
	tLarge = NULL;

	do
	{
		printf("\nMenu");
		printf("\n1. Create/Insert");
		printf("\n2. Search");
		printf("\n3. Delete");
		printf("\n4. Print tree");
		printf("\n5. Split");
		printf("\n6. Merge");
		printf("\n0. Exit\n");
		scanf("%d",&opt);
		printf("\n\n");

		switch (opt)
		{
		case 1:
			printf("\nEnter key and priority : ");
			scanf("%d%f",&el,&p);
			insert(&root,el,p);
			displayTreap(root,0);			
			break;
		case 2:
			printf("\nEnter searched key : ");
			scanf("%d",&el);

			if (member(&root,el))			
				printf("The key is in the tree\n");			
			else			
				printf("The key is not in the tree\n");			
			break;		
		case 3:
			printf("\nEnter the key to be deleted : ");
			scanf("%d",&el);
			deleteTreap(&root,el);
			displayTreap(root,0);
			break;
		case 4:
			if (root)
			{
				printf("\nThe tree is : \n");
				displayTreap(root,0);
				printf("\n The root is: %d\n",root->element);
			} 
			else
			{
				printf("\ntLess is :\n");

				displayTreap(tLess,0);

				printf("\ntLarge is :\n");

				displayTreap(tLarge,0);
			}			
			break;
		case 5: printf("\n Enter the key:");
			     scanf("%d",&el);
				 splitTreap(&root,el);
				 displayTreap(root,0);
		case 6:
			printf("Number of elements :");
			     scanf("%d",&n);
				 while(n!=0)
				 {
			     printf("\n Enter key and priority:");
			     scanf("%d %f",&el,&p);
			     insert(&tLess,el,p);
			     displayTreap(tLess,0);
				 n--;
				 }
				 printf("Number of elements :");
			     scanf("%d",&n);
				 while(n!=0)
				 {
				 printf("\n Enter key and priority:");
			     scanf("%d %f",&el,&p);
				 insert(&tLarge,el,p);
				  displayTreap(tLarge,0);
				 n--;
				 }
	
				 printf("Element: ");
				 scanf("%d",&el);
				 insert(&extraNode,el,p);
			mergeTreaps(&root,&tLess,&tLarge);			
			tLess = NULL;
			tLarge = NULL;
			break;
		default:
			break;
		}

		if (opt != 0)
			getch();
	}while(opt != 0);

	return 0;
}