#include <stdio.h>
#include <stdlib.h>
  
int MergeAuxSort(int a[], int temp[], int left, int right);
int MergeSort(int a[], int n);
int Merge(int a[], int temp[], int left, int middle, int right);
void LoadArray(int A[50],int &n);