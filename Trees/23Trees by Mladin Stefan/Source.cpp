#include<iostream>
#include"23tree.h"

char const menu_options[10][100] = { "Load 2-3 Tree", "Print 2-3 Tree", "Search key", "Insert key."};


int menu_query(int num_queries)
{
	printf("\n_________________________________________________");
	for (int i = 1; i <= num_queries; i++)
	{
		printf("\n%d.%s", i, menu_options[i - 1]);
	}
	printf("\n_________________________________________________\n");

	int o = 0;
	scanf("%d", &o);

	return o;
}


int main()
{
	tree23* ROOT = NULL;


	int o, K;
	FILE* input;

	while (1)
	{

		printf("\n____________________________________________\n0 to EXIT\n____________________________________________");
		o = menu_query(5);

		switch (o)
		{
		default: 
			break;
		case 0:
			return 0;
			break;
		case 1:
		{
				  input = fopen("tree.in", "r");
				  if (input == NULL)
					  printf("\nNO INPUT");
				  else
				  {
					  int buff;

					  while (!feof(input))
					  {
						  fscanf(input, "%d", &buff);
						  ROOT = INSERT(ROOT, buff);
					  }
				  }
				  fclose(input);
				  getchar();
				  getchar();

				  break;
		}
		case 2:
		{
				  PRINTTREE(ROOT);
				  getchar();
				  getchar();
				  break;
		}
		case 3:
		{
				  printf("\nEnter a key to search for.");
				  scanf("%d", &K);

				  if (SEARCH(ROOT, K) != NULL)
				  {
					  printf("\nKey %d has been found.", K);
				  }
				  else
				  {
					  printf("\nKey %d has NOT been found.", K);
				  }
				  getchar();
				  getchar();
				  break;
		}
		case 4:
			printf("\nEnter a key to INSERT.");
			scanf("%d", &K);

			ROOT = INSERT(ROOT, K);
			getchar();
			getchar();
			break;
		case 5:
			printf("\nEnter a key to DELETE.");
			scanf("%d", &K);

			ROOT = DEL(ROOT, K);
			getchar();
			getchar();
			break;
		}
	}

	return 0;

}