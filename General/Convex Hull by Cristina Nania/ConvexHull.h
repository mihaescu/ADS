#include <algorithm>
#include <vector>
#include<iostream>
using namespace std;
 
typedef int coord_t;         // coordinate type
typedef int coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2
 
struct Point {
	coord_t x, y;
 
	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

coord2_t cross(const Point &O, const Point &A, const Point &B);
vector<Point> convex_hull(vector<Point> P);
