#include"kmp.h"

void Read_String(char S[], int n, FILE *f)
{
	int i;

	for(i=0; i<=n; i++)
		fscanf(f,"%c", &S[i]);
}

void KMP_Matcher(char String[], char SubString[], int L_String, int L_SubString)
{
	int Prefix[10];

	Compute_Prefix(SubString,L_SubString, Prefix);
	//Nr of characters matched
	int ch_matched=0;

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
			printf("Pattern occurs with shift %d-%d\n", i-L_SubString+1,i);
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