#include "Procedures.h"

int main()
{
	int i, nodes, links;

	//f.open ("PageRank.txt");

	//f >> nodes >> links;
	cout << "Number of webpages: ";
	cin >> nodes;
		
	cout << "Number of links: ";
	cin	>> links;

	double **adj = new double*[nodes];
	double **M= new double*[nodes];
	double **B= new double*[nodes];
	double **r= new double*[nodes];
	double **c= new double*[nodes];

	allocMatrix (adj, nodes, nodes);
	allocMatrix (M, nodes, nodes);
	allocMatrix (B, nodes, nodes);
	allocMatrix (r, nodes, 1);
	allocMatrix (c, nodes, 1);

	readWebGraph (adj, nodes, links);

	cout << "\n Adjacency Matrix:\n";
	displayMatrix (adj, nodes, nodes);

	matrixSum (M, adj, nodes);
	deallocMatrix (adj, nodes);
	
	createMatrix_M (M, nodes);

	createMatrix_B (B, nodes);

	matrixSum (M, B, nodes);
	deallocMatrix (B, nodes);

	cout << "\n Matrix A = M + B \n";
	displayMatrix (M, nodes, nodes);

	createVector_R (r, nodes);

	bool ok = 0;
	int steps = 0;

	while (!ok)
	{
		matrixMultiply (M, r, c, nodes);

		ok = 1;
		for (i = 0; i < nodes; i++)
		{
			double x = floor(c[i][0] * eps + 0.5) / eps; 
			double y = floor(r[i][0] * eps + 0.5) / eps;

			if (x != y)
			{	
				ok = 0;
				i = nodes;
			}
		}

		double s = 0.0;

		cout << setw(2) << ++steps << ")";
		for (i = 0; i < nodes; i++)
		{
			cout << setw(9) << setprecision(3) << c[i][0];
			s += c[i][0];
		}
		cout << setw(9) << setprecision(3) << s << endl;

		for (i = 0; i < nodes; i++)
		{
			r[i][0] = c[i][0];
		}

	}

	deallocMatrix (M, nodes);
	deallocMatrix (r, nodes);
	deallocMatrix (c, nodes);
	return 0;
}
