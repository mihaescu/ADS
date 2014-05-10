#include"Rabin-Karp.h"

int main(){
	char *pattern = "124";
	FILE *fp = fopen("Input.in", "r+");
    int q = 101;
	char* text = fileReader(fp);
	RabinKarp(pattern, text, q);
    bruteForceSubstringSearch(pattern, text);
    getch();
    return 0;
}