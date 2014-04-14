#include<iostream>
#include"23tree.h"

char const menu_options[10][100] = { "Load 2-3 Tree", "Print 2-3 Tree", "Search key", "Insert key.", "Delete key. " };


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
	int o;

	tree23* ROOT = NULL;

	
	time_tests(1000, 20000, 10);

	scanf("%d", &o);
	return 0;

}