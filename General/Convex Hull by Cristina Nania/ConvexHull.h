#include<stdio.h>
#include<stdlib.h>
 
 
struct Point {
	int x, y;
 
	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

/*  abbout function & parametrers*/
int cross(const Point &O, const Point &A, const Point &B);
/*  
	- about function & parametrers
	- function should return the solution

*/
Point[] convexHull(Point P[],int &n);

void displaySolution(Point[] solution);
