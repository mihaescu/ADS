#include "kara.h"


void getOperand(char *N1,int *lengthN1)
{  
	
	char s[DIMMAX + 1];
	int i,j,t;
	cin >> s;

	*lengthN1 = strlen(s);

	for (i=*lengthN1-1; i>=0; i--)

			N1[*lengthN1 - i - 1] = s[i] - '0';

    for (i=*lengthN1; i<DIMMAX; i++)
		N1[i] = 0;

	for (i=*lengthN1-1; i>=0; i--)
	printf("%d",N1[i]);
	
}
void classicProduct(char *N1,char *N2,char *result,int *lengthN1,int *lengthN2)
{   int i,j,t;
    int lgresult;
	for (i=0; i*2<DIMMAX; i++)
		result[i] = 0;


	for (i=0; i<*lengthN1; i++)
	{         

		t = 0;

		for (j=0; j<*lengthN2; j++)
		{
			result[i+j] = result[i+j] + N1[i] * N2[j] + t;
			t = result[i+j] / 10;
			result[i+j] = result[i+j] % 10;
		}


		if (t)
			result[i+j] = t;
	}


	lgresult = *lengthN1 + *lengthN2 - 1;

	if (result[lgresult])
		lgresult++;
	printf("Result is: ");

	for (t=lgresult-1; t>=0; t--)
		printf("%d",result[t]);
	printf("\n");

}


void karatsuba(char *N1,char *N2,int *lengthN1,int *lengthN2,char *result)
{	
	
	char leftN1[NMAX];
	char rightN1[NMAX];
	char leftN2[NMAX];
	char rightN2[NMAX];
	char sumN1[NMAX];
	char sumN2[NMAX];
	int lengthLeftN1=0;
	int lengthLeftN2=0;
	int lengthRightN1=0;
	int lengthRightN2=0;
	int lengthSumN1=0;
	int lengthSumN2=0;
	
	int max,m,m1,i,j,t;



	char x1[NMAX];//Aleft*Bleft
	char x2[NMAX];//Aright*Bright
	char x3[NMAX];
	char U[NMAX];
	char V[NMAX];
	char W[NMAX];
	int length_x1=0;
	int length_x2=0;
	int length_x3=0;
	int length_U;
	int length_V;
	int length_W;
	char K[NMAX];
	int length_K=0;
	char A[NMAX];
	int length_A;
	char B[NMAX];
	int length_B;
	char C[NMAX];
	int length_C;
	char M[NMAX];
	int length_M=0;

	if( *lengthN1 > *lengthN2 )
		{
			max = *lengthN1;
		}
	else
		{
			max = *lengthN2;
		}
	if( *lengthN1 == *lengthN2 )
	   	max = *lengthN1;
	m = max;
	if( m%2 == 1)
		m = m + 1;
	m1 = m / 2;
	int p = powi(10,m1);
	char arr[NMAX];
    int lengthArr = (int)floor(log10((float)p)) + 1; 
    i = 0;
    do {
    	arr[i] = p % 10;
    	p /= 10;
    	i++;
    } while (p != 0);

	
 
	//Calculam leftN1
	lengthLeftN1 = 0;
	for(i = m1 ; i < *lengthN1 ; i++)
	{	
		leftN1[lengthLeftN1] = N1[i];
		lengthLeftN1++;
	}

	printf("Nr1.left: ");
	for( t = lengthLeftN1 - 1 ; t >= 0 ; t--)
	printf("%d",leftN1[t]);
	printf("\n");
	//Calculam leftN2
	lengthLeftN2 = 0;
	for( j = m1 ; j < *lengthN2 ; j++)
	{
		leftN2[lengthLeftN2] = N2[j];
		lengthLeftN2++;
	}	
	printf("Nr2.left: ");
	for(t = lengthLeftN2 - 1 ; t >= 0 ; t--)
	printf("%d",leftN2[t]);
	printf("\n");

	lengthRightN1 = 0;
	for( i = 0 ; i < m1 ; i++)
			{
				rightN1[lengthRightN1] = N1[i];
				lengthRightN1++;
			}
	printf("Nr1_right: ");
	for( t = lengthRightN1 - 1 ; t >= 0 ; t--)
	printf("%d",rightN1[t]);
	printf("\n");
	//Calculam rightN2
	lengthRightN2 = 0;

	for( j = 0 ; j < m1 ; j++)
			{
				rightN2[lengthRightN2] = N2[j];
				lengthRightN2++;
			}	
	printf("Nr2_right: ");
	for( t = lengthRightN2 - 1 ; t >= 0 ; t--)
	printf("%d",rightN2[t]);
	printf("\n");

	split_Numbers(N1,N2,lengthN1,lengthN2);
	
 	classicProduct(leftN1,leftN2,x1,&lengthLeftN1,&lengthLeftN2);   //x1 = leftN1 * leftN2

	length_x1 = lengthLeftN1 + lengthLeftN2 - 1;
	
	classicProduct(rightN1,rightN2,x2,&lengthRightN1,&lengthRightN2);	//x2 = rightN1 * rightN2
	
	length_x2 = lengthRightN1 + lengthRightN2 -1;

	printf("\n\n\n");

    sum(leftN1,rightN1,sumN1,&lengthLeftN1,&lengthRightN1);//sumN1
	
	if( lengthLeftN1 > lengthRightN1)
			lengthSumN1 = lengthLeftN1;
	else
			lengthSumN1 = lengthRightN1;

	if (lengthLeftN1 == lengthRightN1)
		    lengthSumN1 = lengthLeftN1 + 1;

    sum(leftN2,rightN2,sumN2,&lengthLeftN2,&lengthRightN2);//sumN2
	
	if( lengthLeftN2 > lengthRightN2)
			lengthSumN2 = lengthLeftN2;
	else
			lengthSumN2 = lengthRightN2;
	
	if(lengthLeftN2 == lengthRightN2)
		lengthSumN2 = lengthLeftN2 ;
	//Calculam U
	classicProduct(sumN1,sumN2,U,&lengthSumN1,&lengthSumN2);  //U=sumN1 * sumN2
	printf("\n");
	length_U = lengthSumN1 + lengthSumN2 - 1;
	dif(U,W,x2,&length_U);    //W = U - x2
	length_W = length_U;
	dif(W,x3,x1,&length_W);   //x3 = W - x1
	length_x3 = length_W;
	
	classicProduct(x1,arr,V,&length_x1,&lengthArr);   // V = x1 * 1000;72 * 1000 = 72000
	length_V = length_x1 + lengthArr - 1;

	classicProduct(V,arr,M,&length_V,&lengthArr);     // M = V * 1000 = 72000 * 1000 = 72000000
    length_M = length_V + lengthArr -1;
	
	classicProduct(x3,arr,K,&length_U,&lengthArr);   // K = x3 * 1000 = 11538 * 1000 = 11538000
	length_K = length_x3 + lengthArr -1;
	
	sum(M,K,A,&length_M,&length_K);      // A = M + K = 72000000 + 11538000 = 83538000
	if( length_M > length_K )	
			length_A = length_M ;
	else
			length_A = length_K ;

	if( length_M == length_K)
		    length_A = length_M ;

	sum(A,x2,B,&length_A,&length_x2);   // B = A + x2 = 83538000 + 272205 = 83810205
	

}
 int powi(int number, int exponent)
{
	int i;
	int product = 1;
	for ( i = 0 ; i < exponent ; i++ )
	 
		product = product * number;
	return product;
}


void sum(char *leftN1,char *rightN1,char *sumN1,int *lengthLeftN1,int *lengthRightN1)
 {  
	int i,t = 0;
   	int lengthSumN1 = 0;
	for( i = 0 ; i < DIMMAX ; i++)
		sumN1[i] = 0;
	
	for( i = 0 ; i < *lengthLeftN1 ; i++ )
			{
										 sumN1[i] = sumN1[i] + leftN1[i];
									     lengthSumN1++;
			}
	for( i = 0 ; i < *lengthRightN1 ; i++ )
	{
		t = 0;
										 sumN1[i] = sumN1[i] + rightN1[i] + t;
										 t = sumN1[i] / 10;
										 sumN1[i] = sumN1[i] % 10;

		if( t )
		sumN1[lengthSumN1++] = t;							
	}
	if( sumN1[lengthSumN1] )
		lengthSumN1++;
	printf("sum : ");
	
	for( t = lengthSumN1 - 1 ; t >= 0 ; t-- )
		printf("%d",sumN1[t]);
	printf("\n");
 }

void dif(char *U,char *x3,char *x2,int *length_U)
{   
	int i;
	int t = 0;

	for( i = 0 ; i < DIMMAX ; i++ )
	x3[i] = 0;
	int length_x3 = *length_U;
	for( i=0 ; i < *length_U ; i++)
	{
		x3[i] = U[i] - x2[i]  + t;
		if( x3[i] < 0 )
		{
			x3[i] = x3[i] + 10;
			t = -1;
		}
		else
			t = 0;
	}
	i = length_x3 - 1;
	while( x3[i] == 0 )
		i--;
	length_x3 = i + 1;	
	printf("Diferenta este : ");
	for( t = length_x3 - 1 ; t >= 0 ; t--)
		printf("%d",x3[t]);
	printf("\n");
}
/*
void split_Numbers(char *N1,char *N2,int *lengthN1,int *lengthN2)
{
	
	
	int i,j,t;
	char leftN1[NMAX];
	char leftN2[NMAX];
	char rightN1[NMAX];
	char rightN2[NMAX];
	int lengthLeftN1;
	int lengthRightN1;
	int lengthLeftN2;
	int lengthRightN2;
	int max,m,m1;
	if(*lengthN1>*lengthN2)
		{
			max=*lengthN1;
		}
	else
		{
			max=*lengthN2;
		}
	if(*lengthN1==*lengthN2)
		max=*lengthN1;
	m=max;
	if(m%2==1)
		m=m+1;
	m1=m/2;
	

	//Calculam leftN1
	lengthLeftN1=0;
	for(i=m1;i<*lengthN1;i++)
	{	
		leftN1[lengthLeftN1]=N1[i];
		lengthLeftN1++;
	}

	
	cout<<"Nr1.left: ";	  
	for(t=lengthLeftN1-1;t>=0;t--)
		printf("%d",leftN1[t]);
 	printf("\n");
	//Calculam leftN2
	lengthLeftN2=0;
	for(j=m1;j<*lengthN2;j++)
	{
		leftN2[lengthLeftN2]=N2[j];
		lengthLeftN2++;
	}	
	cout<<"Nr2.left: ";
	for(t=lengthLeftN2-1;t>=0;t--)
		printf("%d",leftN2[t]);
 	printf("\n");
	lengthRightN1=0;
	for(i=0;i<m1;i++)
			{
				rightN1[lengthRightN1]=N1[i];
				lengthRightN1++;
			}
	cout<<"Nr1_right: ";
	for(t=lengthRightN1-1;t>=0;t--)
		printf("%d",rightN1[t]);
 	printf("\n");	
	//Calculam rightN2
	lengthRightN2=0;

	for(j=0;j<m1;j++)
			{
				rightN2[lengthRightN2]=N2[j];
				lengthRightN2++;
			}	
	cout<<"Nr2_right: ";
	for(t=lengthRightN2-1;t>=0;t--)
		printf("%d",rightN2[t]);
 	printf("\n");
	
	
}
*/
