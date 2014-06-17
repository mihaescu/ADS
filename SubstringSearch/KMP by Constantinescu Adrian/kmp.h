#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define Max_Dim 100

void Read_String(char S[], FILE *f);

void KMP_Matcher_NFA(char text[], char pattern[], int textLen, int patternLen);
void buildNFA(char pattern[], int patternLen, int prefix[]);

void KMP_Matcher_DFA(char text[], char pattern[], int textLen, int patternLen);
void buildDFA(char pattern[], int patternLen, int dfa[256][Max_Dim]);