#include "kara.h"



int main(){

	char a[NMAX],b[NMAX],produs[2*DIMMAX];
	int lga,lgb,lgprodus;
	
	cout<<"The first nr is: ";
	getNum(a,&lga);
	cout<<endl;
	cout<<"The second nr is: ";
	getNum(b,&lgb);
	cout<<endl;
	
	Produs_Clasic(a,b,produs,&lga,&lgb);
	cout<<endl;
	cout<<"karatsuba: "<<endl;
	karatsuba(a,b,&lga,&lgb,produs);
	cout<<endl;
	//sum(a,b,&lg);
	system("PAUSE");
	

}
