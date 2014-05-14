#include"header.h"

int main()
{
	int A[50];
	int n;
	//FILE *f=fopen("vector.txt","r");
	//loadData(f,A,n);
	LoadArray(A,n);
	//nr = countInversions(int a[], int n);
    printf(" Number of inversions are %d \n", MergeSort(A, n));
  
  return 0;
}