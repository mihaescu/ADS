#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define beta 0.85  // damping factor (best between 0.8 and 0.9)
#define eps 10000  // the greater the eps, the greater the precision of the pagerank score

/*---------- CORE FUNCTIONS ---------- */

/* create matrix M with *beta* probability of random teleporting, based on
the adjaceny matrix sent as parameter*/
double **createMatrix_M (double**, const int&);

/* create matrix B with *beta* probability of random teleporting */
double **createMatrix_B (const int&);

/* create the column-vector (eigenvector) R */
double **createVector_R (const int&);

/* repeatedly multiply matrix A with vector R, until R = A x R */
void powerIteration (double**, const int&);


/*---------- UTILITY FUNCTIONS ----------*/

/* deallocate memory for a matrix */
template <class T>
void deallocMatrix (T**, int );   

/* generate a random digraph in a file (file name given as parameter)*/
void graphGenerator	(char*);		

/* load graph from a given file, the integer holding the number of nodes */
double **loadGraph (FILE* fin, int&);

/* display graph in console */
void displayGraph (FILE* fin, char*);

/* display matrix in console */
void displayMatrix (double**, const int&, const int&);

/* compute the sum of 2 matrices */
double **matrixSum (double**, double**, const int&);

/* compute the product of 2 matrices */
double **matrixMultiply (double**, double**, double**, const int&);
