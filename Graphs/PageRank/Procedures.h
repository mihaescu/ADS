#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#define beta 0.85  // damping factor (best between 0.8 and 0.9)
#define eps 10000  // the greater the eps, the greater the precision of the pagerank score

using namespace std;

//ifstream f;

void allocMatrix (double**, int, int);
void deallocMatrix (double**, int); 
void displayMatrix (double**, int, int);
void readWebGraph (double**, int, int);
void createMatrix_M (double**, int);
void createMatrix_B (double**, int);
void matrixSum (double**, double**, int);
void createVector_R (double**, int);
void matrixMultiply (double**, double**, double**, int);
