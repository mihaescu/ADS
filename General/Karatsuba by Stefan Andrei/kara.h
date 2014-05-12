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

loadNumbers(File *input, char *A, char *B);
//void getOperand(char *operand,int *length);
void karatsuba(char *N1,char *N2,int *lengthN1,int *lengthN2,char *result);

/*utils*/
int powi(int number, int exponent);
void sum(char *leftN1,char *rightN1,char *sumN1,int *lengthLeftN1,int *lengthRightN1);
void dif(char *U,char *x3,char *x2,char *x1,int *length_U);


void classicProduct(char *N1,char *N2,char *result,int *lengthN1,int *lengthN2);
#endif

