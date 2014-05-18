#include"Rabin-Karp.h"
#include"substringSearchCore.h"
#include<malloc.h>

int main(){
	long q = 101;//large prime number representing the hypothetical hash table size
	
	FILE *fp = fopen("text10kInts.in", "r+");
	FILE *fp2 = fopen("pattern3Ints.in", "r+");
	FILE *fp3 = fopen("results.out","w");

	Text pattern;
	initPattern(pattern,fp2);
	int M = pattern.lenght;
	Text txt;
	initText(txt,M,fp);
	
	int resultRK = RabinKarp(pattern, txt, q);
	int resultBF = bruteForceSubstringSearch(pattern, txt);
	  
	printResult(resultRK, resultBF, fp3);
    return 0;
}