#include"kmp.h"

int main()
{
	FILE *f;
	f=fopen("data/Input.in","r");

	int L_String, L_SubString;
	fscanf(f,"%d",&L_String);
	fscanf(f,"%d",&L_SubString);

	char *String = (char *)malloc(L_String * sizeof(char));
	char *SubString = (char *)malloc(L_SubString * sizeof(char));
	Read_String(String, f);
	Read_String(SubString, f);

	fclose(f);

	printf("NFA\n");
	KMP_Matcher_NFA(String, SubString, L_String, L_SubString);

	printf("\nDFA\n");
	KMP_Matcher_DFA(String, SubString, L_String, L_SubString);

	return 0;
}