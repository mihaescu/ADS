#include"Rabin-Karp.h"

/* functia trebuie sa returneze:
	-1 daca nu se gaseste pattern in text
	>0 adica i-ul
	*/
	
	/*
	trebuie sa avem o functie 
		long modularHashing(char *key, int M);//key este stringul pentru care se calculeaza hash-ul si M este radix-ul lui pattern 
	*/
	
void RabinKarp(char *pattern, char *txt, int q){
	
    int M = strlen(pattern);
    int N = strlen(txt);
    int i, j;//trebuie explicat ce reprezinta fiecare
    int patHash = 0;  // hash value for pattern
    int txtHash = 0; 	// hash value for text
    int h = 1;
	char *text = txt;
    for (i = 0; i < M-1; i++)
        h = (h * d) % q;
  
    for (i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }
  
    for (i = 0; i <= N - M; i++) {
        if ( p == t ) {
            for (j = 0; j < M; j++)  
                if (text[i+j] != pattern[j])
                    break;
            if (j == M)
                 printf("Pattern found at index %d \n", i);
            
        }
       
 
        if ( i < N-M ) {
            t = (d*(t - text[i]*h) + text[i+M])%q;      

            if(t < 0) 
              t = (t + q); 
        }
    }
}

void bruteForceSubstringSearch(char *pattern, char *text){
	int M = strlen(pattern);
    int N = strlen(text);
	int j = 0, i;
	for (i = 0; i < N ; i++) {
		if (text[i] == pattern[j]){
			j++;
			if (j == M){
				printf("Pattern found at index %d \n", i-M+1);
				j=0;
			}
		}
		else 
			j = 0; 		
	}
	if (j == 0)
		 printf("Pattern not found.");
}
char* fileReader(FILE *fp){
	char text[MAX];
	
	int counter = 0;

	while(!feof(fp) && counter < MAX-1) {
		fscanf(fp, "%s", &text[counter]);
		counter++;
	}	
	fclose(fp);
	return &text[0];
}