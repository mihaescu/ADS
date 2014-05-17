/*

12345 = 12 · 1000 + 345  ::::: leftN1=12;rightN1=345
6789 = 6 · 1000 + 789    ::::: leftN1=6 ;rightN1=789

x1 = 12 × 6 = 72
x2 = 345 × 789 = 272205
sumN1 = 12 + 345
sumN2 = 6  + 789
U = sumN1 * sumN2
W = U - x2 
x3 = W - x1
x3 = (12 + 345) × (6 + 789) − x2 − x1 = 357 × 795 − 272205 − 72 = 283815 − 272205 - 72 = 11538
                U           - x2
				       W         - x1
result = 72 · 1000^2 + 11538 · 1000 + 272205 = 83810205

V = x1 * 1000 = 72 * 1000 = 72000
M = V * 1000  = 72000 * 1000 = 72000000
K = x3 * 1000 = 11538 * 1000 = 11538000
A = M + K  = 72000000 + 11538000 = 83538000
B = A + x2 = 83538000 + 272205	 = 83810205
*/          

#ifndef _kara_H_
#define _kara_H_

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <math.h>


#define DIMMAX 100
#define NMAX 1024

using namespace std;

void getOperand(char *N1,int *lengthN1);
void karatsuba(char *N1,char *N2,int *lengthN1,int *lengthN2,char *result);


//void loadNumbers(FILE* fp, char *A, char *B);//,int *lengthN1,int *lengthN2);


/*UTILS*/

int powi(int number, int exponent);
void classicProduct(char *N1,char *N2,char *result,int *lengthN1,int *lengthN2);
void sum(char *leftN1,char *rightN1,char *sumN1,int *lengthLeftN1,int *lengthRightN1);
void dif(char *U,char *x3,char *x2,int *length_U);
//void split_Numbers(char *N1,char *N2,int *lengthN1,int *lengthN2);

#endif
