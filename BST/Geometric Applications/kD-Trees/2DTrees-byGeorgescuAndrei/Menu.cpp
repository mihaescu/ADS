#include"KdTest.h"

void randomGeneratorPoint(int &x,int &y)
{
	srand (time(NULL));

	x=rand()%100+1;
	y=rand()%100+1;
}
void menuFunction(KdTree* myKdTree)
{
	FILE *fp;
	fp=fopen("buhu.txt","r+");

	int xAxis,yAxis;//Build Tree
	int axis=0,parentAxis=1,range;

	int xClosePoint,yClosePoint;//Search
	float currentBest;

	int menu=0,menuOption;//Menu

	do{
		
			puts("Choose one of the following:");
			puts("1.Build from file");
			puts("2.Display");
			puts("3.Insert");
			puts("4.Closest point search");
			puts("5.Range Querry");
			puts("6.N closest points");
			puts("7.Exit");
			scanf("%d",&menuOption);
			char response;
			switch(menuOption)
			{
				
				case 1:
					{
						while(feof(fp)==NULL)
						{
							fscanf(fp,"%d",&xAxis);
							fscanf(fp,"%d",&yAxis);
											
							myKdTree=inserare( myKdTree,xAxis,yAxis,parentAxis);
						}
							break;
					}
				case 2:
					{
						listare(myKdTree,0);
						break;
					}
				case 3:

					{ 
						puts("Dati x:");
						scanf("%d",&xAxis);

						puts("Dati y:");
						scanf("%d",&yAxis);

						myKdTree=inserare( myKdTree,xAxis,yAxis,parentAxis);
						break;
					}
				
				case 4:
					{
						currentBest=infinity;

						puts("Give random number y/n?");
						scanf(" %c", &response);

						if(121 == response)
						{

								randomGeneratorPoint(xAxis,yAxis);
						
						}
					
						else
						{
						puts("Give searched point! \n");//Read Coordinates

						puts("Give the x axis: \n");
						scanf("%d",&xAxis);

						puts("Give the y axis: \n");
						puts("Dati y:");
						scanf("%d",&yAxis);
						}

						find_closest(myKdTree,myKdTree,xAxis,yAxis,currentBest,axis,xClosePoint,yClosePoint);//Use efficient search
						
						printf("\n Closest point using efficient methode is :",currentBest);
						printf("%d ",xClosePoint);
						printf("%d\n",yClosePoint);

						currentBest=infinity;//Set current distance to max
						hard_work(myKdTree,xAxis,yAxis,xClosePoint,yClosePoint,currentBest);

						printf("\n Closest point using hardcore methode is :",currentBest);//Use shovel search
						printf("%d ",xClosePoint);
						printf("%d\n",yClosePoint);

						break;

					}
				case 5:
					{

	
						puts("Give random number and range y/n?");
						scanf(" %c",&response);

						if(121 == response)
						{
								randomGeneratorPoint(xAxis,yAxis);
								range=rand()%100+1;
						
						}
					
						else
						{
						puts("Give querry point! \n");//Read Coordinates and range

						puts("Give the x axis: \n");
						scanf("%d",&xAxis);

						puts("Give the y axis: \n");
						scanf("%d",&yAxis);

						puts("Give range: \n");
						scanf("%d",&range);
						}
						puts("\nThe points inside the range are: ");
						range_Querry(myKdTree,myKdTree,xAxis,yAxis,range);//Use efficient search
						puts("\nThe points inside the range using hard work methode are: ");
						hard_Work_Querry(myKdTree,xAxis,yAxis,range);
						
						break;
					}


				case 6:
					{
						currentBest=infinity;
						int points_Number;
						int contor=0;
						puts("Give random number y/n?");
						scanf(" %c", &response);

						if(121 == response)
						{
								randomGeneratorPoint(xAxis,yAxis);
								points_Number=rand()%14+1;
						}
					
						else
						{
						puts("Give searched point! \n");//Read Coordinates

						puts("Give the x axis: \n");
						scanf("%d",&xAxis);

						puts("Give the y axis: \n");
						puts("Dati y:");
						scanf("%d",&yAxis);

						puts("Give the number n for the closest points: \n");
						scanf("%d",&points_Number);
						}
						std::vector<PointContainer>closest_Distances(points_Number);
						find_closest_Points(myKdTree,myKdTree, xAxis, yAxis,currentBest,axis,closest_Distances,points_Number,contor);//Use efficient search
						puts("\nClosest n points are: ");
						for(int i=0;i<points_Number;i++)
							printf(" %d %d ",closest_Distances[i].x,closest_Distances[i].y);

						currentBest=infinity;//Set current distance to max
						contor=0;

						hard_work_closest(myKdTree,xAxis,yAxis,currentBest,closest_Distances,points_Number,contor);
						puts("Closest n points using hard work are: \n");
						for(int i=0;i<points_Number;i++)
							printf(" %d %d ",closest_Distances[i].x,closest_Distances[i].y);
						break;
						puts("");
					}
				case 7:
					{
						return;
					}
					
			}
		}while(menu!=7);
}
