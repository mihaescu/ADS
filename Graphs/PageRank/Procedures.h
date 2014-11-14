#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define beta 0.85  // damping factor (best between 0.8 and 0.9)
#define eps 10000  // the greater the eps, the greater the precision of the pagerank score

template <class T>
void deallocMatrix (T**, int ); 

void graphGenerator	(char*);
double **loadGraph (FILE* fin, int&);
void displayMatrix (double**, int, int);
double **createMatrix_M (double**, int);
double **createMatrix_B (int);
double **matrixSum (double**, double**, int);
double **createVector_R (int);
double **matrixMultiply (double**, double**, double**, int);
void powerIteration (double**, int);
