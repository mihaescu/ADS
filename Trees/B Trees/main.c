#include"btree.h"

void Generate(FILE *f1,int n, int a, int b)
{

	int i=0,number;
	int vect[MAX];
	if(b>=MAX || b<=a)
		exit(0);
	else
	{
		srand (time(NULL));
		for(i=0;i<=b;i++)
			vect[i]=0;
		i=0;
		do
		{
			number = rand() % b + 1;
			if(vect[number]==0)
			{
				fprintf(f1,"%d ",number);
				vect[number]=1;
				i++;
			}
		}while(i<n);
		fclose(f1);
	}
}

void LoadData(FILE *f1,int n,int vect[MAX])
{
		int x,i=0;
		n=0;
		while(!feof(f1))
		{
			fscanf(f1,"%d",&x);
			if(feof(f1)) break; //to avoid repeating last line
			vect[i]=x;
			n++;
			i++;
		}
		fclose(f1);
}

int main()
{
    system("color 4F");
	int n1, n2, n3, vect1[MAX], vect2[MAX], vect3[MAX];

    FILE *f1, *f2, *f3;

    f1=fopen("Input1.txt","wt");
	Generate(f1,10,1,100);
	printf("\nThe file <Input1.txt> was created. (10 numbers between (1,100))");
	fclose(f1);

	f2=fopen("Input2.txt","wt");
	Generate(f2,100,1,1000);
	printf("\nThe file <Input2.txt> was created. (100 numbers between (1,1000))");
	fclose(f2);

	f3=fopen("Input3.txt","wt");
	Generate(f3,1000,1,10000);
	printf("\nThe file <Input3.txt> was created. (1000 numbers between (1,10000))");
	fclose(f3);

	f1=fopen("Input1.txt","rt");
	LoadData(f1,n1,vect1);
	printf("\n\n\n\nThe dates from file <Input1.txt> was loaded into vect1.");

	f2=fopen("Input2.txt","rt");
	LoadData(f2,n2,vect2);
	printf("\nThe dates from file <Input2.txt> was loaded into vect2.");

	f3=fopen("Input3.txt","rt");
	LoadData(f3,n3,vect3);
	printf("\nThe dates from file <Input2.txt> was loaded into vect2.");
}
