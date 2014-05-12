#include<stdio.h>
#include<stdlib.h>

/*core*/
char* loadText(FILE *inputTextFile);
char* loadPattern(FILE *inputPatternFile);

/*test*/
void bruteForceSubstringSearch(char *pattern, char *text);