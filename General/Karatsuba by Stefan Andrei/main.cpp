#include "kara.h"



int main(){

	char a[NMAX],b[NMAX],result[NMAX];
	int lga,lgb,lgresult;
	

	cout<<"The first nr is: ";
	getOperand(a,&lga);
	printf("\n");
	cout<<"The second nr is: ";
	getOperand(b,&lgb);
	printf("\n");
        //trebuie citire din fisier
        //trebuie afiasare in fisier
	/*FILE *fp = fopen("input.txt", "r");
	loadNumbers(fp,a,b);*/

	classicProduct(a,b,result,&lga,&lgb);
	printf("\n");
	printf("karatsuba: ");
	printf("\n");
	karatsuba(a,b,&lga,&lgb,result);
	printf("\n");
	system("PAUSE");


}
