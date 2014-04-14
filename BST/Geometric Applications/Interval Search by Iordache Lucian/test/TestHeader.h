#ifndef BST_TEST
#define BST_TEST

#include<time.h>
#include <stdlib.h>


void generateInput(int nodeNr,int intervalNr,int pointNr,FILE *f);
unsigned checkSum(void *buffer, size_t len, unsigned int seed);
void displayTime(FILE *f);

#endif