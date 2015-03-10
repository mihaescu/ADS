#include <stdio.h>

#define NMAX 20

int  flow[NMAX][NMAX];			 //stores the flow
int	 capacity[NMAX][NMAX];		 //stores the capacities
int	 rezidual_flow[NMAX][NMAX];	 //stores the residual flow
int  maximum_flow;				 //the maximum flow
int  n;					         //the number of nodes from the graph
int  s;					         //the source node
int  t;					         //the sink node

int i,j;
int path[NMAX],nr_nodes,found,first,d;

//it verifies if nod is already in the way path,
//k represents the number of nodes from the path
int isInPath(int nod,int path[],int k){	
  int i;
  for(i=0;i<=k;i++)
    if(path[i] == nod) return(0);
  return(1);
}

//determins the roads in the rezidual graphic from s to t
void RecursiveDFS(int path[],int *nr_nodes,int *found,int k){
  int i;
  for(i=0;i<n;i++)
    if(rezidual_flow[ path[k] ][i] && isInPath(i,path,k)){
      path[k+1] = i;
      if(i == t){
	    *found = 1;
	    *nr_nodes = k+2;
	    return ;
      }else{
	        RecursiveDFS(path,nr_nodes,found,k+1);
	        if(*found) return ;
      }//end if
    }//end if
  return ;
}

void BuildPath(int path[],int *nr_nodes,int *found)
{
  path[0]=s;
  *nr_nodes=1;
  *found=0;
  RecursiveDFS(path,nr_nodes,found,0);
}

int main(void){
	int i,j;
	int path[NMAX],nr_nodes,found,first,d;

	FILE* input = fopen("input.txt","r");
	fscanf(input,"%d",&n);

	for(i=0;i<=n-1;i++)
		for(j=0;j<=n-1;j++){	
			fscanf(input,"%d",&capacity[i][j]);
			flow[i][j]=0;
		}
	printf("Source node: ");scanf("%d",&s);
	printf("Sink node: ");scanf("%d",&t);
	maximum_flow = 0;
    do{
      //calculates the rezidual graphic
	  for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
        rezidual_flow[i][j] = capacity[i][j] - flow[i][j];
		BuildPath(path,&nr_nodes,&found);
		if(!found) break;
		first = 1;
		d=0;
		
		for(i=0;i<nr_nodes-1;i++)
		  if(first || d>rezidual_flow[path[i]][path[i+1]]){
				first = 0;
				d = rezidual_flow[path[i]][path[i+1]];
          }//end if
		maximum_flow += d;
		for(i=0;i<nr_nodes-1;i++)
		    flow[path[i]][path[i+1]] += d;
	 }while(1);//end do
     printf("\nThe Maximum Flow is: %d \n",maximum_flow); 
     //system("pause");
	 return 0;
}
