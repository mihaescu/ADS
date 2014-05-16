#include"Rabin-Karp.h"

int main(){
/*
trebuie sa avem:
- pattern3Chars.in
- text10kInts.in
- result.out

*/
	char *pattern = "124";
	FILE *fp = fopen("Input.in", "r+");
    int q = 101;//trebuie spus ce reprezinta
	char* text = fileReader(fp);
	RabinKarp(pattern, text, q);
    bruteForceSubstringSearch(pattern, text);
    getch();
    return 0;
}