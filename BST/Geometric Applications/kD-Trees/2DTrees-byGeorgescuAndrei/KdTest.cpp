#include"KdTest.h"




void hard_work_closest(KdTree *a,int xSearchPoint,int ySearchPoint,float &current_best,std::vector<PointContainer> &closest_Distances, int points_number, int &contor)
{
	int i;

  if( a != NULL )
  {
	  a->checked=false;
	 float current_distance=distance(a,xSearchPoint,ySearchPoint);
	  if(current_distance< current_best)
	{	
		if(contor <= points_number-1)

		{
			closest_Distances[contor].x=a->x;
			closest_Distances[contor].y=a->y;
			closest_Distances[contor].distance=current_distance;
			contor++;
		}
		else
		{
			std::sort(closest_Distances.begin(),closest_Distances.end(),mycmp);
			current_best=closest_Distances[closest_Distances.size()-1].distance;
		if(current_distance< current_best)
		{
			
			closest_Distances[closest_Distances.size()-1].x=a->x;
			closest_Distances[closest_Distances.size()-1].y=a->y;
			closest_Distances[closest_Distances.size()-1].distance=current_distance;

			std::sort(closest_Distances.begin(),closest_Distances.end(),mycmp);
			current_best=closest_Distances[closest_Distances.size()-1].distance;
		}
		}
	  }
		hard_work_closest(a->right,xSearchPoint,ySearchPoint, current_best, closest_Distances, points_number, contor);
		hard_work_closest(a->left,xSearchPoint,ySearchPoint,current_best,closest_Distances,points_number,contor);
	  
  }
}
void hard_work(KdTree *a,int xSearchPoint,int ySearchPoint,int &xClosePoint,int & yClosePoint,float &current_best)
{
  int i;

  if( a != NULL )
  {
	  		a->checked=false;
	if(distance(a,xSearchPoint,ySearchPoint)< current_best)
	{	
		xClosePoint=a->x;
		yClosePoint=a->y;
		current_best=distance(a,xSearchPoint,ySearchPoint);
	}
   hard_work( a->right,xSearchPoint,ySearchPoint,xClosePoint,yClosePoint,current_best);
   hard_work( a->left,xSearchPoint,ySearchPoint,xClosePoint ,yClosePoint,current_best);
  }
}
void hard_Work_Querry(KdTree *a ,int xQuerryPoint,int yQuerryPoint,float range)
{
  int i;

  if( a != NULL )
  {
	 float dist=distance(a,xQuerryPoint,yQuerryPoint);
	 a->checked=false;
	if(dist<= range)
	{
		printf(" %d %d  ",a->x,a->y);

	}
   hard_Work_Querry( a->right,xQuerryPoint,yQuerryPoint,range);
   hard_Work_Querry( a->left,xQuerryPoint,yQuerryPoint,range);
  }
}