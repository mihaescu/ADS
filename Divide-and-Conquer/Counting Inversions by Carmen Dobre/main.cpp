#include"header.h"

int main()
{
	int A[50];
	int n;
	LoadArray(A,n);
    printf(" Number of inversions are %d \n", MergeSort(A, n));
  
  return 0;
}