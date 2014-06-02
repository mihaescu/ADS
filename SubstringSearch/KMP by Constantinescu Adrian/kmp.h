#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define Max_Dim 100

void readString(char S[], FILE *f);

void searchKMPnfa(char String[], char SubString[], int L_String, int L_SubString);
void buildNFA(char SubString[], int L_SubString, int Prefix[]);

void buildDFA(char text[], char pattern[], int textLength, int patternLength);
int searchKMPdfa(char String[], int L_String, int L_SubString, int dfa[256][Max_Dim]);
void print(char String[], char SubString[], int L_String, int L_SubString, int dfa[256][Max_Dim]);