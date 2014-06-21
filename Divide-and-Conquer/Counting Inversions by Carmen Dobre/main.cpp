#include"countingInversion.h"

int main()
{
	int a[50];
	int n;
	int nr;//numarul de inversiuni
    FILE *f=fopen("vector.txt","r");

	loadData(f,a,n);
	nr = countInversions(a, n);
    printf(" Number of inversions are: %d \n",nr );
  
  return 0;
}