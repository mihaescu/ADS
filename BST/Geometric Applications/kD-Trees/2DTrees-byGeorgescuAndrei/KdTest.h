#include"KdTree.h"
void hard_work_closest(KdTree *a,int xSearchPoint,int ySearchPoint,float &current_best,std::vector<PointContainer> &closest_Distances,int points_number,int &contor);
void hard_Work_Querry(KdTree *a ,int xQuerryPoint,int yQuerryPoint,float range);
void hard_work(KdTree *a,int xSearchPoint,int ySearchPoint,int &xClosePoint,int & yClosePoint,float &current_best);