#include"ConvexHull.h"

void main()
{
	vector<Point> D;
	Point a;
	FILE * pFile;
  
	
	pFile = fopen ("input.txt" , "r");
	if (pFile == NULL) perror ("Error opening file");
	   else
	   // trebuie functie de incarcare a datelor intr-o structura
	   {
		 while ( ! feof (pFile) )
		 {
		   fscanf(pFile, "%d %d", &a.x, &a.y);
		   D.push_back(a);
		 }
		 fclose (pFile);
	   }
		
	D = convex_hull(D);
	for(int i = 0; i < D.size(); i++)
	{
		a = D.at(i);
		cout<<"x= "<<a.x<<" y= "<<a.y<<endl;
	}
}