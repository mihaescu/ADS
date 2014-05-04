#include"kmp.h"
int main()
{
	FILE *f;
	f=fopen("in.txt","r");

	int L_String, L_SubString;
	char String[1000];
    char SubString[100];

	fscanf(f,"%d",&L_String);
	fscanf(f,"%d",&L_SubString);

	Read_String(String, L_String, f);
	Read_String(SubString, L_SubString, f);

	KMP_Matcher(String, SubString, L_String, L_SubString);

	fclose(f);
	return 0;
}