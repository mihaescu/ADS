#include"ConvexHull.h"
 
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.

/*
	O, A, B - ....
*/
int cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
 
// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
/*
	P[] - ....
	n - ....
*/
void convexHull(Point P[],int &n)
{
	int k = 0,i=0,j=0,t=0;
	Point H[40], aux;
	bool ok = true;
 
	// Sort points lexicographically
	  do
         {
            ok = true;
            for (i=0 ; i<(n -1 ) ; i++)
               if (P[i+1].x < P[i].x)
                    {
                       aux = P[i] ;
					   P[i] = P[i+1] ; 
					   P[i+1] = aux ;
                       ok = false ;
                    }
            j++ ;  
         }
      while ( !ok) ; 

	// Build lower hull
	for ( i = 0; i < n; ++i) 
	{
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) 
			k--;
		H[k++] = P[i];
	}
 
	// Build upper hull
	for (i = n-2, t = k+1; i >= 0; i--) 
	{
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0)
			k--;
		H[k++] = P[i];
	}
 
	//H.resize(k);
	n=k;
	for(i=0;i<k;i++)
		P[i]=H[i];
}
