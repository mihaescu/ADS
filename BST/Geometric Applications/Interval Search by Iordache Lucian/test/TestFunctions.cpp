#include "Header.h"
#include "TestHeader.h"

/*Generate random input*/
void generateInput(int nodeNr,int intervalNr,int pointNr,FILE *f)
{
	srand(time(NULL));
	for(int i=0;i<nodeNr;i++)
	{
		fprintf(f,"%d %d\n",rand() % 500 + 1 ,rand() % 50+1);
	}
	fprintf(f,"\n\n");

	for(int i=0;i<intervalNr;i++)
	{
		fprintf(f,"%d %d\n",rand() % 500 + 1 ,rand() % 500+1);
	}
	fprintf(f,"\n\n");
	for(int i=0;i<pointNr;i++)
	{
		fprintf(f,"%d\n",rand() % 500 + 1);
	}

	fclose(f);
}

/*Calculate binary sum of output before and after execution of the program*/
unsigned checkSum(void *buffer, size_t len, unsigned int seed)
{
	unsigned char *buf = (unsigned char *)buffer;
	size_t i;

	for (i = 0; i < len; ++i)
		seed += (unsigned int)(*buf++);
	return seed;
}

/*display date and time when program is beeing executed*/
void displayTime(FILE *f)
{
	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	fprintf (f,"%s", asctime (timeinfo) );
}
