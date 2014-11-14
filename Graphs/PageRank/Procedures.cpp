#include "Procedures.h"

void graphGenerator (char *fileName)
{
	FILE* fin = fopen (fileName, "w");
	srand ((unsigned int)time (NULL));

	int nodes = rand() % 10 + 1;
	int dsrdLink = nodes * nodes - 2 * nodes + 1;
	int links = rand() % dsrdLink + (2 * nodes);

	fprintf (fin, "%d %d\n", nodes, links);

	int** mat = new int*[links];

	for (int i = 0; i < links; i++)
	{
		mat[i] = new int[2];
		bool exists;

		do
		{
			mat[i][0] = rand() % nodes;
			mat[i][1] = rand() % nodes;

			exists = false;

			for (int j = 0; j < i; j++)
				if (mat[i][0] == mat[j][0] && mat[i][1] == mat[j][1])
					exists = true;
		} while (exists == true);

		fprintf (fin, "%d %d\n", mat[i][0], mat[i][1]);
	}

	fclose(fin);
	deallocMatrix <int> (mat, links);
}


double **loadGraph (FILE* fin, int &nodes)
{
	int i, j, x, y, links;

	fscanf (fin, "%d %d", &nodes, &links);

	double **M = new double*[nodes];
	for (i = 0; i < nodes; i++)
		M[i] = new double[nodes];
	
	for (i = 0; i < nodes; i++)
		for (j = 0; j < nodes; j++)
			M[i][j] = 0;
	
	for (i = 1; i <= links; i++)
	{
		fscanf(fin, "%d %d", &x, &y);
		M[x][y] = 1;
	}

	fclose(fin);
	return M;
}

template <class T>
void deallocMatrix (T **a, int m) 
{
	for (int i = 0; i < m; i++)
		delete[] a[i];

	delete[] a;
}

void displayMatrix (double **a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%.3f   ", a[i][j]);
		printf("\n");
	}
	printf("\n");
}

double **createMatrix_M (double **a, int n)
{
	int i, j;
	double aux;

	// create the transpose of matrix a
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (i < j)
			{
				aux = a[i][j];
				a[i][j] = a[j][i];
				a[j][i] = aux;
			}

	double *sum = new double[n];

	// insert the sum of every column in the vector "sum"
	for (i = 0; i < n; i++)
	{
		sum[i] = 0.0;
		for (j = 0; j < n; j++)
			sum[i] += a[j][i];
	}

	// divide every element of column i by sum[i]
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (a[j][i] && sum[i])
				a[j][i] /= sum[i];

	delete[] sum;

	printf("\n Matrix M:\n");
	displayMatrix (a, n, n);

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] *= beta;

	printf("\n Matrix M after random teleports (probability = %.2f):\n", beta);
	displayMatrix (a, n, n);

	return a;
}

double** createMatrix_B (int n)          
{
	int i, j;

	double **B = new double*[n];
	for (i = 0; i < n; i++)
		B[i] = new double[n];

	for (i = 0; i < n; i++)					// create a matrix having all the elements 1/n
		for (j = 0; j < n; j++)
			B[i][j] = 1.0 / n;

	printf("\n Matrix B:\n");
	displayMatrix (B, n, n);

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			B[i][j] *= 1.0 - beta;

	printf("\n Matrix B after random teleports (probability = %.2f):\n", 1.0 - beta);
	displayMatrix (B, n, n);

	return B;
}

double **matrixSum (double **a, double **b, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] += b[i][j];

	return a;
}

double **createVector_R (int n)              // create the column-vector (eigenvector) R
{
	int i;

	double **r = new double*[n];
	for (i = 0; i < n; i++)
		r[i] = new double[1];

	for (i = 0; i < n; i++)
		r[i][0] = 1.0 / n;

	printf("\n Vector r:\n");
	displayMatrix (r, n, 1);

	return r;
}

double **matrixMultiply (double **a, double **b, double **c, int n)
{
	double s;
	for (int i = 0; i < n; i++)
	{
		s = 0.0;
		for (int j = 0; j < n; j++)
			s += a[i][j] * b[j][0];
		c[i][0] = s;
	}

	return c;
}

void powerIteration (double **M, int n)
{
	bool ok = 0;
	int steps = 0, i;

	double **c = new double*[n];
	for (i = 0; i < n; i++)
		c[i] = new double[1];

	double **r = createVector_R (n);

	printf ("\t Power Iteration:\n\n");
	while (!ok)
	{
		c = matrixMultiply (M, r, c, n);

		ok = 1;
		for (i = 0; i < n; i++)
		{
			double x = floor(c[i][0] * eps + 0.5) / eps; 
			double y = floor(r[i][0] * eps + 0.5) / eps;

			if (x != y)
			{	
				ok = 0;
				i = n;
			}
		}

		double s = 0.0;

		printf("%2d) ", ++steps);

		for (i = 0; i < n; i++)
		{
			printf("%.3f  ", c[i][0]);
			s += c[i][0];
			r[i][0] = c[i][0];
		}
		
		printf("%.3f \n", s);
	}

	printf("\n\n\t PAGE RANK SCORE:\n\n");
	for (i = 0; i < n; i++)
	{
		printf("PageRank Score for node %d is: %.3f\n", i+1, r[i][0]);
	}

	deallocMatrix (M, n);
	deallocMatrix (r, n);
	deallocMatrix (c, n);

	printf("\n");
}

