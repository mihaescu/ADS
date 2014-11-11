#include "Procedures.h"

void allocMatrix (double **a, int m, int n)
{
	int i, j;

	for (i = 0; i < m; i++)
		a[i] = new double[n];

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = 0;
}

void deallocMatrix (double **a, int m) 
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
			cout << setw(9) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void readWebGraph (double **a, int n, int m)
{
	int i, x, y;

	for (i = 1; i <= m; i++)
	{
		cout << "\nRead link number " << i << " (from x to y): ";
		cout << "\nRead x & y: ";
		cin >> x >> y;
		//f >> x >> y;
		a[x][y] = 1;
	}
}

void createMatrix_M (double **a, int n)
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

	cout << "\nM Matrix:\n";
	displayMatrix (a, n, n);

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] *= beta;

	cout << "\nM Matrix after random teleports (probability = " << beta << "):\n";
	displayMatrix (a, n, n);
}

void createMatrix_B (double **a, int n)          
{
	int i, j;

	for (i = 0; i < n; i++)					// create a matrix having all the elements 1/n
		for (j = 0; j < n; j++)
			a[i][j] = 1.0 / n;

	cout << "\nMatrix B:\n";
	displayMatrix (a, n, n);

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] *= 1.0-beta;

	cout << "\nMatrix B after random teleports (probability = " << 1.0 - beta << "):\n";
	displayMatrix (a, n, n);
}

void matrixSum (double **a, double **b, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] += b[i][j];
}

void createVector_R (double **r, int n)              // create the column-vector (eigenvector) R
{
	for (int i = 0; i < n; i++)
		r[i][0] = 1.0 / n;

	cout << "\n Vectorul r:\n";
	displayMatrix (r, n, 1);
}

void matrixMultiply (double **a, double **b, double **c, int n)
{
	double s;
	for (int i = 0; i < n; i++)
	{
		s = 0.0;
		for (int j = 0; j < n; j++)
			s += a[i][j] * b[j][0];
		c[i][0] = s;
	}
}

