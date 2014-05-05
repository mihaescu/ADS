#include"Rabin-Karp.h"

void search(char *pattern, char *text, int q){

    int M = strlen(pattern);
    int N = strlen(text);
    int i, j;
    int p = 0;  // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;
  
    for (i = 0; i < M-1; i++)
        h = (h*d)%q;
  
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
 
char* fileReader(){
	char text[MAX];
	//nu aici se specifica fisierul de intrare ... ci in main
	FILE *fp = fopen("Input.in", "r+");
	int counter = 0;

	while(!feof(fp) && counter < MAX-1) {
		fscanf(fp, "%s", &text[counter]);
		counter++;
	}	
	fclose(fp);
	return &text[0];
}
