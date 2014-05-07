#include "Hungarian.h"
void StepOne(int &step, int c[10][10] , int n)
{
    int minval,i,j;
    for(i=0;i<n;i++)
    {
        minval=c[i][0];
        for(j=1;j<n;j++)
            if(minval>c[i][j])
                minval=c[i][j];
        for(j=0;j<n;j++)
            c[i][j]=c[i][j]-minval;
    }
    step=2;
    printf("\nstep 1");
}
void StepTwo(int &step, int col[10], int row[10], int n, int m[10][10],int c[10][10])
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(c[i][j]==0 && col[j]==0 && row[i]==0)
            {
                m[i][j]=1;
                col[j]=1;
                row[i]=1;
            }
    for(i=0;i<n;i++)
        col[i]=row[i]=0;
    step=3;
    printf("\nstep 2");
}
void StepThree(int & step, int n, int col[10], int m[10][10])
{
    int count,i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(m[i][j]==1)
                col[j]=1;
    count=0;
    for(j=0;j<n;j++)
        count=count+col[j];
    if(count>=n)
        step=7;
    else
        step=4;
    printf("\nstep 3");
}
void FindAZero(int &rows,int &cols, int row[10], int col[10], int c[10][10], int n)
{
    int i,j;
    bool done;
    rows=cols=-1;
    i=0;
    done=false;
    do
    {
        j=0;
        do
        {
            if(c[i][j]==0 && row[i]==0 && col[j]==0)
            {
                rows=i;
                cols=j;
                done=true;
                
            }
            j=j+1;
        }while(j<n);
        i=i+1;
        if(i>=n)
            done=true;
    }while(!done);

}
bool StarInRow(int rows, int n,int m[10][10])
{
    bool tbool=false;
    for(int j=0;j<n;j++)
        if(m[rows][j]==1)
            tbool=true;
    return tbool;
}
void FindStarInRow(int rows,int &cols, int n, int m[10][10])
{
    cols=-1;
    for(int j=0;j<n;j++)
        if(m[rows][j]==1)
            cols=j;
}
void StepFour(int &step, int n, int m[10][10], int row[10], int col[10], int &Z0_r, int &Z0_c, int c[10][10])
{
    int rows=-1,cols=-1;
    bool done=false;
    while(!done)
    {
        FindAZero(rows,cols,row,col,c,n);
        if(rows==-1)
        {
            done=true;
            step=6;
        }
        else
        {
            m[rows][cols]=2;
            if(StarInRow(rows,n,m))
            {
                FindStarInRow(rows,cols,n,m);
                row[rows]=1;
                col[cols]=0;
            }
            else
            {
                done=true;
                step=5;
                Z0_r=rows;
                Z0_c=cols;
            }
        }
    }
    printf("\nstep 4");
}
void FindStarInCol(int cols,int &rows, int n, int m[10][10])
{
    rows=-1;
    for(int j=0;j<n;j++)
        if(m[j][cols]==1)
            rows=j;
}
void FindPrimeInRow(int rows,int &cols, int n, int m[10][10])
{
    for(int j=0;j<n;j++)
        if(m[rows][j]==2)
            cols=j;
}
void CovertPath(int path[20][10],int count, int m[10][10])
{
    int i;
    for(i=0;i<=count;i++)
        if(m[path[i][1]][path[i][2]]==1)
            m[path[i][1]][path[i][2]]=0;
        else
            m[path[i][1]][path[i][2]]=1;
}
void ClearCovers(int row[10],int col[10], int n)
{
    for(int i=0;i<n;i++)
        row[i]=col[i]=0;
}
void ErasePrimes(int n,int m[10][10])
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(m[i][j]==2)
                m[i][j]=0;
}
void StepFive(int &step,int n, int c[10][10],int Z0_r, int Z0_c, int m[10][10], int row[10], int col[10])
{
    int count=0;
    bool done=false;
    int r=-1,co;
    int path[2*10][10];
    path[count][1]=Z0_r;
    path[count][2]=Z0_c;
    while(!done)
    {
        FindStarInCol(path[count][2],r,n,m);
        if(r>=0)
        {
            count++;
            path[count][1]=r;
            path[count][2]=path[count-1][2];
        }
        else
            done=true;
        if(!done)
        {
            FindPrimeInRow(path[count][1],co,n,m);
            count++;
            path[count][1]=path[count-1][1];
            path[count][2]=co;
        }
    }
    CovertPath(path,count,m);
    ClearCovers(row,col,n);
    ErasePrimes(n,m);
    step=3;
    printf("\nstep 5");
}
void FindSmallests(int &minval, int n,int row[10], int col[10],int c[10][10])
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(row[i]==0 && col[j]==0)
                if(minval>c[i][j])
                    minval=c[i][j];
}
void StepSix(int &step, int c[10][10],int n,int row[10],int col[10])
{
    int minval=999999;
    int i,j;
    FindSmallests(minval,n,row,col,c);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(row[i]==1)
                c[i][j]=c[i][j]+minval;
            if(col[j]==0)
                c[i][j]=c[i][j]-minval;
        }
    step=4;
    printf("\nstep 6");
}
void Unger()
{
    int n=4;
    int c[10][10];
    int m[10][10];
    int row[10],col[10];
    int Z0_r,Z0_c;
    bool done=false;
    int stepnum=1;
        c[0][0]=80;
    c[0][1]=40;
    c[0][2]=50;
c[0][3]=46;
    c[1][0]=40;
    c[1][1]=70;
    c[1][2]=20;
c[1][3]=25;
    c[2][0]=30;
    c[2][1]=10;
    c[2][2]=20;
c[2][3]=30;
c[3][0]=35;
c[3][1]=20;
c[3][2]=25;
c[3][3]=30;
    for(int i=0;i<n;i++)
    {
        row[i]=0;
        col[i]=0;
    }
    while(!done)
    {
        switch(stepnum)
    {
        case 1 : {
            StepOne(stepnum,c,n);
            break;
                   }
        case 2 : {
            StepTwo(stepnum,col,row,n,m,c);
            break;
                   }
        case 3 : {
            StepThree(stepnum,n,col,m);
            break;
                   }
        case 4 : {
            StepFour(stepnum,n,m,row,col,Z0_r,Z0_c,c);
            break;
                   }
        case 5 : {
            StepFive(stepnum,n,c,Z0_r,Z0_c,m,row,col);
            break;
                   }
        case 6 : {
            StepSix(stepnum,c,n,row,col);
            break;
                   }
        case 7 : done=true;
            printf("\nstep 7");
            break;
    }
        printf("\n");
            for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%i ",c[i][j]);
        printf("\n");

    }
    }
}
