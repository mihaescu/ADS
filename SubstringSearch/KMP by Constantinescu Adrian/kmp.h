#include<stdio.h>
#include<stdlib.h>

void Read_String(char S[], int n, FILE *f);
void KMP_Matcher(char String[], char SubString[], int L_String, int L_SubString);
void Compute_Prefix(char SubString[], int L_SubString, int Prefix[]);