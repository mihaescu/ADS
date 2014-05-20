#include"ConvexHull.h"

void main()
{
	Point D[20];
	Point a;
	FILE * pFile;
	int c=0;
	int n=0;

	pFile = fopen ("input.txt" , "r");
	if (pFile == NULL) perror ("Error opening file");
	   else
	   {
		 while ( ! feof (pFile) )
		 {
		   fscanf(pFile, "%d %d", &a.x, &a.y);
		   D[n]=a;
		   n++;
		 }
		 fclose (pFile);
	   }
		
	convex_hull(D,n);
	for(c = 0; c < n; c++)
	{
		a = D[c];
		printf("x=%d  y=%d \n",a.x,a.y);
	}
}