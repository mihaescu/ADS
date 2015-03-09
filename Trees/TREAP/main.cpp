#include"Treap.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
	Treap* treap;
	init(treap);


	char opt;
	do
	{
		system("CLS");
		printf("1.Insert\n2.Delete\n3.Display\n0.Exit\n");
		opt = _getch();
		int key = 0, priority = 0;
		switch (opt)
		{
		case '1':
			printf("Key:");
			scanf("%d", &key);
			printf("Priority:");
			scanf("%d", &priority);
			insert(treap, key, priority);
			break;
		case '2':
			printf("Key:");
			scanf("%d", &key);
			erase(treap, key);
			break;
		case '3':
			displayTreap(treap, 1);
			system("PAUSE");
			break;
		}
	} while (opt != '0');




	system("PAUSE");
	return 0;
}
