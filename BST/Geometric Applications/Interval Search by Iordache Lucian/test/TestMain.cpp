// BST test.cpp : Defines the entry point for the console application.
//

#include "Header.h"
#include "TestHeader.h"

#define nodeNr 1000
#define intervalNr 200
#define pointNr 300
int main()
{
	int x,y;
	BSTNode *root=0;
	Interval *interval=0;

	size_t len;
    char buf[4096];
	FILE *fi = fopen("TestOutput.out", "rb");
	FILE *fo=fopen("logs.txt","a");
	len = fread(buf, sizeof(char), sizeof(buf), fi);

	displayTime(fo);
	fprintf(fo,"Before execution:\n");
	fprintf(fo,"The checksum of %s is %#x\n","output.out", checkSum(buf, len, 0));

	fi=fopen("TestInput.in","r+");
	fo=fopen("TestOutput.out","w");

    //generateInput(nodeNr,intervalNr,pointNr,fi);

	fi=fopen("TestInput.in","r");
	for(int i=1;i<=nodeNr;i++)
	{
		interval=createNewInterval(interval,fi);
		root=insert(root,interval);
		free(interval);

	}
	fprintf(fo,"\n");
	for(int i=1;i<=intervalNr;i++){
		interval=createNewInterval(interval,fi);
		fprintf(fo,"\n\nQuerry interval: [%d,%d] \n",interval->lo,interval->hi);
		fprintf(fo,"Intersected intervals:\n");
		segmentIntersect(root,interval,fo);
		free(interval);
	}
	for(int i=1;i<=pointNr;i++){
		fprintf(fo,"\n");
		fscanf(fi,"%d",&x);
		fprintf(fo,"\n\nQuerry point:%d \n",x);
		searchPoint(root,x,fo);
		fprintf(fo,"\n");
	}
	fi = fopen("TestOutput.out", "rb");
	fo=fopen("logs.txt","a");
	len = fread(buf, sizeof(char), sizeof(buf), fi);
	fprintf(fo,"After execution:\n");
	fprintf(fo,"The checksum of %s is %#x\n\n","output.out", checkSum(buf, len, 0));
	return 0;
}

