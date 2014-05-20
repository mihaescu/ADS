#include<stdio.h>
#include<stdlib.h>
 
 
struct Point {
	int x, y;
 
	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

int cross(const Point &O, const Point &A, const Point &B);
void convex_hull(Point P[],int &n);
