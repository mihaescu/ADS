#include"kmp.h"

void Read_String(char S[], FILE *f)
{
	fscanf(f,"%s", S);
}


void KMP_Matcher_NFA(char text[], char pattern[], int textLen, int patternLen)
{
	int *prefix = (int *)malloc(patternLen * sizeof(int));

	buildNFA(pattern, patternLen, prefix);

	//Nr of characters matched
	int chMatched=0;

	for (int i = 1; i <= textLen; i++) //Scan the text from left to right
	{
		//Next character does not match
		while (chMatched > 0 && pattern[chMatched + 1] != text[i])
			chMatched = prefix[chMatched];
		
		//Next character match
		if (pattern[chMatched + 1] == text[i])
			chMatched++;

		//Is all of pattern matched?
		if (chMatched == patternLen - 1)
		{
			printf("Pattern occurs with shift %d-%d\n", i - patternLen + 1, i);
			//Look for the next match
			chMatched = prefix[chMatched];
		}	
	}
}
void buildNFA(char pattern[], int L_SubString, int prefix[])
{
	prefix[1] = 0;
	int k=0;

	for(int q=2; q<=L_SubString; q++)
	{
		while (k>0 && pattern[k + 1] != pattern[q])
		{
			k = prefix[k];
		}
		if (pattern[k + 1] == pattern[q])
			k++;
		prefix[q] = k;
	}
}


void KMP_Matcher_DFA(char text[], char pattern[], int textLen, int patternLen)
{
	int i, j, offset;
	int N = textLen;
	int M = patternLen;
	int dfa[256][Max_Dim];

	for (int i = 0; i < 256; i++)
		for (int j = 0; j < Max_Dim; j++)
			dfa[i][j] = 0;

	buildDFA(pattern, patternLen, dfa);

	// Simulate operation of DFA on txt
	printf("%s\n", text);
	
	for (i = 0, j = 0; i < N && j < M; i++)
		j = dfa[text[i]][j];
	if (j == M)
		offset = i - M;  // found (hit end of pattern)
	else
		offset =  N;     // not found (hit end of text)

	for (int i = 0; i < offset; i++)
		printf(" ");

	printf("%s\n", pattern);
}
void buildDFA(char pattern[], int patternLen, int dfa[256][Max_Dim])
{
	// Build DFA from pattern.

	int M = patternLen;
	int R = 256;

	dfa[pattern[0]][0] = 1;

	for (int X = 0, j = 1; j < M; j++)
	{
		for (int c = 0; c < R; c++)
			dfa[c][j] = dfa[c][X];    // Copy mismatch cases
		dfa[pattern[j]][j] = j + 1;   // Set match case
		X = dfa[pattern[j]][X];       // Update restart state
	}
}