#include"kmp.h"

int main()
{
	FILE *f;
	f=fopen("data/Input.in","r");

	int textLen, patternLen;
	fscanf(f, "%d", &textLen);
	fscanf(f, "%d", &patternLen);

	char *text = (char *)malloc(textLen * sizeof(char));
	char *pattern = (char *)malloc(patternLen * sizeof(char));

	Read_String(text, f);
	Read_String(pattern, f);

	fclose(f);

	printf("NFA\n");
	KMP_Matcher_NFA(text, pattern, textLen, patternLen);

	printf("\nDFA\n");
	KMP_Matcher_DFA(text, pattern, textLen, patternLen);

	return 0;
}