#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define d 256
#define MAX 10000

void RabinKarp(char *pattern, char *text, int q);
char* fileReader(FILE *fp);
void bruteForceSubstringSearch(char *pattern, char *text);