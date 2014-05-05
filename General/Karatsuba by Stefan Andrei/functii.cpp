#include "kara.h"


void getNum(char *Number1,int *length_Number1)
	{  char s[DIMMAX + 1];
	int i,j,t;
	cin >> s;

	*length_Number1 = strlen(s);

	for (i=*length_Number1-1; i>=0; i--)
	
			Number1[*length_Number1 - i - 1] = s[i] - '0';
		
    for (i=*length_Number1; i<DIMMAX; i++)
		Number1[i] = 0;
	cout<<"Nr este: ";

	for (i=*length_Number1-1; i>=0; i--)
		cout<<(int) Number1[i];
	cout<<endl;	
}


	/*FILE *f1;
	f1=fopen("input.txt","r");

	fgets(a,NMAX,f1);
	puts(a);
	fgets(b,NMAX,f1);
	puts(b);
	cout<<endl;

	lga=strlen(a);
	for (i=lga-1; i>=0; i--)
	a[lga - i - 1] = s[i] - '0';


	for (i=lga; i<DIMMAX; ++i)
	a[i] = 0;
	lgb=strlen(b);
	for (j=lgb-1; j>=0; j--)
	b[lgb - j - 1] = s[j] - '0';


	for (j=lgb; j<DIMMAX; ++j)
	b[j] = 0;*/

void Produs_Clasic(char *Number1,char *Number2,char *produs,int *length_Number1,int *length_Number2)
{   int i,j,t;
    int lgprodus;
	for (i=0; i<DIMMAX; i++)
		produs[i] = 0;


	for (i=0; i<*length_Number1; i++)
	{         

		t = 0;

		for (j=0; j<*length_Number2; j++)
		{
			produs[i+j] = produs[i+j] + Number1[i] * Number2[j] + t;
			t = produs[i+j] / 10;
			produs[i+j] = produs[i+j] % 10;
		}


		if (t)
			produs[i+j] = t;
	}


	lgprodus = *length_Number1 + *length_Number2 - 1;

	if (produs[lgprodus])
		lgprodus++;
	cout<<"produsul este: ";
	
	for (t=lgprodus-1; t>=0; t--)
		cout<<(int)produs[t];
	 
}


void karatsuba(char *Number1,char *Number2,int *length_Number1,int *length_Number2,char *produs)
{  
	char Number1_left[NMAX];
	char Number1_right[NMAX];
	char Number2_left[NMAX];
	char Number2_right[NMAX];
	char Number1_sum[NMAX];
	char Number2_sum[NMAX];
	int length_Number1_left=0;
	int length_Number2_left=0;
	int length_Number1_right=0;
	int length_Number2_right=0;
	int length_Number1_sum=0;
	int length_Number2_sum=0;
	int max,m,m1,i,j,t;
	
	if(*length_Number1>*length_Number2)
		{
			max=*length_Number1;
		}
	else
		{
			max=*length_Number2;
		}
	
	m=max;
	if(m%2==1)
		m=m+1;
	m1=m/2;
	int p=powi(10,m1);
	
	
	char x1[NMAX];//Aleft*Bleft
	char x2[NMAX];//Aright*Bright
	char x3[NMAX];
	int length_x1=0;
	int length_x2=0;
	int length_x3=0;
	
	
	//Calculam Number1_left
	length_Number1_left=0;
	for(i=m1;i<*length_Number1;i++)
	{	
		Number1_left[length_Number1_left]=Number1[i];
		length_Number1_left++;
	}

	cout<<"Nr1.left: ";
	for(t=length_Number1_left-1;t>=0;t--)
		cout<<(int)Number1_left[t];
	cout<<endl;
	//Calculam Number2_left
	length_Number2_left=0;
	for(j=m1;j<*length_Number2;j++)
	{
		Number2_left[length_Number2_left]=Number2[j];
		length_Number2_left++;
	}	

	cout<<"Nr2.left: ";
	for(t=length_Number2_left - 1;t>=0;t--)
		cout<<(int)Number2_left[t];
	cout<<endl;
	//Calculam x1
	Produs_Clasic(Number1_left,Number2_left,x1,&length_Number1_left,&length_Number2_left);
	cout<<endl;
	//Calculam Number1_right
	length_Number1_right=0;
	for(i=0;i<m1;i++)
			{
				Number1_right[length_Number1_right]=Number1[i];
				length_Number1_right++;
			}
	cout<<"Nr1_right: ";
	for(t=length_Number1_right-1;t>=0;t--)
				cout<<(int)Number1_right[t];
	cout<<endl;
	//Calculam Number2_right
	length_Number2_right=0;
	
	for(j=0;j<m1;j++)
			{
				Number2_right[length_Number2_right]=Number2[j];
				length_Number2_right++;
			}	
	cout<<"Nr2_right: ";
	for(t=length_Number2_right-1;t>=0;t--)
				cout<<(int)Number2_right[t];
	cout<<endl;
	//Calculam x2
	Produs_Clasic(Number1_right,Number2_right,x2,&length_Number1_right,&length_Number2_right);
		
	cout<<endl;

    sum(Number1_left,Number1_right,Number1_sum,&length_Number1_left,&length_Number1_right);
	length_Number1_sum=*length_Number1-1;//Number1_sum
    sum(Number2_left,Number2_right,Number2_sum,&length_Number2_left,&length_Number2_right);//Number2_sum
	length_Number2_sum=*length_Number2-1;
	//Calculam x3
	Produs_Clasic(Number1_sum,Number2_sum,x3,&length_Number1_sum,&length_Number2_sum);
}
 int powi(int number, int exponent)
{
	int i, product = 1;
	for (i = 0; i < exponent; i++)
		product = product * number;
	return product;
}


void sum(char *Number1_left,char *Number1_right,char *Number1_sum,int *length_Number1_left,int *length_Number1_right)
 {  
	int i,t=0;
   	int length_Number1_sum=0;
	for(i=0;i<DIMMAX;i++)
		Number1_sum[i]=0;
	for(i=0;i<*length_Number1_left;i++)
			{
										 Number1_sum[i]=Number1_sum[i]+Number1_left[i];
									     length_Number1_sum++;
			}
	for(i=0;i<*length_Number1_right;i++)
	{
		t=0;
										 Number1_sum[i]=Number1_sum[i]+Number1_right[i]+t;
										 t=Number1_sum[i]/10;
										 Number1_sum[i]=Number1_sum[i]%10;
										
		if(t)
		Number1_sum[length_Number1_sum++]=t;							
	}
	if(Number1_sum[length_Number1_sum])
		length_Number1_sum++;
	cout<<"sum : ";
	
	for(t=length_Number1_sum - 1 ; t>=0; t--)
		cout<<(int)Number1_sum[t];
	cout<<endl;
 }
