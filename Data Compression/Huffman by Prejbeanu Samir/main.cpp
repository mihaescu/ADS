#include "huffman.h"

int main()
{
    FILE *f;
    f=fopen("input.txt","r");
	int i;
	char input[1024],output[1024];
	fgets(input,1024,f);
	printf("Frequency of characters from the file:\n");
	buildHuffman(input);
	printf("\n\nCharacters in the file and their related code:\n\n");
	for (i = 0; i < 128; i++)
		if (huffCode[i])
            printf("\" %c \" -> %s\n",i,huffCode[i]);
    printf("\n\n");
	codare(input,output);
	printf("\nEncoded file:\n%s \n",output);
	printf("\nDecoded: ");
	decodare(output, queue[1]);
	printf("\n\n");
	system("PAUSE");
	return 0;
}
