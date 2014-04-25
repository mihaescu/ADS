#ifndef _PRIM_H_
#define _PRIM_H_

#include <stdio.h>
#include <iostream>
#include <conio.h>

#define VMAX 5000

void loadData(int a[50][50], int Q[50], int H[50], int &n, int &r);

int findEdge(int a[50][50], int Q[50], int n);

void updateQ(int a[50][50], int Q[50], int n, int j);

void displayMST(int H[50], int n);

int prim(int a[50][50], int Q[50], int H[50], int &n, int &r);

void init(int a[50][50], int Q[50], int H[50], int n);

#endif
