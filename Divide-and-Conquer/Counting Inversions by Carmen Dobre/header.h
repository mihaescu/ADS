#include <stdio.h>
#include <stdlib.h>
 
/* countingInversions.h*/

int countInversions(int a[], int n);

void loadArray(int A[50],int &n); 

int MergeAuxSort(int a[], int temp[], int left, int right);
int merge(int a[], int temp[], int left, int middle, int right);
