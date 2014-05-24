#include"substringSearchCore.h"
#include"Rabin-Karp.h"

/*
Method that initializes the txt Text structure

txt - the Text structure to be initialized
lenght- the pattern's lenght
fp - the input file pointer
*/
void initText(struct Text &txt, int lenght, FILE *fp){
	txt.radix = 10;
	txt.text = loadText(fp);
	txt.lenght = strlen(txt.text);
}
/*
Method that initializes the pattern Text structure

pattern - the Text structure to be initialized
fp - the input file pointer
*/
void initPattern(struct Text &pattern, FILE *fp2){
	pattern.radix = 10;
	pattern.text = loadText(fp2);
	pattern.lenght = strlen(pattern.text);
}

/*
Method for saving the content of a file in an array

fp - the file's pointer

return - the created array
*/
char* loadText(FILE *fp){
	char text[MAX];
	
	int counter = 0;

	while(!feof(fp) && counter < MAX-1) {
		fscanf(fp, "%s", &text[counter]);
		counter++;
	}	
	fclose(fp);
	return &text[0];
}

/*
Method that performs the substring search with the Brute Force algorithm

pattern - the Text structure that contains the pattern that will be searched for
txt - the Text structure in which the pattern will be searched for

return - 0, if not found,
	   - the index, if found
*/
int bruteForceSubstringSearch(struct Text &pattern, struct Text &txt){
	int M = pattern.lenght;
	int N = txt.lenght;
	int i,j; // indexes for traversing both arrays

	for (i = 0, j = 0; i < N && j < M; i ++) {
		if (txt.text[i] == pattern.text[j])
			j ++;
		
		else{
			i -= j;
			j = 0;
		}
	}
	if( j == M)
		return i - M;
	else
		return M;
}

/*
Method that prints the results of the substring search

RKResults - the result of performing the Rabin-Karp algorithm
bruteForceResults - the result of performing the Brute Force algorithm
fp - the output file pointer
*/
void printResult(int RKResults, int bruteForceResults, FILE *fp){
	if(RKResults != 0)
		fprintf(fp, "Rabin-Karp output: Pattern found at index %d\n", RKResults);
	else
		fprintf(fp,"Rabin-Karp output: Pattern not found.\n");

	if(bruteForceResults != 0)
		fprintf(fp, "Brute Force output: Pattern found at index %d\n", bruteForceResults);
	else
		fprintf(fp,"Brute Force output: Pattern not found.\n");
	fclose(fp);
}