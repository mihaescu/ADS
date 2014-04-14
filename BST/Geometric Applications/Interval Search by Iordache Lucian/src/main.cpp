#include"Header.h"
#include<time.h>

void main()
{

	BSTNode *root=0;
	Interval *interval=0;
	FILE *f=fopen("input.in","r");
	FILE *fo=fopen("output.out","w");
	int n,x,y;
	fscanf(f,"%d",&n);
	for(int i=1;i<=n;i++)
	{
		interval=createNewInterval(interval,f);
		root=insert(root,interval);
		free(interval);
	}
	fprintf(fo,"\n\n\nDISPLAY TREE\n");
	displayTree(root, 0,fo);
	fscanf(f,"%d",&n);
	for(int i=1;i<=n;i++){
		interval=createNewInterval(interval,f);
		fprintf(fo,"\n\nQuerry interval: [%d,%d] \n",interval->lo,interval->hi);
		fprintf(fo,"Intersected intervals:\n");
		segmentIntersect(root,interval,fo);
		free(interval);
	}
	fscanf(f,"%d",&n);
	for(int i=1;i<=n;i++){
		fscanf(f,"%d",&x);
		fprintf(fo,"\n\nQuerry point:%d \n",x);
		fprintf(fo,"Intersected intervals:\n");
		searchPoint(root,x,fo);
	}

}