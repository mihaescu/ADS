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
void getNum(char *Number1,int *length_Number1);
void Produs_Clasic(char *Number1,char *Number2,char *produs,int *length_Number1,int *length_Number2);
void karatsuba(char *Number1,char *Number2,int *length_Number1,int *length_Number2,char *produs);
int powi(int number, int exponent);
void sum(char *Number1_left,char *Number1_right,char *Number1_sum,int *length_Number1_left,int *length_Number1_rigth);
void dif(char *U,char *x3,char *x2,char *x1,int *length_U);
#endif

