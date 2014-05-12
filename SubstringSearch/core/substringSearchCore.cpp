#include"kmp.h"

void Read_String(char S[], int n, FILE *f)
{
	int i;

	for(i=0; i<=n; i++)
		fscanf(f,"%c", &S[i]);
}

