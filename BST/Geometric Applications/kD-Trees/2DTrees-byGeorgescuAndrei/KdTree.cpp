#include"KdTest.h"


float distance(KdTree *a,int xSearchPoint,int ySearchPoint)
{
	float dist=((xSearchPoint-a->x)*(xSearchPoint-a->x)+(ySearchPoint-a->y)*(ySearchPoint-a->y));
	dist=sqrt(dist);
	return dist;
}
void find_closest(KdTree *a , KdTree *b,int xSearchPoint,int ySearchPoint,float &current_best,int &axis,int &xClosePoint,int & yClosePoint)
{
	float current_distance;
  if(a!=NULL)
	  if(!a->axis)
		  if(a->x>xSearchPoint)
			 find_closest(a->left,a,xSearchPoint,ySearchPoint,current_best,axis,xClosePoint,yClosePoint);
		  else
			 find_closest(a->right,a,xSearchPoint,ySearchPoint,current_best,axis,xClosePoint,yClosePoint);
   
	  else
		  if(a->y>ySearchPoint)
			find_closest(a->left,a,xSearchPoint,ySearchPoint,current_best,axis,xClosePoint,yClosePoint);
         
		  else
			 find_closest(a->right,a,xSearchPoint,ySearchPoint,current_best,axis,xClosePoint,yClosePoint);
 
	axis=b->axis;
	current_distance=distance(b,xSearchPoint,ySearchPoint);

	if(current_distance < current_best)
	{
		 xClosePoint=b->x;
		 yClosePoint=b->y;
		 current_best=current_distance;
	}
	
if(b->checked==true)return;
else
{
 	b->checked=true;
  if(axis==0)
  {
	  if(abs(xSearchPoint-b->x) < current_best)
		  if(b->x>xSearchPoint && b->right!=NULL)
			find_closest(b->right,b,xSearchPoint,ySearchPoint,current_best,axis,xClosePoint,yClosePoint);
		  else
			  if( b->left!=NULL)
				  find_closest(b->left,b,xSearchPoint,ySearchPoint,current_best,axis,xClosePoint,yClosePoint);
  }
	 else
		 if(abs(ySearchPoint-b->y) < current_best)
			 if(b->y>ySearchPoint && b->right!=NULL) 
				find_closest(b->right,b,xSearchPoint,ySearchPoint,current_best,axis,xClosePoint,yClosePoint);
			 else
				 if(b->left!=NULL)
					 find_closest(b->left,b,xSearchPoint,ySearchPoint,current_best,axis,xClosePoint,yClosePoint);

	}
	
  
}
bool mycmp(PointContainer x, PointContainer y)
 {
	 return x.distance < y.distance;
 }
void find_closest_Points(KdTree *a , KdTree *b,int xSearchPoint,int ySearchPoint,float &current_best,int &axis,std::vector<PointContainer> &closest_Distances,int points_Number,int &contor)
{
	float current_distance;
  if(a!=NULL)
	  if(!a->axis)
		  if(a->x>xSearchPoint)
			 find_closest_Points(a->left,a,xSearchPoint,ySearchPoint,current_best,axis,closest_Distances,points_Number,contor);
		  else
			 find_closest_Points(a->right,a,xSearchPoint,ySearchPoint,current_best,axis,closest_Distances,points_Number,contor);
   
	  else
		  if(a->y>ySearchPoint)
			find_closest_Points(a->left,a,xSearchPoint,ySearchPoint,current_best,axis,closest_Distances,points_Number,contor);
         
		  else
			 find_closest_Points(a->right,a,xSearchPoint,ySearchPoint,current_best,axis,closest_Distances,points_Number,contor);
 
  if(b->checked==true)return;
else
{
	axis=b->axis;
	current_distance=distance(b,xSearchPoint,ySearchPoint);

	
		if(contor < points_Number)

		{
			closest_Distances[contor].x=b->x;
			closest_Distances[contor].y=b->y;
			closest_Distances[contor].distance=current_distance;
	
			contor++;
		}
		else
		{
			std::sort(closest_Distances.begin(),closest_Distances.end(),mycmp);
			current_best=closest_Distances[closest_Distances.size()-1].distance;
			if(current_distance < current_best)
			{


			closest_Distances[closest_Distances.size()-1].x=b->x;
			closest_Distances[closest_Distances.size()-1].y=b->y;
			closest_Distances[closest_Distances.size()-1].distance=current_distance;

			std::sort(closest_Distances.begin(),closest_Distances.end(),mycmp);
			current_best=closest_Distances[closest_Distances.size()-1].distance;

			
			}
		}
		



	b->checked=true;
  if(axis==0)
  {
	  if(abs(xSearchPoint-b->x) <= current_best)
		  if(b->x>xSearchPoint && b->right!=NULL)
			find_closest_Points(b->right,b,xSearchPoint,ySearchPoint,current_best,axis,closest_Distances,points_Number,contor);
		  else
			  if( b->left!=NULL)
				 find_closest_Points(b->left,b,xSearchPoint,ySearchPoint,current_best,axis,closest_Distances,points_Number,contor);
  }
	 else
	 {
		 if(abs(ySearchPoint-b->y) <= current_best)
			 if(b->y>ySearchPoint && b->right!=NULL) 
				find_closest_Points(b->right,b,xSearchPoint,ySearchPoint,current_best,axis,closest_Distances,points_Number,contor);
			 else
				 if(b->left!=NULL)
					find_closest_Points(b->left,b,xSearchPoint,ySearchPoint,current_best,axis,closest_Distances,points_Number,contor);
	}
}
}		
void range_Querry(KdTree *a , KdTree *b,int xQuerryPoint,int yQuerryPoint,float range)
{
  if(a!=NULL)
	  if(!a->axis)
		  if(a->x > xQuerryPoint)
			range_Querry(a->left,a,xQuerryPoint,yQuerryPoint,range);
		  else
			 range_Querry(a->right,a,xQuerryPoint,yQuerryPoint,range);
   
	  else
		  if(a->y > yQuerryPoint)
			range_Querry(a->left,a,xQuerryPoint,yQuerryPoint,range);
         
		  else
			 range_Querry(a->right,a,xQuerryPoint,yQuerryPoint,range);

if(b->checked==true)return;
else
{
	float current_distance=distance(b,xQuerryPoint,yQuerryPoint);
	if(range >= current_distance)
		printf("%d %d  ",b->x , b->y);
	b->checked=true;
	if(b->axis==0)
  {
	  if(abs(xQuerryPoint-b->x) < range)
		  if(b->x>xQuerryPoint && b->right!=NULL)
			range_Querry(b->right,b,xQuerryPoint,yQuerryPoint,range);
		  else
			  if( b->left!=NULL)
				range_Querry(b->left,b,xQuerryPoint,yQuerryPoint,range);
  }
	 else
		 if(abs(yQuerryPoint-b->y) < range)
			 if(b->y>yQuerryPoint && b->right!=NULL) 
				range_Querry(b->right,b,xQuerryPoint,yQuerryPoint,range);
			 else
				 if(b->left!=NULL)
					 range_Querry(b->left,b,xQuerryPoint,yQuerryPoint,range);
}
}
KdTree *inserare(KdTree *p,int x,int y,int &parentAxis)
{ 

 if (p==NULL)
	{ 
		 p=(KdTree*)calloc(1,sizeof(KdTree)); 
		 p->x=x; 
		 p->y=y;
		 if(parentAxis==0)
			 p->axis=1;
		 else
			 p->axis=0;
		 p->right=NULL;
	     p->left=NULL; 
	} 
 else 
 { if(p->axis==0){
	if (x<p->x)
	{
		parentAxis=p->axis;
		p->left = inserare(p->left,x,y,parentAxis);
	}
	else
	{
		parentAxis=p->axis;
		p->right = inserare(p->right,x,y,parentAxis);
	}
 }
 else {
	 if (y<p->y)
	 {
			parentAxis=p->axis;
			p->left = inserare(p->left,x,y,parentAxis); 
	 }
	 else
	 {
		 parentAxis=p->axis;
			p->right = inserare(p->right,x,y,parentAxis); 
	 }
 }

 } 
 return p;
}
void listare( KdTree *a, int num)
{
  int i;
 
  if( a != NULL )
  {
    listare( a->right, num+3 );
    for( i = 0; i < num; i++ )
           printf("  ");
	printf("(%d %d)\n",a->x,a->y);
    listare( a->left, num+3 );
  }
}
