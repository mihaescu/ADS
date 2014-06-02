#include"kmp.h"

void Read_String(char S[], FILE *f)
{
	fscanf(f,"%s", S);
}


void KMP_Matcher_NFA(char String[], char SubString[], int L_String, int L_SubString)
{
	int *prefix = (int *)malloc(L_SubString * sizeof(int));

	computePrefix(SubString,L_SubString, Prefix);
	//Nr of characters matched
	int chMatched = 0;

	for(int i=1; i<=L_String; i++) //Scan the text from left to right
	{
		//Next character does not match
		while(ch_matched>0 && SubString[ch_matched+1] != String[i])
		{
			ch_matched=Prefix[ch_matched]; 
		}
		
		//Next character match
		if(SubString[ch_matched+1] == String[i])
			ch_matched++;	

		//Is all of SubString matched?
		if(ch_matched==L_SubString-1)        
		{
			printf("Pattern occurs with shift %d-%d\n", i-L_SubString + 1,i);
			//Look for the next match
			ch_matched=Prefix[ch_matched]; 
		}	
	}
}
void Compute_Prefix(char SubString[], int L_SubString, int Prefix[])
{
	Prefix[1]=0;
	int k=0;

	for(int q=2; q<=L_SubString; q++)
	{
		while(k>0 && SubString[k+1]!=SubString[q])
		{
			k=Prefix[k];
		}
		if(SubString[k+1]==SubString[q])
			k++;
		Prefix[q]=k;
	}
}


void buildDFA(char String[], char SubString[], int L_String, int L_SubString)
{
	// Build DFA from pattern.

	int dfa[256][Max_Dim];
	for (int i = 0; i < 256; i++)
		for (int j = 0; j < Max_Dim; j++)
			dfa[i][j] = 0;


	int M = L_SubString;
	int R = 256;

	dfa[SubString[0]][0] = 1;

	for (int X = 0, j = 1; j < M; j++)
	{
		for (int c = 0; c < R; c++)
			dfa[c][j] = dfa[c][X];		// Copy mismatch cases
		dfa[SubString[j]][j] = j + 1;   // Set match case
		X = dfa[SubString[j]][X];       // Update restart state
	}

	Print(String, SubString, L_String, L_SubString, dfa);
}
void Print(char String[], char SubString[], int L_String, int L_SubString, int dfa[256][Max_Dim])
{
	printf("%s\n", String);

	int offset = Search(String, L_String, L_SubString, dfa);

	for (int i = 0; i < offset; i++)
		printf(" ");

	printf("%s\n", SubString);
}
int Search(char String[], int L_String, int L_SubString, int dfa[256][Max_Dim])
{
	// Simulate operation of DFA on txt

	int i,j;
	int N = L_String;
	int M = L_SubString;
	for (i = 0, j = 0; i < N && j < M; i++)
		j = dfa[String[i]][j];
	if (j == M) 
		return i - M; // found (hit end of pattern)
	else 
		return N;     // not found (hit end of text)
}

