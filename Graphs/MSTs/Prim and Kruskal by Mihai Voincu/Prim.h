#ifndef _PRIM_H_
#define _PRIM_H_

#include <stdio.h>
#include <iostream>
#include <conio.h>

#define VMAX 5000

//trebuie in core
void loadData(int a[50][50], int Q[50], int H[50], int &n, int &r);

//trebuie vazut!
int findEdge(int a[50][50], int Q[50], int n);
void updateQ(int a[50][50], int Q[50], int n, int j);

void displayMST(int H[50], int n);

int prim(int a[50][50], int Q[50], int H[50], int &n, int &r);

//in core
void init(int a[50][50], int Q[50], int H[50], int n);

#endif
