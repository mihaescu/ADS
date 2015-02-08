#include "Procedures.h"

int main()
{
	FILE* fin = NULL;
	char c, fileName[20];
	int i;

	do
	{
		printf ("\n    <<<<<<<<<<<<<<<<<<<<<<   MENU   >>>>>>>>>>>>>>>>>>>>>>\n\n");
		printf ("\n    1. Generate a new test file AND display it;");
		printf ("\n    2. Generate a new test file WITHOUT displaying it;\n");
		printf ("\n    3. Load an existing test file AND display it;");
		printf ("\n    4. Load an existing test file WITHOUT displaying it;\n");
		printf ("\n    5. Exit the program.\n");

		printf ("\n Choose an option ('c' to clear screen): ");
		scanf (" %c", &c);

		if (c == 'c')
		{
			for (i = 0; i < 100; i++)
			{
				printf ("\n");
			}
		}

		else if (c == '1')
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
		{
			exit(1);
		}

		else
		{
			printf ("\nThe key you pressed is not a valid option. Please press 1, 2, 3, 4 or 5.\n\n");
		}

		if (c == '1' || c == '2' || c == '3' || c == '4')
		{
			fin = fopen (fileName, "r");

			if (fin == NULL) 
			{
				perror ("\n\tError opening file\n");
			}
			else
			{
				int nodes;
				double beta;

				printf ("\nDefine the damping factor (best between 0.8 and 0.9): ");
				scanf ("%lf", &beta);

				double **M = loadGraph (fin, nodes);
				M = createMatrix_M (M, nodes, beta);

				double **B = createMatrix_B (nodes, beta);
				M = matrixSum (M, B, nodes);
				deallocMatrix <double> (B, nodes);

				//
				printf("\n Matrix A = M + B \n");
				displayMatrix (M, nodes, nodes);
				//

				powerIteration (M, nodes, beta);

				fclose (fin);
			}
		}

	} while (true);

	return 0;
}
