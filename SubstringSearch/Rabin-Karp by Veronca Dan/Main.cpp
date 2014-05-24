#include"Rabin-Karp.h"
#include"substringSearchCore.h"
#include<malloc.h>

int main(){
	long q = 101;//large prime number representing the hypothetical hash table size
	
	FILE *textF = fopen("text10kInts.in", "r+");
	FILE *patF = fopen("pattern3Ints.in", "r+");
	FILE *resultF = fopen("results.out", "w");

	Text pattern;
	initPattern(pattern, patF);
	int M = pattern.lenght;
	Text txt;
	initText(txt, M, textF);
	
	int resultRK = RabinKarp(pattern, txt, q);
	int resultBF = bruteForceSubstringSearch(pattern, txt);
	  
	printResult(resultRK, resultBF, resultF);
    return 0;
}