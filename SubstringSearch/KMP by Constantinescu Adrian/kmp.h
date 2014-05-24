#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define Max_Dim 100

void Read_String(char S[], FILE *f);

void KMP_Matcher_NFA(char String[], char SubString[], int L_String, int L_SubString);
void Compute_Prefix(char SubString[], int L_SubString, int Prefix[]);

void KMP_Matcher_DFA(char String[], char SubString[], int L_String, int L_SubString);
int Search(char String[], int L_String, int L_SubString, int dfa[256][Max_Dim]);
void Print(char String[], char SubString[], int L_String, int L_SubString, int dfa[256][Max_Dim]);