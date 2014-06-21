#include <stdio.h>
#include <stdlib.h>

int countInversions(int a[], int n);
void loadData(FILE *f,int a[],int &n);

int sortAndMerge(int a[], int temp[], int left, int right);
int merge(int a[], int temp[], int left, int middle, int right);
