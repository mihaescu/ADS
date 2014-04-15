#include "header.h"
#include <time.h>
#include <random>
#include <vector>
#include<fstream>
#include<string>

#define N 16000

int create(char* file)
{
	int x,y,l,h;
	FILE *fp;
	srand (time(NULL));
	std::vector<int> input;
	fp = fopen(file,"w");
	if( fp == NULL )
		return 0;

	int i=0,ok=0;
	while(i<N)
	{

		x = rand() % (N*100) + 1;
		y = rand() % (N*100) + 1;
		h = rand() % (N*100) + 1;
		l = rand() % (N*100) + 1;

		ok = 1;

		if(input.size() != 0)
		{
			for(int j=0;j<input.size();j++)
				if(x==input[j] || x+l == input[j])
					ok=0;
		}

		if(ok == 1)
		{
			input.push_back(x);
			input.push_back(x+l);

			fprintf(fp,"%d %d %d %d\n",x,y,l,h);
			i++;
		}


	}

	fclose(fp);
	return 1;
}

NodArb *add(MinHeap temp, NodArb *root)
{
	NodArb *nod1, *nod2, *nod3;

	nod1 = new NodArb;
	nod1->info.x = temp.x;
	nod1->info.y = temp.y;
	nod1->info.lenght = temp.lenght;
	nod1->info.height = temp.height;
	nod1->info.type = temp.type;

	nod1->left = NULL;
	nod1->right = NULL;

	if(root == NULL)
	{
		root = nod1;
	}
	else
	{
		nod2=root;

	while (nod2 != NULL)
		{
			if (temp.y < nod2->info.y)
			{
				nod3 = nod2;
				nod2 = nod2->left;
			}
			else
			{
				nod3 = nod2;
				nod2 = nod2->right;
			}
		}

		if (temp.y < nod3->info.y)
			nod3->left = nod1;
		else
			nod3->right = nod1;
	}

	return root;
}
NodArb *remove(MinHeap nr, NodArb **root)
{
	int temporar;
	NodArb *tmp,*tmp1,*tmp2,*rootTemp;

	rootTemp = *root;
	tmp1 = *root;
	tmp = NULL;

	while (!((tmp1->info.y == nr.y) && (tmp1->info.x == nr.x-nr.type) && (tmp1->info.lenght == nr.lenght) && (tmp1->info.height == nr.height)))
	{
		tmp = tmp1;
		if (tmp1->info.y > nr.y)
			tmp1 = tmp1->left;
		else
			tmp1 = tmp1->right;
	}

	if (tmp1->info.y != nr.y)
		{
			printf("The number inserted can't be fountd in the tree! Please try again.\n");
		}
	else
		{

		if( (tmp1->right==NULL) && (tmp1->left==NULL) )
		{
			if(tmp1==rootTemp)
			{
				delete tmp1;
				rootTemp = NULL;
			}
			else
			{
				if(tmp->right == tmp1)
				{
					tmp->right = NULL;
					delete tmp1;
				}
				else
				{

					tmp->left = NULL;
					delete tmp1;
				}
			}
		}
		else if (tmp1->right == NULL)
		{
			if(tmp!=NULL)
			{
				if(tmp->right == tmp1)
					tmp->right = tmp1->left;
				else if(tmp->left == tmp1)
					tmp->left = tmp1->left;
				delete tmp1;
			}
			else if (tmp1==*root)
			{
				tmp = tmp1->left;
				tmp1->info.x = tmp->info.x;
				tmp1->info.y = tmp->info.y;
				tmp1->info.lenght = tmp->info.lenght;
				tmp1->info.height = tmp->info.height;

				tmp1->left = tmp->left;
				tmp1->right = tmp->right;
				delete tmp;

			}
		}
		else if (tmp1->left == NULL)
		{
			if(tmp!=NULL)
			{
				if(tmp->left == tmp1)
				{
					tmp->left = tmp1->right;
					delete tmp1;
				}
				else if(tmp->right ==tmp1)
				{
					tmp->right = tmp1->right;
					delete tmp1;
				}
			}
			else if (tmp1==rootTemp)
			{
				tmp = tmp1->right;
				tmp1->info.x = tmp->info.x;
				tmp1->info.y = tmp->info.y;
				tmp1->info.height = tmp->info.height;
				tmp1->info.lenght = tmp->info.lenght;

				tmp1->left = tmp->left;
				tmp1->right = tmp->right;
				delete tmp;
			}


		}
		else
		{
				tmp = tmp1->right;
				if(tmp->left!=NULL)
				{
					tmp2 = tmp1;

					while (tmp->left != NULL)
					{
						tmp2 = tmp;
						tmp = tmp->left;
					}

					tmp1->info.x = tmp->info.x;
					tmp1->info.y = tmp->info.y;
					tmp1->info.lenght = tmp->info.lenght;
					tmp1->info.height = tmp->info.height;

					tmp2->left = tmp->right;
					delete tmp;
				}
				else
				{
					tmp1->info.x = tmp->info.x;
					tmp1->info.y = tmp->info.y;
					tmp1->info.lenght = tmp->info.lenght;
					tmp1->info.height = tmp->info.height;

					tmp1->right = tmp->right;
					delete tmp;
				}
		}
	}

	return rootTemp;
}
void compare(FILE *fp,MinHeap x,NodArb *tr)
{
	if(tr != NULL)
	{
		if(((tr->info.y >= x.y) && (tr->info.y - tr->info.height <= x.y)) || ((tr->info.y <= x.y) && (x.y - x.height <= tr->info.y)))
			if(!(tr->info.y == x.y && tr->info.x == x.x-x.type && tr->info.height == x.height && tr->info.lenght == x.lenght ))
			{
				fprintf(fp,"Rectangle (x:%d y:%d l:%d h:%d) /-\\ Rectangle (x:%d y:%d l:%d h:%d)\n",x.x-x.type,x.y,x.lenght,x.height,tr->info.x,tr->info.y,tr->info.lenght,tr->info.height);
			}

			if(tr->left != NULL || tr->right != NULL)
			{
				if(tr->left != NULL)
					compare(fp,x,tr->left);

				if(tr->right != NULL)
					compare(fp,x,tr->right);
			}
	}
}
int SweepLine(char* fileToRead, char* fileToWrite)
{
	clock_t start,stop;
	//start = clock();

	priority_queue< MinHeap, vector<MinHeap>, greater<MinHeap> > q;
	NodArb *root = NULL;

	FILE *fp;
	MinHeap temp;



	fp = fopen (fileToRead, "r");
	if( fp == NULL )
		return 0;


	while( ( fscanf(fp, "%d %d %d %d", &temp.x,&temp.y,&temp.lenght,&temp.height) ) != EOF )
	{
		temp.type=0;
		q.push(temp);

		temp.x = temp.x + temp.lenght;
		temp.type = temp.lenght;
		q.push(temp);

	}

	fclose(fp);

	fp = fopen (fileToWrite, "w+");

	start = clock();
	while(q.size() != 0)
	{
		temp = q.top();
		q.pop();

		if(temp.type == 0)
		{
			root = add(temp,root);
		}
		else
		{
			compare(fp,temp,root);
			root = remove(temp,&root);

		}
	}


	//system("pause");
	stop = clock();
	fprintf(fp,"\nTime: %f",((double)(stop - start))/CLOCKS_PER_SEC );
	printf("\nTime Sweep: %f",((double)(stop - start))/CLOCKS_PER_SEC );

	fclose(fp);
	return 1;
}
int BruteForce(char* fileToRead, char* fileToWrite)
{
	clock_t start,stop;
	start = clock();
	int n=0;
	struct data brute[N];
	FILE *fp1;

	fp1 = fopen (fileToRead,"r");
	if(fp1 ==NULL)
		return 0;

	while( ( fscanf(fp1,"%d %d %d %d",&brute[n].x,&brute[n].y,&brute[n].lenght,&brute[n].height)) != EOF)
		n++;

	fclose(fp1);

	fp1 = fopen (fileToWrite,"w+");
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
		{
			if(((brute[i].y >= brute[j].y) && (brute[i].y-brute[i].height <= brute[j].y)) || ((brute[i].y <= brute[j].y) && (brute[i].y >= brute[j].y-brute[j].height)))
				if(((brute[i].x >= brute[j].x) && (brute[i].x <= brute[j].x+brute[j].lenght)) || ((brute[i].x <= brute[j].x) && (brute[i].x + brute[i].lenght >= brute[j].x)))
					if(!((brute[i].y == brute[j].y) && (brute[i].x == brute[j].x) && (brute[i].lenght == brute[j].lenght) && (brute[i].height == brute[j].height)))
						fprintf(fp1,"Rectangle (x:%d y:%d l:%d h:%d) /-\\ Rectangle (x:%d y:%d l:%d h:%d)\n",brute[i].x,brute[i].y,brute[i].lenght,brute[i].height,brute[j].x,brute[j].y,brute[j].lenght,brute[j].height);
		}

		stop = clock();
		fprintf(fp1,"\nTime: %f",((double)(stop - start))/CLOCKS_PER_SEC);
		printf("\nTime Brute: %f",((double)(stop - start))/CLOCKS_PER_SEC);
		fclose(fp1);
		return 1;
}
