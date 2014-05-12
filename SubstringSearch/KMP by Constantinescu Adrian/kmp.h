#include<stdio.h>
#include<stdlib.h>

void Read_String(char S[], int n, FILE *f);//to core!
void KnuthMorisPratt(char text[], char pattern[], int textLength, int patternLength);
void Compute_Prefix(char SubString[], int L_SubString, int Prefix[]);
/* trebuie sa avem char[][] dfa (char pattern[]) */