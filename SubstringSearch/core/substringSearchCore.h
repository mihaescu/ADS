#include<stdio.h>
#include<stdlib.h>

typedef struct Text{
	char* text;
	int hash;
	int radix;
	int lenght;
}Text;

/*core*/
void initText(struct Text &txt, int lenght, FILE *fp);
void initPattern(struct Text &pattern, FILE *fp2);
char* loadText(FILE *inputTextFile);
void printResult(int RKResults,int bruteForceResults, FILE *ouputResults);

/*test*/
int bruteForceSubstringSearch(struct Text &pattern, struct Text &txt);