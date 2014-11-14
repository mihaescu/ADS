#include "Procedures.h"

int main()
{
	FILE* fin = NULL;
	char c, file[20];

	do
	{
		printf("If you want to generate a new test file, press 1;\n");
		printf("If you want to load an existing test file, press 2.\n");

		scanf (" %c", &c);

		if (c == '1')
		{
			printf ("\nGenerate a new test file. Input its name:\n");
			scanf ("%s", file);
			graphGenerator (file);
		}

		else if (c == '2')
		{
			printf ("\nLoad an existing test file. Input its name:\n");
			scanf ("%s", file);
		}
		else
		{
			printf("\nThe key you pressed is not a valid option. Please press 1 or 2.\n");
		}
	} while ((c != '1') && (c != '2'));

	fin = fopen (file, "r");
	
	if (fin == NULL) 
		perror ("Error opening file");
	else
	{
		int nodes;

		double **M = loadGraph (fin, nodes);
		M = createMatrix_M (M, nodes);

		double **B = createMatrix_B (nodes);
		M = matrixSum (M, B, nodes);
		deallocMatrix <double> (B, nodes);

		printf("\n Matrix A = M + B \n");
		displayMatrix (M, nodes, nodes);

		powerIteration (M, nodes);
	}

	return 0;
}
