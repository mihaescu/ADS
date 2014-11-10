#ifndef _KDTREE_H
#define _KDTREE_H

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<vector>
#include<algorithm>

#define infinity 999999

typedef struct Tree{
	int x;
	int y;
	int axis;
	Tree *left;
	Tree *right;
	bool checked;
}KdTree;
typedef struct PointContainer{
	int x;
	int y;
	float distance;
}PointContainer;


void listare( KdTree *a, int num);
KdTree* inserare(KdTree *p,int x,int y,int &parentAxis);
void find_closest(KdTree *a,KdTree *b,int xSearchPoint,int ySearchPoint,float &parentAxis,int &axis,int &xClosePoint,int &yClosePoint);
void range_Querry(KdTree *a , KdTree *b,int xQuerryPoint,int yQuerryPoint,float range);
void find_closest_Points(KdTree *a , KdTree *b,int xSearchPoint,int ySearchPoint,float &current_best,int &axis,std::vector<PointContainer> &closest_Distances,int points_Number,int &contor);
float distance(KdTree *a,int xSearchPoint,int ySearchPoint);
bool mycmp(PointContainer x, PointContainer y);
#endif