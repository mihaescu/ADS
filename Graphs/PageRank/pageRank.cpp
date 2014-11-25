#include "Procedures.h"

int main()
{
	FILE* fin = NULL;
	char c, fileName[20];

	do
	{
		printf("If you want to generate a new test file AND display it, press 1;\n");
		printf("If you want to generate a new test file WITHOUT displaying it, press 2;\n\n");
		printf("If you want to load an existing test file AND display it, press 3;\n");
		printf("If you want to load an existing test file WITHOUT displaying it, press 4;\n\n");
		printf("If you want to exit the program, press 5.\n");

		printf ("\nChoose an option: ");
		scanf (" %c", &c);

		if (c == '1')
		{
			printf ("\nGenerate a new test file and display it. Input its name:\n");
			scanf ("%s", fileName);
			graphGenerator (fileName);
			displayGraph (fin, fileName);
		}

		else if (c == '2')
		{
			printf ("\nGenerate a new test file. Input its name:\n");
			scanf ("%s", fileName);
			graphGenerator (fileName);
		}

		else if (c == '3')
		{
			printf ("\nLoad an existing test file and display it. Input its name:\n");
			scanf ("%s", fileName);
			displayGraph (fin, fileName);
		}

		else if (c == '4')
		{
			printf ("\nLoad an existing test file. Input its name:\n");
			scanf ("%s", fileName);
		}

		else if (c == '5')
			exit(1);
		else
		{
			printf("\nThe key you pressed is not a valid option. Please press 1, 2, 3, 4 or 5.\n");
		}
	} while ((c != '1') && (c != '2') && (c != '3') && (c != '4'));


	fin = fopen (fileName, "r");

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

		/*printf("\n Matrix A = M + B \n");
		displayMatrix (M, nodes, nodes);*/

		powerIteration (M, nodes);
	}

	return 0;
}
